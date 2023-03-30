
#include "suma.h"
#include <stdio.h>

//RECIBE HOST Y DATOS
void suma_prog_1(char *host, int a, int b)
{
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif

//ASIGNAMOS VALORES RECIBIDOS A ARGUMENTOS DEL PROGRAMA
suma_1_arg.a = a;
suma_1_arg.b = b;
result_1 = suma_1(&suma_1_arg, clnt);

	result_1 = suma_1(&suma_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
else {
printf("Result = %d\n", *result_1); }
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main(int argc, char *argv[]) {
char *host;
int a, b;
if (argc != 4) {
//DAMOS INSTRUCCIONES A USUARIO
printf ("usage: %s server_host num1 num2\n", argv[0]);
exit(1);
}
//VALIDAMOS NUMEROS RECIBIDOS POR USUARIO
host = argv[1];
if ((a = atoi(argv[2])) == 0 && *argv[2] != '0') {
fprintf(stderr, "invalid value: %s\n", argv[2]);
exit(1);
}
if ((b = atoi(argv[3])) == 0 && *argv[3] != '0') {
fprintf(stderr, "invalid value: %s\n", argv[3]);
exit(1);
}
suma_prog_1(host, a, b);
exit(0);
}
