/*
Name: Mohammed Thamidur Rashid
Class: CMPT 214
Student #: 11280257
*/

#include <stdio.h>
#define COUNT 5

float avgLife(float province[COUNT])
{
  float total = 0.0;
  for (int i = 0; i < COUNT; i++)
  {
    total += province[i];
  }
  return (total / COUNT);
}

void highLow(float province[COUNT])
{
  float high = 0.0;
  float low = province[0];
  for (int i = 0; i < COUNT; i++)
  {
    if (province[i] > high)
    {
      high = province[i];
    }
    if (province[i] < low)
    {
      low = province[i];
    }
  }

  printf("Lowest  life  expectancy  value is: %0.3f\n", low);
  printf("Highest  life  expectancy  value is: %0.3f\n", high);
}

void insertionSort(float province[COUNT])
{
  int i, j;
  float temp;

  for (i = 1; i < COUNT; i++)
  {
    temp = province[i];
    j = i - 1;
    while ((temp > province[j]) && (j >= 0))
    {
      province[j + 1] = province[j];
      j = j - 1;
    }
    province[j + 1] = temp;
  }
}

int main()
{
  float LifeEx[COUNT] = {75.981, 82.675, 68.745, 99.425, 88.442};
  printf("Average of the life expentancy values: %0.3f\n", avgLife(LifeEx));
  highLow(LifeEx);
  printf("The list of sorted life expentancy values: \n");
  insertionSort(LifeEx);
  for (int i = 0; i < COUNT; i++)
  {
    printf("%0.3f\n",LifeEx[i]);
  }
  return 0;
}