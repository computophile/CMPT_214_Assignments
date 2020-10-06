/*
Name: Mohammed Thamidur Rashid
NSID: mor867  
Course: CMPT 214
Student Number: 1280257
*/
#include <stdio.h>
int calcSmoothies(int n, int *strawberries, double *sugar, double *fruitJuice)
{
  if (n > 0)
  {
    *strawberries = n * 12;
    *sugar = (n * 0.5);
    *fruitJuice = (n * 1.5);
    return 0;
  }
  else
  {
    // for n is less than or equal to 0
    return 1;
  }
}

int main()
{

  int n, strawberries;
  double sugar, fruitJuice;

  // pointer declarations;
  int *ptr_strawberries = &strawberries;
  double *ptr_sugar = &sugar;
  double *ptr_fruitJuice = &fruitJuice;

  printf("Enter the number of smoothies you want to prepare: ");
  scanf("%d", &n);

  if (calcSmoothies(n, ptr_strawberries, ptr_sugar, ptr_fruitJuice) == 0)
  {
    printf("Amount of ingredients neccessary to make %d smoothies:\n %d Strawberries,\n %0.2lf tsp of sugar\n %0.2lf cups of fruit juice", n, strawberries, sugar, fruitJuice);
  }
  else
  {
    printf("Invalid input for n! Try again!!");
  }

  return 0;
}