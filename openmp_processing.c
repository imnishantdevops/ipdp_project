#include "openmp_processing.h"
#include <omp.h>

void process_data_openmp(float *data, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        // Processing logic here
        data[i] *= 2;  // Example operation
    }
}
