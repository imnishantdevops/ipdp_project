#include "pthreads_task.h"
#include <pthread.h>

void process_data_pthreads(float *data, int size) {
    // Create and manage threads for processing
    for (int i = 0; i < size; i++) {
        data[i] += 1;  // Example operation
    }
}
