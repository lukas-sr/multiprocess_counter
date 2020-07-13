#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 32
#define MAX_THREADS 4

int i = 0, n_primos = 0, threads = 0, size_vet = 0;
unsigned int vetor[MAX];

//input de valores para o vetor
void catch_values(){
   char unit = '\0';
   
   //for ( i = 0 ; i < MAX ; i++) vetor[i] = '\0';
    
	for ( i = 0 ; i < MAX ; i++){
      unit = scanf("%u", &vetor[i]); 
      
      if( unit == EOF ){
			size_vet = i; //SÓ PARA DEBUG <===
         break;
		}
   }
}

void analyze(int number){
   pid_t pid_local;
   int j, cont_div;
   
   pid_local = fork();
   
   if (pid_local == 0){
      
      for( j = 0 ; j < number ; j++){
         if (number % j == 0) cont_div++;

         if (cont_div++ >= 2) break;
      }
      
      if (cont_div == 1) n_primos++;

      exit(0);
   }
   

}

int main(){
   system("clear");
   catch_values();

   //SÓ PARA DEBUG <==
   for (i = 0 ; i < size_vet ; i++) printf("%d ", vetor[i]);

   for (i = 0 ; i < size_vet ; i++){
      if(threads <= MAX_THREADS) analyze(vetor[i]);
      
   }

	return 0;
}
