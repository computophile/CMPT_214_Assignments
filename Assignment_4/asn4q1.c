/*
Name: Mohammed Thamidur Rashid
Class: CMPT 214
Student #: 11280257
*/

#include <stdio.h>
#include<stdlib.h>
int main(){
  FILE *fp;
  int i = 0;
  char name[1000], weight[1000];
  float price_2018[10], price_2020[10], totalPrice2020 = 0, totalPrice2018 = 0;
  fp = fopen("food.txt", "r");


  if(fp != NULL){
  fgets(name, 1000, fp);//skipping the first line
    int i = 0;
    while (fscanf(fp,"%s %s %f %f", name, weight, &price_2018[i], &price_2020[i])!=EOF)
    {
    totalPrice2018 = totalPrice2018 + price_2018[i];
    totalPrice2020 = totalPrice2020 + price_2020[i];
      i++;
    }
    
  }
  else
  {
    printf("Error Reading Files/Not enough Permissions.\n");
    return 1;
  }
  
  printf("Total cost of all the items in 2018: %0.2f\n", totalPrice2018);
  printf("Total cost of all the items in 2020: %0.2f\n", totalPrice2020);
  printf("The differenece in the total cost: %0.2f\n", (totalPrice2018-totalPrice2020));

  fclose(fp);//close the file
  return 0;
}