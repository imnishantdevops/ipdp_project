#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define RECORDS 50000000LL
#define PARAMETERS 50
#define CHUNK_SIZE 1000
#define FILENAME "/home/nishant-kamal/Downloads/dataset.csv"  // Path to your CSV file

void load_and_distribute_data(float **data, int *num_chunks, int rank, int size) {
    *num_chunks = RECORDS / CHUNK_SIZE;
    *data = (float *)malloc(RECORDS * PARAMETERS * sizeof(float));

    if (*data == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Open the CSV file for reading
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open file");
        free(*data);
        exit(EXIT_FAILURE);
    }

    // Read the data from the file
    for (long long i = 0; i < RECORDS; i++) {
        for (int j = 0; j < PARAMETERS; j++) {
            if (fscanf(file, "%f,", &(*data)[i * PARAMETERS + j]) != 1) {
                fprintf(stderr, "Error reading data at record %lld, parameter %d\n", i, j);
                free(*data);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}
