/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 *
 */

#include <stdio.h>
#define MAX 20

int main() {

  int i, vet[MAX], var;

  for (i=0; i < MAX ; i++) vet[i] = '\0'; //Inicializando vetor com valores nulos

  while (vet[i] != '\n'){
	
	scanf("%d", &var);
	vet[i] = var;
	if (var == '\n') break;

	i++;
  }

  for (i=0; i < MAX ; i++){
	printf("%d ", vet[i]);
  }

  return 0;
}
