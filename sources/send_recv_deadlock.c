#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
  int my_rank;       
  int size;             
  int tag=0;        
  char message[100]; 
  MPI_Status status; 

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  printf(message, "Greetings from process %d!", my_rank);

  if (my_rank == 0) {
    MPI_Recv(message, 100, MPI_CHAR, 1, tag, MPI_COMM_WORLD, &status);
    MPI_Send(message, strlen(message)+1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
    printf("Process 0 printing:  %s\n", message);
  }
  else { 
    MPI_Recv(message, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
    MPI_Send(message, strlen(message)+1, MPI_CHAR, 0, tag, MPI_COMM_WORLD);
    printf("Process 1 printing:  %s\n", message);
  }
  
  MPI_Finalize();
}