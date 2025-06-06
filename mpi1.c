#include <stdio.h>
#include <string.h>  
#include <mpi.h>     

int main(void) {
   int        comm_sz;               /* Número de processos    */
   int        my_rank;               /* Rank   do processo     */

   /* Inicia MPI */
   MPI_Init(NULL, NULL); 

   /* Obter número de processos */
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); 

   /* Obter rank (id) do processo */
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 

   
   char *res;
   switch(my_rank){
      case 0:
         res = "João";
         break;
      case 1:
         res = "Maria";
         break;
      case 2:
         res = "Pedro";
         break;
      case 3:
         res = "Marta";
         break;
      default:
         res ="Outro";
         break;
   }
printf("Número de processos: %d Rank do processos corrente: %d Nome: %s \n", comm_sz, my_rank, res);
   /* Encerra MPI */
   MPI_Finalize(); 

   return 0;
}  /* main */
