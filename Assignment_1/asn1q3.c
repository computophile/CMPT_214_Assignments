#include "stdio.h"
#include "math.h"

/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Course: CMPT 214
Assignment 1
*/

int main(){
    float p = 300.0; //profit
    int n; //number of chicken
    float e = 1.50 + 2.0; // expense to raise 1 chicken 1.50 price for each chick + $2 for food
    float f = 50 + 10; // $50 for setting up the hatchery and 10 dollar for gas
    float u = 4.0; // unit price charged per chicken


// the formula: p  = (n*u) - (n*e) - f
// since n number of r chicks has already been bought and raised the total expense = n * e
// the number of chicks that are sold after 5% loss = (n * u) - (0.05n * u) => 0.95( n * u)
// the final formula : p = (0.95(n * u)) - (n * e) - f
// on further simplification n = (p + f)/(0.95u - e)
    n = floor((p + f)/((0.95 * u) - e));
    printf("The total number of chickens that Mary bought to raise $300: %d \n" , n);
    printf("The number of chicks that Mary lost during the first sixteen weeks: %0.0f \n" , floor(n * 0.05));
    printf("Total expenses: %0.2f \n", (n * e) + f);

    return 0;
}

// where p is the profit, u is the unit price charged per chiken, e is the expense to raise the chicken, anf f represnts fixed one-time costs that are independent of how many chicken are raised.
