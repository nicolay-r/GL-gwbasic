/* GW-Basic Events */

#include "inc/env.h"
#include <assert.h>

#include <stdio.h>
/*
	Function Implementations
*/
void gwbr_Event_OnKeyPressed(GWBE_Environment* env, int key)
{
	switch (key)
	{
		case 8: /* Backspace */
		{
			gwbe_PopCharFromRequest(env);
			break;
		}
		case 13: /* Enter */	
		{
			/* Append Enter */
			gwbe_PushCharToRequest(env, '\n');
			
			/* Change the state of environment */
			switch (env->runtime_mode)
			{
				case GWBE_RUNTIMEMODE_INTERPRETERWAIT:
				{	
					env->runtime_mode = GWBE_RUNTIMEMODE_INTERPRETER;
					break;
				}
				case GWBE_RUNTIMEMODE_PROGRAMWAIT:
				{	
					env->runtime_mode = GWBE_RUNTIMEMODE_PROGRAM;
					break;
				}
				default:
				{
					printf("%d\n", env->runtime_mode); 
					assert(0 && "Unimplemented runtime mode");
					break;
				}
			}

			break;
		}
		default:
		{
			gwbe_PushCharToRequest(env, key);
			break;
		}
	}
}
