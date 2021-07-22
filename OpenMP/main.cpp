#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

#include <iostream>

void printworld();

int main()
{

#ifdef _OPENMP
            std::cout << "_OPENMP defined in main.cpp" << std::endl;
#else
            std::cout << "_OPENMP is not defined in main.cpp" << std::endl;
#endif


printworld();

  #pragma omp parallel
  {
    int ID = omp_get_thread_num();

    #pragma omp critical
    {
      std::cout << "main" << ID <<std::endl;
    }
  }
  return 0;
}
