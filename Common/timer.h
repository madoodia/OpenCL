/* --------------------- */
/* (C) 2020 madoodia.com */
/* All Rights Reserved.  */
/* --------------------- */

#ifndef MYTIMER_H
#define MYTIMER_H

#include <chrono>
#include <iostream>

struct Timer
{
  std::chrono::steady_clock::time_point start, end;
  std::chrono::duration<double> duration = {};
  double endResult = 0.0;

  Timer()
  {
    start = std::chrono::steady_clock::now();
  }

  ~Timer()
  {
    endResult = result();
    std::cout << endResult << " ms\n";
  }

  double result()
  {
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    endResult = (double)duration.count() * (double)1000.0f;
    return endResult;
  }
};

#endif // MYTIMER_H
