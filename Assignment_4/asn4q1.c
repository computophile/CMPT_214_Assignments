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
  char name[1000];
  float price_2018[10], price_2020[10], totalPrice2020 = 0, totalPrice2018 = 0;
  fp = fopen("food.txt", "r");
  // reading the file to skip the first line
  fgets(name, 1000, fp);

  if(fp){
    printf("File is read:\n");

    for (int i = 0; i < 10; i++){
    
    char weight[1000];
    char itemPrice18[1000], itemPrice20[1000];
    fscanf(fp, "%s", &name[i]);
    fscanf(fp, "%s", &weight[i]);
    fscanf(fp, "%s", &itemPrice18[i]);
    fscanf(fp, "%s", &itemPrice20[i]);

    printf("\nName: %s \n", &name[i]);
    printf("Weight:  %s\n", &weight[i]);
    printf("2018: %s\n", &itemPrice18[i]);
    printf("2019: %s\n", &itemPrice20[i]);

    // float f = atof(&itemPrice18[i]);
    // float f = atof(&itemPrice18[i]);

    
    price_2018[i] = atof(&itemPrice18[i]);
    price_2020[i] = atof(&itemPrice20[i]);

    totalPrice2018 = totalPrice2018 + price_2018[i];
    totalPrice2020 = totalPrice2020 + price_2020[i];

    printf("The Value of i:%d\n", i);
    printf("converted value of price 2018: %f", price_2018[i]);
    printf("converted value of price 2018: %f\n", price_2020[i]);


    }
  }
  
  printf("Total cost of all the items in 2018: %0.2f\n", totalPrice2018);
  printf("Total cost of all the items in 2020: %0.2f\n", totalPrice2020);
  printf("The differenece in price: %0.2f\n", (totalPrice2018-totalPrice2020));

  fclose(fp);
  return 0;
}