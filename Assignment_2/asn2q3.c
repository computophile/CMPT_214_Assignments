/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Course: CMPT 214
Assignment 1
*/

#include "stdio.h"
#include "math.h"

int deadChicks(int n){
  return  0.05 * n;
}

int chicks(int e, int f, int u, int p)
{

  return ceil(round((p + f) / ((.95) * u - e) * 1000.0) / 1000.0);
}

int main()
{
  double f, e, u, p;

  // modiied formula:
  // p = (loss_rate * n * u) - (n * e) - f;

  // Solve for n:
  // have to round to three decimal places to combat roundoff error interacating weirdly with ceil()
  printf("Enter the total fixed one time costs , f :");
  scanf("%lf", &f);
  printf("Enter the expenses to raise one chicken , e :");
  scanf("%lf", &e);
  printf("Enter the unit price charged per chicken , u :");
  scanf("%lf", &u);
  printf("Enter the required profit , p :");
  scanf("%lf", &p);

  int n = chicks( e,  f,  u, p);
  printf("The number of chickens that Mary bought to raise %0.2lf is : %d\n", p, n)  ;
  // This is also acceptable, but will result in off-by-one errors because ceil() will round up
  // tiny roundoff errors:
  printf("The number of chickens lost during the first 16 weeks was : %d \n", deadChicks(n));

  // Again, have to round to 3 decimal places before we ceil() to avoid roundoff.
  // int lost = (int)ceil(round(5 * n * 1000.0) / 1000.0);

  // Version not accounting for roundoff is also acceptable:
  // int lost = loss_rate * n;
}