#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define PARAMETERS 50
#define CHUNK_SIZE 1000
#define NOISE_THRESHOLD_LOW 0.5
#define NOISE_THRESHOLD_HIGH 99.5

void eliminate_noise(float *data_chunk, float **valid_data, int *valid_count) {
    // Same logic as provided before...
}
