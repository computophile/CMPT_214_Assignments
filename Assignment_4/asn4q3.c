/*
Name: Mohammed Thamidur Rashid
Class: CMPT 214
Student #: 11280257
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct smoothie
{
  char name[100];
  int unitSold;
  float price;
  float totalSales;
} Smoothie;

float highestSold (char fileName[100]){
  float maxSale = 0.0;
  Smoothie sm;
  FILE *fp;
  fp = fopen(fileName, "r");
// skip the first line of the text file
  char c[1];//dummy variable for fgets
  fgets(c, 100, fp);
  float price, totalSales = 0.0;
  int unitSold;
  char bestSellerName[100];
  
    while (!feof(fp))
    {
      fscanf(fp, "%s %d %f %f", sm.name, &sm.unitSold, &sm.price, &sm.totalSales);
      if (sm.totalSales > maxSale){
        maxSale = sm.totalSales;
      }

    }
  fclose(fp);
  return maxSale;
}

Smoothie bestSeller(char name[100])
{
  Smoothie bestSmoothie;

  FILE *fp;
  fp = fopen(name, "r");

  if (fp)
  {
    float highestSelling = highestSold(name);
    while (!feof(fp))
    {
      fscanf(fp, "%s %d %f %f", bestSmoothie.name, &bestSmoothie.unitSold, &bestSmoothie.price, &bestSmoothie.totalSales);
      if (bestSmoothie.totalSales == highestSelling){
        printf("I ma ");
        break;
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