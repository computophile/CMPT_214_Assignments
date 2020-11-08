/*Name: Mohammed Thamidur Rashid
NSID: mor867
Student Number: 11280257
Subject: CMPT 214
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_CHARACTERS 30           //maximum number of characters of unique  city names
#define MAX_NUMBER_OF_DESTINATION 6 // Max number of destination for each source city

typedef struct city
{
  char cityName[MAX_CHARACTERS];                                    //to store the city name
  char cityDestinations[MAX_NUMBER_OF_DESTINATION][MAX_CHARACTERS]; // store the destination names from the source city
  int destinationCount;                                             // number of destination from the source city
} City;

City *read_cities(FILE *fp)
{
  /*
  Function: read_cities
  Purpose: to populated the data structure from the file read and return a pointer to the instance of the data structure
  Parameters: fp - file pointer that has been opened for reading;
  Return: (struct city *) the pointer to the populated instance of the data structure.
  */

  int entries, uniqueCityNames;

  fscanf(fp, "%d %d", &entries, &uniqueCityNames);

  City *cities = (City *)malloc(sizeof(City) * uniqueCityNames); //Dynamically allocated memory to hold an Array of cities

  for (int i = 0; i < uniqueCityNames; i++)
  {
    fscanf(fp, "%s", cities[i].cityName); //reading the city name to the data structure.
    cities[i].destinationCount = 0;       //intializing the destinatination count.
  }

  for (int i = 0; i < entries; i++)
  {
    /*looping through the loop to match the source with the
    unique city names and adding to the destination array of that city when matched.*/

    char source[30], destination[30];
    fscanf(fp, "%s %s", source, destination);

    for (int j = 0; j < uniqueCityNames; j++)
    {
      if (strcmp(cities[j].cityName, source) == 0)
      {
        strcpy(cities[j].cityDestinations[cities[j].destinationCount], destination);
        ++cities[j].destinationCount;
      }
    }
  }

  return cities;
}

void display_cities(City *cities, int N)
{
  /*
  Function: display_cities
  Purpose: to print the content of the data structure
  Parameters: (City *cities) - address location to the first element of the dynamically allocated data structure;
  int N: number of Cities in the data structure;
  Return: void
  */
  for (int i = 0; i < N; i++)
  {
    printf("%s: ", cities[i].cityName);
    for (int j = 0; j < cities[i].destinationCount; j++)
    {
      if (j == cities[i].destinationCount - 1)
      {
        //if index j is the last element print with a period and break from the loop;
        printf("%s.", cities[i].cityDestinations[j]);
        break;
      }
      printf("%s, ", cities[i].cityDestinations[j]);
    }
    printf("\n");
  }
}

void destroy_data_structure(City *cities)
{
  /*
  Function: destroy_data_structure
  Purpose: to free the memory dynamically allocated to the data structure
  Parameters: (City *cities) - address location to the first element of the dynamically allocated data structure;
  Return: void
  */
  free(cities); //free the allocated memory;
}

int main()
{
  FILE *fp = NULL;
  fp = fopen("travel-log.txt", "r");
  if (fp != NULL)
  {
    // if the file exists
    City *cities = read_cities(fp);
    rewind(fp); //to re-read the file
    int entries, uniqueCityNames;
    fscanf(fp, "%d %d", &entries, &uniqueCityNames);
    display_cities(cities, uniqueCityNames); //display the city names and the destinations
    destroy_data_structure(cities);          //free the dynimically allocated memory;
  }
  else
  {
    printf("Error reading file!\n");
    return 1; //error in reading the file
  }
  fclose(fp);
  return 0;
}
