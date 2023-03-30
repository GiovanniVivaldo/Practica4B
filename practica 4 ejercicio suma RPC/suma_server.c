#include "suma.h"

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)
{
	static int  result;
	//ESTADO DE SERVIDOR
	printf("server is working \n");
	//PARAMETROS A PROCESAR
	printf("parameters: %d, %d \n", argp->a, argp->b);
	//PROCESAMOS SUMA
	result = argp->a + argp->b;
	//ENVIAMOS RESULTADOS
	printf("returning: %d \n", result);
	return &result;
}
