#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "data_loader.h"
#include "noise_elimination.h"

#define CHUNK_SIZE 1000
#define PARAMETERS 50
#define MASTER 0

int main(int argc, char *argv[]) {
    int rank, total_ranks;
    int num_chunks_per_rank;
    float *data_chunk;
    int valid_records = 0;
    int total_valid_records = 0;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &total_ranks);

    // Determine the number of chunks each rank will process
    num_chunks_per_rank = (RECORDS / CHUNK_SIZE) / total_ranks;

    // Allocate memory for a data chunk
    data_chunk = (float *)malloc(CHUNK_SIZE * PARAMETERS * sizeof(float));
    if (data_chunk == NULL) {
        perror("Failed to allocate memory for data chunk");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    for (int chunk_index = 0; chunk_index < num_chunks_per_rank; chunk_index++) {
        // Load data for the current chunk
        load_and_distribute_data(data_chunk, chunk_index, rank);

        // Eliminate noise in the chunk
        eliminate_noise(data_chunk, &valid_records);

        // Send valid record count to the master process
        if (rank != MASTER) {
            MPI_Send(&valid_records, 1, MPI_INT, MASTER, 0, MPI_COMM_WORLD);
        } else {
            total_valid_records += valid_records;
            for (int source = 1; source < total_ranks; source++) {
                int received_valid_records;
                MPI_Recv(&received_valid_records, 1, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                total_valid_records += received_valid_records;
            }

            // Print progress
            printf("Processed chunk %d/%d, Total valid records so far: %d\n", 
                   chunk_index + 1, num_chunks_per_rank, total_valid_records);
        }
    }

    // Free memory and finalize MPI
    free(data_chunk);
    MPI_Finalize();
    return 0;
}
