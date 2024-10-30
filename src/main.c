#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "data_loader.h"

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    float *data;  // Declare a float pointer to hold the data
    int num_chunks;

    // Load data from the dataset
    load_and_distribute_data(&data, &num_chunks);  // Pass the address of the data pointer

    // Example output to verify data loaded correctly
    printf("Number of chunks: %d\n", num_chunks);
    printf("First record, first parameter: %f\n", data[0]);  // Print first value for verification

    // Other processing...

    free(data);  // Free allocated memory
    MPI_Finalize();
    return 0;
}
