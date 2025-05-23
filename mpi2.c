#include <stdio.h>
#include <string.h>  
#include <mpi.h>     
#include <math.h>
const int MAX_STRING = 100;


int pow_int(int value, int expoente){
   int result =1;
   for(int i =0; i<expoente;i++){
      result *= value;
   }
   return result;
}


int main(void) {
   char       message[MAX_STRING];  
   int        comm_size;               
   int        my_rank;               
   int        message2 = 0;
   int        sum = 0;
   MPI_Init(NULL, NULL); 
   MPI_Comm_size(MPI_COMM_WORLD, &comm_size); 
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 


   
   if (my_rank != 0) { 
   switch(my_rank){
      case 1:
         message2 = my_rank + my_rank;
         break;
      case 2:
         message2 = my_rank * my_rank;
         break;
      case 3:
         message2 = pow_int(my_rank, 3);
         break;
      default:
         message2 = my_rank;
         break;
   }
      
      /* Envio da mensagem para o processo 0 */
      MPI_Send(&message2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
   } else {  
      /* Impressão da mensagem do processo centralizador */
      printf("Processo centralizador em execução: %d of %d!\n", my_rank, comm_size);
      
      for (int q = 1; q < comm_size; q++) {
         /* Recepção da mensagem do processo q */
         MPI_Recv(&message2, 1, MPI_INT, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
         sum += message2;
         /* Impressão da mensagem do processo q */
         printf("O processo %d recebeu o seguinte valor: %d\n", my_rank, sum);
      } 
    printf("Soma totla: %d\n", sum);

   }

   /* Finaliza MPI */
   MPI_Finalize(); 

   return 0;
}  /* main */


