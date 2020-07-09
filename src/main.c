#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define NUM_THREADS 4

int n_primos;

int main(){
   char aux;
   int i;
   unsigned int *vetor = (int*)malloc(MAX * sizeof(int));

   for ( i = 0 ; i < MAX ; i++) vetor[i] = '\0';

	for ( i = 0 ; (aux != '\n') && (aux != EOF) ; i++){
		aux = scanf("%u", &vetor[i]);

		printf("\ni=%d vetor[i]=%d", i, vetor[i]);
		if( aux == '\n' ) printf("sou um barra N\n");

		if( aux == EOF ) printf("sou um EOF\n");	
	}

	for (i = 0 ; i < MAX ; i++) printf("%d", vetor[i]);

   return 0;
}
