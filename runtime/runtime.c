#include <stdio.h>
#include <assert.h>

#include <output.h>				/* gwbo_* */

#include "inc/parser.h"
#include "inc/runtime.h"
#include "inc/env.h"

#include "handlers/interp/inc/interp.h"		/* gwbh_Interpreter() */
#include "handlers/interp/stmts/inc/stmts.h" 	/* To gwbr_RunProgram for statements handling */
/*
	Terminate GWBasic Shell
*/
void gwbr_TerminateShell(GWBE_Environment* env)
{
	exit(0);
}

/*
	Lexical And Syntax Parser
*/
GWBN_Interpreter* gwbr_Parse(char* sourceCode)
{
	return (GWBN_Interpreter*) gwbp_Parse(sourceCode);		
}

/*
	Main Function that runs interpreter
*/
void gwbr_Run(GWBE_Environment *env)
{
	assert(env != NULL);
	assert(env->input != NULL);

	/* Parse user request */
	assert(env->input->buffer != NULL);
	
	/*
		Нужно проверить тип запроса. 
		Пока проверка не осуществляется,
		и запрос всегда разбирается как
		пользовательский запрос к IDE.
	*/
	switch (env->runtime_mode)
	{
		case GWBE_RUNTIMEMODE_INTERPRETER:
		{
			/* Обрабатываем запрос пользователя */
			GWBN_Interpreter* interpreter = gwbr_Parse(env->input->buffer);
			
			/* Handle the received "GWBN_Interpreter*" */
			if (interpreter != NULL)
			{
				gwbh_Interpreter(env, interpreter);
			}

			/* Очищаем содержимое буфера */
			gwbe_ClearRequest(env);

			/* Переводим среду в режим "ожидания запроса пользователя" 
			   в случае, если оно не было изменено */
			if (env->runtime_mode == GWBE_RUNTIMEMODE_INTERPRETER)
				env->runtime_mode = GWBE_RUNTIMEMODE_INTERPRETERWAIT;
			
			break;
		}
		case GWBE_RUNTIMEMODE_PROGRAM:
		{
			/* Продолжаем выполнение программы */
			gwbr_ContinueProgram(env);
			break;
		}
		case GWBE_RUNTIMEMODE_INTERPRETERWAIT:
		{
			/* Idle, nothing to do */
			break;
		}
		case GWBE_RUNTIMEMODE_PROGRAMWAIT:
		{
			/* Idle, nothing to do */
			break;
		}
		default:
		{
			assert(0 && "Unimplemented Runtime Mode");
			break;
		}
	}
}
/*
	Finish GWBasic Program
*/
void gwbr_FinishProgram(GWBE_Environment* env, GWBR_Result result)
{
	assert(env != NULL);
	assert(env->ctx != NULL);
	
	gwbo_DisplayDebugMessage(env, "In \"FinishProgram\" Handler"); 	

	/* Сброс индекса строки программы */
	env->ctx->current_line = 0;

	/* Вывод результата выполнения программы */
	gwbo_DisplayResult(env, result);
	gwbo_NextLine(env);

	/* Переключаем режим среды на "ожидаение ввода пользовательского запроса" */
	env->runtime_mode = GWBE_RUNTIMEMODE_INTERPRETERWAIT;
	gwbe_ClearRequest(env);
}

/*
	Continue GWBasic Program
*/
GWBR_Result gwbr_ContinueProgram(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->ctx != NULL);

	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	int current_line = env->ctx->current_line;
	if (current_line < GWBE_PROGRAM_MAXLINES && result.type == GWBR_RESULT_OK)
	{
		assert(env->program != NULL);
		assert(env->program->lines != NULL);
		
		if (env->program->lines[current_line] != NULL)
		{	
			/* строка присутствует, поэтому ее нужно обработать */
			result = gwbh_Statements(env, env->program->lines[current_line]->stmts);
		}
		
		if (result.type == GWBR_RESULT_OK)	/* Критично для оператора Input, чтобы он выполнился повторно */
		{
			/* Переход на следующую строку */	
			env->ctx->current_line++;
			current_line = env->ctx->current_line;
		}
	}	

	/* Если ожидается ввод с клавиатуры */ 
	if (result.type == GWBR_NOTIFICATION_WAITFORVALUE)
	{
		/* Изменяем состояние среды исполнения на "ожидание ввода данных" */
		env->runtime_mode = GWBE_RUNTIMEMODE_PROGRAMWAIT;
		gwbe_ClearRequest(env);
	}
	/* Если не ожидается ввод с клавиатуры */
	if (current_line >= GWBE_PROGRAM_MAXLINES || 
		result.type == GWBR_NOTIFICATION_FINISHPROGRAM)
	{
		gwbr_FinishProgram(env, result);
	}

	return result;
}

/*
	Start GWBasic Program
*/
void gwbr_StartProgram(GWBE_Environment* env)
{		
	assert(env != NULL);
	assert(env->ctx != NULL);

	gwbo_DisplayDebugMessage(env, "In \"StartProgram\" Handler"); 	
	
	/* переключаем режим среды на выполнениеп программы */
	env->runtime_mode = GWBE_RUNTIMEMODE_PROGRAM;

}

/*
	Run GWBasic Program
*/
GWBR_Result gwbr_RunProgram(GWBE_Environment* env)
{
	assert(env != NULL);
	
	gwbo_DisplayDebugMessage(env, "In \"RunProgram\" Handler"); 	
		
	/* Начинаем выполнение программы */
	gwbr_StartProgram(env);

	/* Продолжаем выполенение программы */
	return gwbr_ContinueProgram(env);	 
}
