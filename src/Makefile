CC = mpicc
CFLAGS = -lm -lpthread
CUDA_PATH = /usr/local/cuda
CUDA_SRC = cuda_filter.cu
CUDA_OBJ = cuda_filter.o
OPENMP_SRC = openmp_processing.c
OPENMP_OBJ = openmp_processing.o
PTHREADS_SRC = pthreads_task.c
PTHREADS_OBJ = pthreads_task.o
MAIN_SRC = main.c
DATA_LOADER_SRC = data_loader.c
DATA_LOADER_OBJ = data_loader.o
DISTRIBUTE_MPI_SRC = distribute_mpi.c
DISTRIBUTE_MPI_OBJ = distribute_mpi.o
PARAMETERS = 50  # Define the number of parameters if needed

# List of all object files
OBJ = $(MAIN_SRC) $(OPENMP_OBJ) $(PTHREADS_OBJ) $(DATA_LOADER_OBJ) $(DISTRIBUTE_MPI_OBJ) $(CUDA_OBJ)

all: main

main: $(OBJ)
	$(CC) -o main $(OBJ) -L$(CUDA_PATH)/lib64 -lcudart $(CFLAGS) -I$(CUDA_PATH)/include

$(CUDA_OBJ): $(CUDA_SRC)
	nvcc -ccbin=g++ -c $(CUDA_SRC) -o $(CUDA_OBJ) -I$(CUDA_PATH)/include

$(OPENMP_OBJ): $(OPENMP_SRC)
	$(CC) -c $(OPENMP_SRC)

$(PTHREADS_OBJ): $(PTHREADS_SRC)
	$(CC) -c $(PTHREADS_SRC)

$(DATA_LOADER_OBJ): $(DATA_LOADER_SRC)
	$(CC) -c $(DATA_LOADER_SRC)

$(DISTRIBUTE_MPI_OBJ): $(DISTRIBUTE_MPI_SRC)
	$(CC) -c $(DISTRIBUTE_MPI_SRC)

clean:
	rm -f *.o main $(CUDA_OBJ) $(OPENMP_OBJ) $(PTHREADS_OBJ) $(DATA_LOADER_OBJ) $(DISTRIBUTE_MPI_OBJ)
