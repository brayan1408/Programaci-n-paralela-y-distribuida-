
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  const int LIMIT = 10;

  MPI_Init(NULL, NULL);
 
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); //Rank
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);// total de procesos

  // 2 procesos
  if (world_size != 2) {
    fprintf(stderr, "Debe ser 2 %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int ping_pong_count = 0;
  int partner_rank = (world_rank + 1) % 2;
  for(;ping_pong_count < LIMIT;) {
    if (world_rank == ping_pong_count % 2) {
      ping_pong_count++;
      MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
      printf("%d ping_pong_count enviado e incrementado %d a %d\n",
             world_rank, ping_pong_count, partner_rank);
    } else {
      MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
      printf("%d ping_pong_count recibido %d de %d\n",
             world_rank, ping_pong_count, partner_rank);
    }
  }
  MPI_Finalize();
}
