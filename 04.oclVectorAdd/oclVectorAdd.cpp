/* --------------------- */
/* (C) 2020 madoodia.com */
/* All Rights Reserved.  */
/* --------------------- */

/* ---------------------------------------- */
/* C++ Version of NVidia SDK OpenCL Samples */
/* ---------------------------------------- */

#define __CL_ENABLE_EXCEPTIONS

#include <iostream>
#include <string>
#include <vector>

#include <CL/cl.hpp>

#include "errors.h"
#include "timer.h"
#include "utils.h"

uint roundUp(int groupSize, int globalSize);
void fillArray(std::vector<float> &data, int num);
void VectorAddHost(std::vector<float> pfData1,
                   std::vector<float> pfData2,
                   std::vector<float> &pfResult);

int main()
{
  std::cout << "\n";

  std::string filepath = "oclVectorAdd.cl";

  uint iNumElements = 100000000;
  uint localWorkSize = 256;
  uint globalWorkSize = roundUp(localWorkSize, iNumElements);

  std::vector<float> srcA(iNumElements);
  std::vector<float> srcB(iNumElements);
  std::vector<float> srcDst(iNumElements);
  std::vector<float> golden(iNumElements);

  std::cout << "Filling Arrays ran in: ";
  {
    Timer timer;
    fillArray(srcA, 1);
    fillArray(srcB, 2);
  }

  cl::Buffer devA;
  cl::Buffer devB;
  cl::Buffer devDst;

  try
  {
    std::vector<cl::Platform> platforms;

    cl::Platform::get(&platforms);

    cl::Context context(CL_DEVICE_TYPE_GPU);

    cl::Program program(context, utils::loadFromFile(filepath), true);

    cl::CommandQueue queue(context);

    auto vectorAdd = cl::make_kernel<cl::Buffer,
                                     cl::Buffer,
                                     cl::Buffer,
                                     uint>(program, "VectorAdd");

    std::cout << "Buffers ran in: ";
    {
      Timer timer;
      devA = cl::Buffer(context, srcA.begin(), srcA.end(), true);
      devB = cl::Buffer(context, srcB.begin(), srcB.end(), true);
      devDst = cl::Buffer(context, CL_MEM_WRITE_ONLY, sizeof(float) * iNumElements);
    }
    std::cout << "The kernel ran in: ";
    {
      Timer timer;
      vectorAdd(
          cl::EnqueueArgs(
              queue,
              cl::NDRange(iNumElements)),
          devA,
          devB,
          devDst,
          iNumElements);
      queue.finish();
    }
    std::cout << "cl::copy ran in: ";
    {
      Timer timer;
      cl::copy(queue, devDst, srcDst.begin(), srcDst.end());
    }

    std::cout << "The Host ran in: ";
    {
      Timer timer;
      VectorAddHost(srcA, srcB, golden);
    }

    // Print the end result
    // for (int i = 0; i < golden.size(); ++i)
    // {
    //   std::cout << "vectorAdd[" << i << "]: " << golden[i] << std::endl;
    // }
  }
  catch (cl::Error err)
  {
    std::cerr << err.what() << '\n';
  }
}

void fillArray(std::vector<float> &data, int num)
{
  int i;
  const float fScale = 1.0f / (float)RAND_MAX;
  // float randNum = fScale * rand();
  float randNum = num;
  for (int i = 0; i < data.size(); ++i)
  {
    data[i] = randNum;
  }
}

uint roundUp(int groupSize, int globalSize)
{
  int r = globalSize % groupSize;
  if (r == 0)
  {
    return globalSize;
  }
  else
  {
    return globalSize + groupSize - r;
  }
}

void VectorAddHost(std::vector<float> pfData1,
                   std::vector<float> pfData2,
                   std::vector<float> &pfResult)
{
  int i, j, k;
  for (i = 0, j = 0; i < pfResult.size(); i++)
  {
    pfResult[i] += pfData1[j] * pfData2[j];
  }
}