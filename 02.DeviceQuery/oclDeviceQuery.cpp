/* --------------------- */
/* (C) 2020 madoodia.com */
/* All Rights Reserved.  */
/* --------------------- */

/* ---------------------------------------- */
/* C++ Version of NVidia SDK OpenCL Samples */
/* ---------------------------------------- */

#define __CL_ENABLE_EXCEPTIONS

#include <iostream>
#include <vector>

#include <CL/cl.hpp>

#include "errors.h"
#include "utils.h"

int main()
{
  std::cout << "OpenCL SW Info:\n";

  try
  {
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);
    std::cout << "Number of Platforms: " << platforms.size() << std::endl;
    std::cout << "----------------------------------------\n";

    for (auto &plat : platforms)
    {
      std::string info;
      plat.getInfo(CL_PLATFORM_NAME, &info);
      std::cout << "CL_PLATFORM_NAME: " << info << std::endl;

      plat.getInfo(CL_PLATFORM_VERSION, &info);
      std::cout << "CL_PLATFORM_VERSION: " << info << std::endl;

      std::cout << "----------\n";
      std::vector<cl::Device> devices;
      plat.getDevices(CL_DEVICE_TYPE_ALL, &devices);
      std::cout << "  Number of Devices: " << devices.size() << std::endl;

      for (auto &device : devices)
      {
        device.getInfo(CL_DEVICE_NAME, &info);
        std::cout << "  CL_DEVICE_NAME: " << info << std::endl;
        cl::Context context(device);

        std::vector<cl::ImageFormat> formats;
        context.getSupportedImageFormats(CL_MEM_READ_ONLY,
                                         CL_MEM_OBJECT_IMAGE2D,
                                         &formats);

        std::cout << "\n  2D Image Formats Supported:\n  ";
        for (auto &format : formats)
        {
          std::cout << utils::oclImageFormatToString(format) << " ";
        }
        std::cout << "\n";

        context.getSupportedImageFormats(CL_MEM_READ_ONLY,
                                         CL_MEM_OBJECT_IMAGE3D,
                                         &formats);

        std::cout << "\n  3D Image Formats Supported:\n  ";
        for (auto &format : formats)
        {
          std::cout << utils::oclImageFormatToString(format) << " ";
        }
        std::cout << "\n";
      }
    }
  }
  catch (cl::Error err)
  {
    std::cerr << err.what() << '\n';
  }

  return 0;
}
