cmake_minimum_required(VERSION 3.20)

project(AddVectors )

set(CMAKE_CUDA_STANDARD 14)

if(UNIX)
    find_package(CUDAToolkit REQUIRED)
    # For enable_language(CUDA) to complete correctly, the CMAKE_CUDA_COMPILER variable must be defined.
    # This is not always done (e.g. jetson).
    # So first we find the CUDAToolkit package.
    # Next, we check that the CMAKE_CUDA_COMPILER variable is not empty. If it is empty, we define it to be CUDAToolkit_NVCC_EXECUTABLE.
    # Lastly we set enable_language(CUDA).
    if (NOT CMAKE_CUDA_COMPILER)
        if (NOT MSVC)
            set(CMAKE_CUDA_COMPILER ${CUDAToolkit_NVCC_EXECUTABLE})
            set(CMAKE_CUDA_HOST_COMPILER ${CMAKE_CXX_COMPILER})
        endif()
    endif()

    enable_language(CUDA)
endif()

add_executable(AddVectors main.cu)