/*
Name: Mohammed Thamidur Rashid
NSID: 11280257
Subject: CMPT 214
*/

#include <stdio.h>

#define STATION_CODE_LENGTH 4

typedef struct _station
{
  // defining the node
  char code[STATION_CODE_LENGTH];
  struct _station *next;
} Station;

typedef struct _route
{
  // keeping track of the route
  Station *first_station;
  unsigned int num_stations;
} Route;

Route *read_stations(FILE *fp)
{
  // Purpose: To read the content of the file and put it
  if (fp != NULL)
  {
    printf("We are reading the file! \n");
    char city_code[STATION_CODE_LENGTH];
    Route *route = NULL;

    route = (Route *)malloc(sizeof(Route));

    fscanf(fp, "%s", city_code);

    Station *station_node = (Station *)malloc(sizeof(Station));

    strcpy(station_node->code, city_code);

    station_node->next = NULL;

    route->first_station = station_node;

    route->num_stations = 1;

    while (fscanf(fp, "%s", city_code) != EOF)
    {
      // ;
      // if (feof(fp)){
      //   break;// break if we have reached the end of the file!
      // }
      if (city_code == "\n" || city_code == "\0")
      {
        break;
      }
      route->num_stations = route->num_stations + 1;

      Station *new_station = (Station *)malloc(sizeof(Station));

      strcpy(new_station->code, city_code);

      new_station->next = route->first_station;

      route->first_station = new_station;

      // printf("Route first station: %p]\n", route->first_station);
      // printf("The value of station: %s\n", new_station->code);
      // printf("The next value of stations: %p\n", station_node->next);
    }
    fclose(fp);
    return route;
  }
}
void display(Route *route)
{
  // takes a pointer to the Route structure and prints every station code in the list
  // *route: pointer to the Route Structure
  Station *station = route->first_station;
  while (station != NULL)
  {
    printf("%s\n", station->code);
    station = station->next;
  }
}

int search(Route *route, char c[STATION_CODE_LENGTH])
{
  // to display the position number of the station whose code matches c;
  // *route: pointer to Route srtucture
  // 3-Character station code
  Station *station = route->first_station;
  int position = 0;
  while (station != NULL)
  {
    ++position;

    if (strcmp(station->code, c) == 0)
    {
      printf("Code position: %d\n", position);

      // print the next two codes if available
      if (position == route->num_stations - 1)
      {
        printf("The next two codes:\n");
        station = station->next;
        printf("%s\n", station->code);
        printf("Beyond the end of line.\n");
        return 0;

      }
      else if (position == route->num_stations)
      {
        printf("Beyond the end of line.\n");
        printf("Beyond the end of line.\n");
        return 0;
      }

      else
      {
        printf("The next two codes:\n");
        station = station->next;
        printf("%s\n", station->code);
        station = station->next;
        printf("%s\n", station->code);
        return 0;

      }
    }
    station = station->next;// walk through the node

    if (position == route->num_stations)
    {
      //loop though the whole list
      printf("Code not found in the list!");
    }
  }
}

int main()
{
  FILE *fp;
  fp = fopen("code.txt", "r");
  if (fp == NULL)
  {
    printf("Error reading files!\n");
    return 1;
  }
  Route *route = read_stations(fp); //getting the route information
  
  display(route);                   //displaying the Codes

  char search_code[STATION_CODE_LENGTH];
  printf("Enter code to search: ");
  scanf("%s", search_code);
  search(route, search_code);
  return 0;
}