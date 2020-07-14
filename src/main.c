#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>

#define MAX 32
#define MAX_PROCS 4

unsigned int vetor[MAX], size_vet = 0;

//input de valores para o vetor
void input_vetor(){
   int i;
   char unit = '\0';

	for ( i = 0 ; i < MAX ; i++){
      unit = scanf("%u", &vetor[i]);

      if( unit == EOF ){
			     size_vet = i;
           break;
		  }
   }
}

//verifica se é primo
unsigned int verifica_primo(int number){
   int cont_div = 0, n_primos = 0;

   for(int j = 1; j <= number ; j++){
     //se é um divisor e o numero é diferente de 1, conta +1 divisor
     if ((number % j == 0) && (j != 1)) cont_div++;

     //se encontrar um segundo divisor pode quebrar o laço
     if (cont_div > 1) break;
   }

  //se só houver 1 divisor, o número é primo
  if (cont_div == 1) n_primos++;

  return n_primos;
}

int main(){
   pid_t PID[MAX_PROCS];

   //definição de flags de proteção e visibilidade da memória
   int protection = PROT_READ | PROT_WRITE;
   int visibility = MAP_SHARED| MAP_ANON;
   //area de memória compartilhada
   int *shrd_memory, primos;
   shrd_memory = (int *) mmap(NULL, sizeof(int)*MAX, protection, visibility, 0, 0);
   (*shrd_memory) = 0;

   //lê valores do usuario
   input_vetor();

   for (int i = 0; i < MAX_PROCS ; i++){
      PID[i] = fork();
      //se for um processo filho
      if (PID[i] == 0){
          primos = verifica_primo(vetor[i]);
          *shrd_memory += primos;
          exit(0);
      }
      printf("Process filho %d com num_primos = %d\n", PID[i], *shrd_memory);
   }

   for (int k = 0 ; k < MAX_PROCS; k++) waitpid(PID[k], NULL, 0);

   printf("num_primos = %d\n", *shrd_memory);

   //printf("%ls\n", shrd_memory);

   return 0;
}
