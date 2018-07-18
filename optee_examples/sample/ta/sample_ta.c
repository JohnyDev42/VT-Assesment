

#include<tee_internal_api.h>
#include<tee_internal_api_extensions.h>

#include<sample_ta.h>

//static TEE_Result printtest(uint32_t , TEE_Param);
static TEE_Result printtest(void);

TEE_Result TA_CreateEntryPoint(void)
{
	DMSG("AKSHAY : CREATED ENTRY ");
	return TEE_SUCCESS;
}

void TA_DestroyEntryPoint(void)
{
	DMSG("Destroy has been called ");
}


TEE_Result TA_OpenSessionEntryPoint(uint32_t param_types , 
		TEE_Param __maybe_unused params[4],
		void __maybe_unused **sess_ctx)

{
	uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE);

	DMSG("OPEN SESSION ENTRY POINT");
	
	if(param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;
	
	
	(void)&params;
	(void)&sess_ctx;

	IMSG("LEAVING OPEN SESSION EP");

	return TEE_SUCCESS;
}


void TA_CloseSessionEntryPoint(void __maybe_unused *sess_ctx)
{
	(void)&sess_ctx;
	DMSG("GOODBYE");
}


static TEE_Result printtest(void)
{

	DMSG("InSIDE PRINTTEST");
	DMSG("LEAVING PRINTTEST");

//	if( param_types != exp_param_types)
//		return TEE_ERROR_BAD_PARAMETERS;

	DMSG("IT IS WORKING");
	
//	(void)&params;

	return TEE_SUCCESS;
}

TEE_Result TA_InvokeCommandEntryPoint(void __maybe_unused *sess_ctx, 
				uint32_t cmd_id,
				uint32_t param_types , TEE_Param params[4])
{
	
	DMSG("INSIDE INVOKE ");

	(void)&sess_ctx;

	switch(cmd_id)
	{
		case TA_SAMPLE_CMD_INC_VALUE:
			DMSG("INSIDE SWITCH CASE");	
			return printtest();
			
		default:
			return TEE_ERROR_BAD_PARAMETERS;
	}

	(void)&param_types;
	(void)&params ;

	return TEE_SUCCESS ;
}


