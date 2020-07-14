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

} // namespace utils

#endif //UTILS_H