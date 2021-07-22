#include <iostream>

#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

void printworld() {

#ifdef _OPENMP
            std::cout << "_OPENMP defined in printworld.cpp" << std::endl;
#else
            std::cout << "_OPENMP is not defined in printworld.cpp" << std::endl;
#endif

  #pragma omp parallel
  {
    int ID = omp_get_thread_num();

    #pragma omp critical
    {
      std::cout << "world" << ID <<std::endl;
    }
  }
}
