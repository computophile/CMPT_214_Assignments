/*
Name: Mohammed Thamidur Rashid
Class: CMPT 214
Student #: 11280257
*/

#include <stdio.h>

typedef struct smoothie
{
  char name[100];
  int unitSold;
  float price;
  float totalSales;
} Smoothie;

Smoothie bestSeller(char name[100])
{
  Smoothie bestSmoothie, sm;

  FILE *fp;
  fp = fopen(name, "r");
  float highestSelling = 0.0;
  if (fp)
  {
    int i = 0;
    while (fscanf(fp, "%s %d %f %f", sm.name, &sm.unitSold, &sm.price, &sm.totalSales) != EOF)
    {
      if (sm.totalSales > highestSelling)
      {

        highestSelling = sm.totalSales;
        strcpy(bestSmoothie.name, sm.name);
        bestSmoothie.price = sm.price;
        bestSmoothie.totalSales = sm.totalSales;
        bestSmoothie.unitSold = sm.unitSold;
      }
    }
  }
  fclose(fp);
  return bestSmoothie;
}

void main()
{
  Smoothie bestSellingSmoothie = bestSeller("sales.txt");
  printf("Displaying the best seller for the last weekend:\n");
  printf("Name: %s\n", bestSellingSmoothie.name);
  printf("Price: %f\n", bestSellingSmoothie.price);
  printf("Number Sold: %d\n", bestSellingSmoothie.unitSold);
  printf("Total Sales: %f\n", bestSellingSmoothie.totalSales);
}