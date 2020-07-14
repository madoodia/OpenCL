/* --------------------- */
/* (C) 2020 madoodia.com */
/* All Rights Reserved.  */
/* --------------------- */

#define __CL_ENABLE_EXCEPTIONS

#include <iostream>
#include <string>
#include <vector>

#include <CL/cl.hpp>

#include "errors.h"
#include "timer.h"
#include "utils.h"

int main()
{
  // Define the size of the problem (1D array)
  const unsigned int LENGTH = 10;

  // Define Host Memories
  std::vector<float> h_a(LENGTH);
  std::vector<float> h_b(LENGTH);
  std::vector<float> h_c(LENGTH);

  // Define Device Memories
  cl::Buffer d_a;
  cl::Buffer d_b;
  cl::Buffer d_c;

  // Initialize Host Memories
  for (int i = 0; i < LENGTH; ++i)
  {
    h_a[i] = rand() / (float)RAND_MAX;
    h_b[i] = rand() / (float)RAND_MAX;
  }
  try
  {
    // Get Platform of System
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    // Create Context
    cl::Context context(CL_DEVICE_TYPE_GPU);

    // Create Program from .cl file
    cl::Program program(context, utils::loadFromFile("sum.cl"), true);

    // Create CommandQueue from current context
    cl::CommandQueue queue(context);

    // Create Kernel from the program
    auto sum = cl::make_kernel<cl::Buffer, cl::Buffer, cl::Buffer, unsigned int>(program, "sum");

    // Copy data from Host Memories to Device Memories
    d_a = cl::Buffer(context, h_a.begin(), h_a.end(), true);
    d_b = cl::Buffer(context, h_b.begin(), h_b.end(), true);
    d_c = cl::Buffer(context, CL_MEM_WRITE_ONLY, sizeof(float) * LENGTH);

    // Run the Program on Device with timer
    std::cout << "The kernel ran in: ";
    {
      Timer timer;
      sum(
          cl::EnqueueArgs(
              queue,
              cl::NDRange(LENGTH)),
          d_a,
          d_b,
          d_c,
          LENGTH);
      queue.finish();
    }

    // Copy Data from Device Memories to Host Memories
    cl::copy(queue, d_c, h_c.begin(), h_c.end());
  }
  catch (cl::Error err)
  {
    std::cerr << err.what() << '\n';
  }
}
