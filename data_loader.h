#ifndef DATA_LOADER_H
#define DATA_LOADER_H

float *load_data_from_file(const char *filename, int *num_records);
void load_and_distribute_data(float **data, int *num_chunks);

#endif // DATA_LOADER_H
