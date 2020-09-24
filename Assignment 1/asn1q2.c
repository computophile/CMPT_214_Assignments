/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Course: CMPT 214
Assignment 1
*/

#include <stdio.h>

void main(){

  float diameter, pi, radius;
  pi = 3.14159265;
  
  printf("Enter the diameter: ");
  scanf("%f", &diameter);
  radius = diameter / 2;
  printf("The radius of the circle is %f \n", radius);
  printf("The area of the circle is %.2f \n", (pi * radius * radius));
  printf("The circumference is %.2f \n", (2 * pi * radius));

}