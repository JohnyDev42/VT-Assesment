

#include<err.h>
#include<stdio.h>
#include<string.h>

#include<tee_client_api.h>

#include<example.h>

int main(int argc , char *argv[])
{
	TEEC_Result res ;
	TEEC_Context ctx;
	TEEC_Session sess;
	TEEC_Operation op;
	
	TEEC_UUID uuid = TA_TEST_UUID ;
	uint32_t err_origin;
	
	//Initializing Context

	res = TEEC_InitializeContext(NULL,&ctx);
	if(res != TEEC_SUCCESS)
		errx(1 , "TEEC_Initialize Failed with code 0x%x" , res);
	
	//Opening session

	res = TEEC_OpenSession(&ctx , &sess , &uuid , TEEC_LOGIN_PUBLIC , NULL , NULL, &err_origin);

	if(res != TEEC_SUCCESS)
		errx(1 , "TEEC_OpenSession Failed with code 0x%x origin 0x%x ", res , err_origin);

	//Clearing the Operation Struct 
	memset(&op , 0 , sizeof(op));

	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INOUT, TEEC_NONE , TEEC_NONE , TEEC_NONE );
	
	op.params[0].value.a = 5;

	//Invoke function 
	res = TEEC_InvokeCommand(&sess , TA_TEST_CMD_ID , &op , &err_origin);

	if(res != TEEC_SUCCESS)
		errx(1 , "TEEC_Invokation failed with code 0x%x origin 0x%x" , res , err_origin);	
		
	TEEC_CloseSession(&sess);

	TEEC_FinalizeContext(&ctx);
	

	return 0;
}

