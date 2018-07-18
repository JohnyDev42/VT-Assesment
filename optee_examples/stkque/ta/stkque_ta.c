/*
 * Copyright (c) 2016, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>

#include <stkque_ta.h>
#include <templete.h>
/*
 * Called when the instance of the TA is created. This is the first call in
 * the TA.
 */
struct stack * st1;
struct stack * st2;
int y;
struct stack * createStack(unsigned cap)
{
	struct stack * new=(struct stack*)TEE_Malloc(sizeof(struct stack),0);
	new->top=-1;
	new->capacity=cap;
	new->arr=(int *)TEE_Malloc((new->capacity)*sizeof(int),0);
	return new;
}
int isEmptyS(struct stack *stack)
{
	return stack->top==-1;
}
int isFullS(struct stack *stack1)
{
	return stack1->capacity-1==stack1->top;
}
void pushS(struct stack * stack1,int data)
{
	if(isFullS(stack1))
	{
		printf("Stack is Full\n");
		return;
	}
	stack1->arr[++stack1->top]=data;	
}
int peekS(struct stack * st)
{
	return st->arr[st->top];
}
int popS(struct stack * st)
{
	if(isEmptyS(st))
		return -1;
	return st->arr[st->top--];
}
TEE_Result TA_CreateEntryPoint(void)
{
	DMSG("ARUN:has been called");

	return TEE_SUCCESS;
}

/*
 * Called when the instance of the TA is destroyed if the TA has not
 * crashed or panicked. This is the last call in the TA.
 */
void TA_DestroyEntryPoint(void)
{
	DMSG("ARUN:has been called");
}

/*
 * Called when a new session is opened to the TA. *sess_ctx can be updated
 * with a value to be able to identify this session in subsequent calls to the
 * TA. In this function you will normally do the global initialization for the
 * TA.
 */
TEE_Result TA_OpenSessionEntryPoint(uint32_t param_types,
		TEE_Param __maybe_unused params[4],
		void __maybe_unused **sess_ctx)
{
	uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE);

	DMSG("ARUN:has been called");

	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	/* Unused parameters */
	(void)&params;
	(void)&sess_ctx;

	/*
	 * The DMSG() macro is non-standard, TEE Internal API doesn't
	 * specify any means to logging from a TA.
	 */
	IMSG("STKQUE Session !\n");

	/* If return value != TEE_SUCCESS the session will not be created. */
	return TEE_SUCCESS;
}

/*
 * Called when a session is closed, sess_ctx hold the value that was
 * assigned by TA_OpenSessionEntryPoint().
 */
void TA_CloseSessionEntryPoint(void __maybe_unused *sess_ctx)
{
	(void)&sess_ctx; /* Unused parameter */
	IMSG("STKQUE Session Closed !\n");
}

static TEE_Result create_st(uint32_t param_types,
	TEE_Param params[4])
{
	uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_INOUT,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE);

	

	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;
	DMSG("CREATE:has been called");

	st1 = createStack(params[0].value.a);
	st2 = createStack(params[0].value.a);
	
	

	return TEE_SUCCESS;
}
static TEE_Result push(uint32_t param_types,
	TEE_Param params[4])
{
	uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_INOUT,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE);

	
	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	if(isFullS(st1)==1)
		IMSG("Stack is Full\n");
	pushS(st1,params[0].value.b);
	DMSG("PUSH:has been called");


	return TEE_SUCCESS;
}
static TEE_Result pop(uint32_t param_types,
	TEE_Param params[4])
{
	uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_INOUT,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE);

	
	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	if((isEmptyS(st2)==1)&&(isEmptyS(st1)==1)){
		IMSG("Stack is Empty\n");
		return TEE_SUCCESS;
	}
	if(isEmptyS(st2)==1){
			while(isEmptyS(st1)!=1)
			{
			y=peekS(st1);
			pushS(st2,y);
			popS(st1);
			}
			}
			IMSG("Data:%d\n",peekS(st2));
			popS(st2);
	
	DMSG("POP:has been called");
	

	return TEE_SUCCESS;
}

/*
 * Called when a TA is invoked. sess_ctx hold that value that was
 * assigned by TA_OpenSessionEntryPoint(). The rest of the paramters
 * comes from normal world.
 */
TEE_Result TA_InvokeCommandEntryPoint(void __maybe_unused *sess_ctx,
			uint32_t cmd_id,
			uint32_t param_types, TEE_Param params[4])
{
	(void)&sess_ctx; /* Unused parameter */

	switch (cmd_id) {
	case TA_CREATEST_CMD_VALUE:
		return create_st(param_types, params);

	case TA_PUSH_CMD_VALUE:
		return push(param_types, params);
	case TA_POP_CMD_VALUE:
		return pop(param_types, params);

	default:
		return TEE_ERROR_BAD_PARAMETERS;
	}
	
}
