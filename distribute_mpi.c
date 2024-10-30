#include <mpi.h>
#include <stdlib.h>  // Include stdlib for malloc
#include "data_loader.h" // Make sure this header is correctly defined
#include <stdio.h>

void distribute_with_mpi(float *data, int num_records) {
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int chunk_size = num_records / num_procs; // Use num_procs instead of size
    float *chunk = (float *)malloc(chunk_size * sizeof(float));

    if (chunk == NULL) {
        perror("Failed to allocate memory for chunk");
        exit(EXIT_FAILURE);
    }

    MPI_Scatter(data, chunk_size, MPI_FLOAT, chunk, chunk_size, MPI_FLOAT, 0, MPI_COMM_WORLD);

    // Process the chunk here (you can call your processing function)
    // process_data(chunk, chunk_size); // Uncomment this line and define process_data() accordingly

    free(chunk);
}

