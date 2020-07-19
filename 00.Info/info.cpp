/* --------------------- */
/* (C) 2020 madoodia.com */
/* All Rights Reserved.  */
/* --------------------- */

#define __CL_ENABLE_EXCEPTIONS

#include <iostream>
#include <vector>

#include <CL/cl.hpp>

#include "errors.h"

int main()
{
  try
  {
    // Discover number of platforms
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);
    std::cout << "\nNumber of OpenCL plaforms: " << platforms.size() << std::endl;

    // Investigate each platform
    std::cout << "\n-------------------------" << std::endl;
    // for (std::vector<cl::Platform>::iterator plat = platforms.begin(); plat != platforms.end(); plat++)
    for (auto &plat : platforms)
    {
      std::string s;
      plat.getInfo(CL_PLATFORM_NAME, &s);
      std::cout << "Platform: " << s << std::endl;

      plat.getInfo(CL_PLATFORM_VENDOR, &s);
      std::cout << "\tVendor:  " << s << std::endl;

      plat.getInfo(CL_PLATFORM_VERSION, &s);
      std::cout << "\tVersion: " << s << std::endl;

      // Discover number of devices
      std::vector<cl::Device> devices;
      plat.getDevices(CL_DEVICE_TYPE_ALL, &devices);
      std::cout << "\n\tNumber of devices: " << devices.size() << std::endl;

      // Investigate each device
      // for (std::vector<cl::Device>::iterator dev = devices.begin(); dev != devices.end(); dev++)
      for (auto &dev : devices)
      {
        std::cout << "\t-------------------------" << std::endl;

        dev.getInfo(CL_DEVICE_NAME, &s);
        std::cout << "\tCL_DEVICE_NAME: " << s << std::endl;
        dev.getInfo(CL_DEVICE_VENDOR, &s);
        std::cout << "\tCL_DEVICE_VENDOR: " << s << std::endl;
        dev.getInfo(CL_DRIVER_VERSION, &s);
        std::cout << "\tCL_DRIVER_VERSION: " << s << std::endl;
        dev.getInfo(CL_DEVICE_PROFILE, &s);
        std::cout << "\tCL_DEVICE_PROFILE: " << s << std::endl;
        dev.getInfo(CL_DEVICE_VERSION, &s);
        std::cout << "\tCL_DEVICE_VERSION: " << s << std::endl;
        dev.getInfo(CL_DEVICE_EXTENSIONS, &s);
        std::cout << "\tCL_DEVICE_EXTENSIONS: " << s << std::endl;

        dev.getInfo(CL_DEVICE_OPENCL_C_VERSION, &s);
        std::cout << "\n\tCL_DEVICE_OPENCL_C_VERSION: " << s << std::endl;

        int i;
        dev.getInfo(CL_DEVICE_MAX_COMPUTE_UNITS, &i);
        std::cout << "\tCL_DEVICE_MAX_COMPUTE_UNITS: " << i << std::endl;

        dev.getInfo(CL_DEVICE_MAX_CLOCK_FREQUENCY, &i);
        std::cout << "\tCL_DEVICE_MAX_CLOCK_FREQUENCY: " << i << std::endl;

        dev.getInfo(CL_DEVICE_ADDRESS_BITS, &i);
        std::cout << "\n\tCL_DEVICE_ADDRESS_BITS: " << i << std::endl;

        dev.getInfo(CL_DEVICE_IMAGE_SUPPORT, &i);
        std::cout << "\tCL_DEVICE_IMAGE_SUPPORT: " << i << std::endl;

        dev.getInfo(CL_DEVICE_MAX_READ_IMAGE_ARGS, &i);
        std::cout << "\tCL_DEVICE_MAX_READ_IMAGE_ARGS: " << i << std::endl;

        dev.getInfo(CL_DEVICE_MAX_WRITE_IMAGE_ARGS, &i);
        std::cout << "\tCL_DEVICE_MAX_WRITE_IMAGE_ARGS: " << i << std::endl;

        size_t size;
        dev.getInfo(CL_DEVICE_IMAGE2D_MAX_WIDTH, &size);
        std::cout << "\n\tCL_DEVICE_IMAGE2D_MAX_WIDTH: " << size << " [" << size / 1000 << "k]" << std::endl;
        dev.getInfo(CL_DEVICE_IMAGE2D_MAX_HEIGHT, &size);
        std::cout << "\tCL_DEVICE_IMAGE2D_MAX_HEIGHT: " << size << " [" << size / 1000 << "k]" << std::endl;
        dev.getInfo(CL_DEVICE_IMAGE3D_MAX_WIDTH, &size);
        std::cout << "\tCL_DEVICE_IMAGE3D_MAX_WIDTH: " << size << " [" << size / 1000 << "k]" << std::endl;
        dev.getInfo(CL_DEVICE_IMAGE3D_MAX_HEIGHT, &size);
        std::cout << "\tCL_DEVICE_IMAGE3D_MAX_HEIGHT: " << size << " [" << size / 1000 << "k]" << std::endl;
        dev.getInfo(CL_DEVICE_IMAGE3D_MAX_DEPTH, &size);
        std::cout << "\tCL_DEVICE_IMAGE3D_MAX_DEPTH: " << size << " [" << size / 1000 << "k]" << std::endl;

        dev.getInfo(CL_DEVICE_MAX_SAMPLERS, &i);
        std::cout << "\n\tCL_DEVICE_MAX_SAMPLERS: " << i << std::endl;

        dev.getInfo(CL_DEVICE_MAX_PARAMETER_SIZE, &size);
        std::cout << "\n\tCL_DEVICE_MAX_PARAMETER_SIZE: " << size << std::endl;
        dev.getInfo(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, &size);
        std::cout << "\tCL_DEVICE_MAX_CONSTANT_BUFFER_SIZE: " << size << std::endl;

        dev.getInfo(CL_DEVICE_ENDIAN_LITTLE, &i);
        std::cout << "\n\tCL_DEVICE_ENDIAN_LITTLE: " << i << std::endl;

        dev.getInfo(CL_DEVICE_AVAILABLE, &i);
        std::cout << "\n\tCL_DEVICE_AVAILABLE: " << i << std::endl;

        dev.getInfo(CL_DEVICE_COMPILER_AVAILABLE, &i);
        std::cout << "\n\tCL_DEVICE_COMPILER_AVAILABLE: " << i << std::endl;

        dev.getInfo(CL_DEVICE_MEM_BASE_ADDR_ALIGN, &i);
        std::cout << "\n\tCL_DEVICE_MEM_BASE_ADDR_ALIGN: " << i << std::endl;

        dev.getInfo(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, &i);
        std::cout << "\n\tCL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE: " << i << std::endl;

        dev.getInfo(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, &size);
        std::cout << "\n\tCL_DEVICE_GLOBAL_MEM_CACHE_SIZE: " << size << std::endl;

        dev.getInfo(CL_DEVICE_LOCAL_MEM_SIZE, &size);
        std::cout << "\n\tCL_DEVICE_LOCAL_MEM_SIZE: " << size / 1024 << " KB" << std::endl;

        dev.getInfo(CL_DEVICE_GLOBAL_MEM_SIZE, &size);
        std::cout << "\tCL_DEVICE_GLOBAL_MEM_SIZE: " << size / (1024 * 1024) << " MB" << std::endl;

        dev.getInfo(CL_DEVICE_MAX_MEM_ALLOC_SIZE, &size);
        std::cout << "\n\tCL_DEVICE_MAX_MEM_ALLOC_SIZE: " << size / (1024 * 1024) << " MB" << std::endl;

        dev.getInfo(CL_DEVICE_MAX_WORK_GROUP_SIZE, &size);
        std::cout << "\tCL_DEVICE_MAX_WORK_GROUP_SIZE: " << size << std::endl;

        dev.getInfo(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, &size);
        std::cout << "\tCL_DEVICE_MAX_WORK_ITEM_DIMENSIONS: " << size << std::endl;

        std::vector<size_t> deviceDims;
        dev.getInfo(CL_DEVICE_MAX_WORK_ITEM_SIZES, &deviceDims);
        std::cout << "\tCL_DEVICE_MAX_WORK_ITEM_SIZES: (";
        // for (std::vector<size_t>::iterator st = deviceDims.begin(); st != deviceDims.end(); st++)
        for (auto &st : deviceDims)
          std::cout << st << " ";
        std::cout << "\x08)" << std::endl;

        std::cout << "\t-------------------------" << std::endl;
      }

      std::cout << "\n-------------------------\n";
    }
  }
  catch (cl::Error err)
  {
    std::cout << "OpenCL Error: " << err.what() << " returned " << errorCode(err.err()) << std::endl;
    exit(-1);
  }

  return 0;
}
