/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Course: CMPT 214
Assignment 1
*/

#include "stdio.h"

int checkTriangleValidity(int x, int y, int z)
{
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

  // printf("The sides that are entered by the user is: %f ,%f, %f", x, y, z);
  
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
