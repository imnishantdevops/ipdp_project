#include "cuda_filter.h"
#include <cuda_runtime.h> // Ensure you include the CUDA runtime header

__global__ void process_cuda_kernel(float *data, int size) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < size) {
        data[idx] += 10;  // Example operation
    }
}

void process_data_cuda(float *data, int size) {
    float *d_data;
    cudaMalloc(&d_data, size * sizeof(float));
    cudaMemcpy(d_data, data, size * sizeof(float), cudaMemcpyHostToDevice);
    
    // Launch kernel (for example, with 256 threads per block)
    int blocks = (size + 255) / 256;
    process_cuda_kernel<<<blocks, 256>>>(d_data, size);
    
    cudaMemcpy(data, d_data, size * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(d_data);
}
