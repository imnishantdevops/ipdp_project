#ifndef CUDA_FILTER_H
#define CUDA_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void process_data_cuda(float *data, int size); // Ensure this declaration exists

#ifdef __cplusplus
}
#endif

#endif // CUDA_FILTER_H
