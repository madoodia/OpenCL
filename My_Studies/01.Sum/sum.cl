/* --------------------- */
/* (C) 2020 madoodia.com */
/* All Rights Reserved.  */
/* --------------------- */

__kernel void sum(
    __global float *a,
    __global float *b,
    __global float *c,
    const unsigned int length)
{
  int gid = get_global_id(0);
  if (gid < length)
  {
    c[gid] = a[gid] + b[gid];
  }
}