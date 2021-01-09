#include "fun.h"
#include<stdio.h>

int main()
{
  int a, b, c, d;
  a = 7;
  b = 3;
  c = add(a,b);
  d = mul(a,b);
  printf("c=%d,d=%d\n",c,d);
  return 0;
}
