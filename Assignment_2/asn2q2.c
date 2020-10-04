/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Course: CMPT 214
Assignment 2
*/

#include "stdio.h"

int checkTriangleValidity(int x, int y, int z)
{
  // returning 1 if the triagle is geometrically valid 0 otherwise.
  if ((x + y > z) && (x + z > y) && (y + z > x))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  double x, y, z;
  printf("Enter the value of x: ");
  scanf("%lf", &x);

  printf("Enter the value of y: ");
  scanf("%lf", &y);

  printf("Enter the value of z: ");
  scanf("%lf", &z);

  
  if (checkTriangleValidity(x, y, z) == 1)
  {
    printf("The Triangle is valid");
  }
  else
  {
    printf("The triangle is not valid");
  }
  return 0;
}
