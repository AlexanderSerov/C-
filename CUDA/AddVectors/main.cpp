/*
 * Set up environment for compiling cuda:
 * 1) Install compatible toolchain VS 2017 or 2019. Install it through separate installer to get full functionality.
 * 2) You can compile in Command Prompt now using nvcc. For using Powershell x64 follow instructions in Workflow
 * 		document on Drive.
 * 3) To be able VS toolset locate you cuda installation you need copy nvidia extension for VS to VS toolset.
 * 		Details: https://github.com/mitsuba-renderer/mitsuba2/issues/103#issuecomment-618378963
 * 4) If you use CLion you just need to specify desired, preconfigured toolset.
 * */
#include <iostream>


// Kernel function to add the elements of two arrays
__global__
void add(int n, const float *x, float *y)
{
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	int stride = blockDim.x * gridDim.x;
	for (int i = index; i < n; i += stride)
		y[i] = x[i] + y[i];
}

int main()
{
	int N = 1<<20;
	float *x, *y;

	// Allocate Unified Memory – accessible from CPU or GPU
	cudaMallocManaged(&x, N*sizeof(float));
	cudaMallocManaged(&y, N*sizeof(float));

	// initialize x and y arrays on the host
	for (int i = 0; i < N; i++) {
		x[i] = 1.0f;
		y[i] = 2.0f;
	}

	// Prefetch the data to the GPU
	int device = -1;
	cudaGetDevice(&device);
	std::cout << "device: " << device << std::endl;
	cudaMemPrefetchAsync(x, N*sizeof(float), device, nullptr);
	cudaMemPrefetchAsync(y, N*sizeof(float), device, nullptr);

	// Run kernel on 1M elements on the GPU
	int blockSize = 256;
	int gridSize = (N / blockSize) + 1;
	add<<<gridSize, blockSize>>>(N, x, y);

	// Prefetch the data to the CPU
	cudaMemPrefetchAsync(y, N*sizeof(float), cudaCpuDeviceId, nullptr);

	// Wait for GPU to finish before accessing on host
	cudaDeviceSynchronize();

	// Check for errors (all values should be 3.0f)
	float maxError = 0.0f;
	for (int i = 0; i < N; i++)
		maxError = fmax(maxError, fabs(y[i]-3.0f));
	std::cout << "Max error: " << maxError << std::endl;

	// Free memory
	cudaFree(x);
	cudaFree(y);

	return 0;
}