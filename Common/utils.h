/* --------------------- */
/* (C) 2020 madoodia.com */
/* All Rights Reserved.  */
/* --------------------- */

#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

namespace utils
{

std::string loadFromFile(std::string filepath)
{
  std::ifstream stream(filepath.c_str());
  if (!stream.is_open())
  {
    std::cout << "Failed to open File: " << filepath << std::endl;
    exit(1);
  }

  return std::string(
      std::istreambuf_iterator<char>(stream),
      (std::istreambuf_iterator<char>()));
}

std::string oclImageFormatToString(cl::ImageFormat format)
{
  // cl_channel_order
  if (format.image_channel_order == CL_R)
    return "CL_R";
  if (format.image_channel_order == CL_A)
    return "CL_A";
  if (format.image_channel_order == CL_RG)
    return "CL_RG";
  if (format.image_channel_order == CL_RA)
    return "CL_RA";
  if (format.image_channel_order == CL_RGB)
    return "CL_RGB";
  if (format.image_channel_order == CL_RGBA)
    return "CL_RGBA";
  if (format.image_channel_order == CL_BGRA)
    return "CL_BGRA";
  if (format.image_channel_order == CL_ARGB)
    return "CL_ARGB";
  if (format.image_channel_order == CL_INTENSITY)
    return "CL_INTENSITY";
  if (format.image_channel_order == CL_LUMINANCE)
    return "CL_LUMINANCE";

  // cl_channel_type
  if (format.image_channel_data_type == CL_SNORM_INT8)
    return "CL_SNORM_INT8";
  if (format.image_channel_data_type == CL_SNORM_INT16)
    return "CL_SNORM_INT16";
  if (format.image_channel_data_type == CL_UNORM_INT8)
    return "CL_UNORM_INT8";
  if (format.image_channel_data_type == CL_UNORM_INT16)
    return "CL_UNORM_INT16";
  if (format.image_channel_data_type == CL_UNORM_SHORT_565)
    return "CL_UNORM_SHORT_565";
  if (format.image_channel_data_type == CL_UNORM_SHORT_555)
    return "CL_UNORM_SHORT_555";
  if (format.image_channel_data_type == CL_UNORM_INT_101010)
    return "CL_UNORM_INT_101010";
  if (format.image_channel_data_type == CL_SIGNED_INT8)
    return "CL_SIGNED_INT8";
  if (format.image_channel_data_type == CL_SIGNED_INT16)
    return "CL_SIGNED_INT16";
  if (format.image_channel_data_type == CL_SIGNED_INT32)
    return "CL_SIGNED_INT32";
  if (format.image_channel_data_type == CL_UNSIGNED_INT8)
    return "CL_UNSIGNED_INT8";
  if (format.image_channel_data_type == CL_UNSIGNED_INT16)
    return "CL_UNSIGNED_INT16";
  if (format.image_channel_data_type == CL_UNSIGNED_INT32)
    return "CL_UNSIGNED_INT32";
  if (format.image_channel_data_type == CL_HALF_FLOAT)
    return "CL_HALF_FLOAT";
  if (format.image_channel_data_type == CL_FLOAT)
    return "CL_FLOAT";

  // unknown constant
  return "Unknown";
}

} // namespace utils

#endif //UTILS_H