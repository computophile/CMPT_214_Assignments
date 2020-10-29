/*
Name: Mohammed Thamidur Rashid
NSID: 11280257
Subject: CMPT 214
*/

#include <stdio.h>

#define STATION_CODE_LENGTH 4

typedef struct _station
{
  char code[STATION_CODE_LENGTH];
  struct _station *next;
} Station;

typedef struct _route
{
  Station *first_station;
  unsigned int num_stations;
} Route;

Route *read_stations(FILE *fp)
{
  // read the firs line
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

    while (fscanf(fp, "%s", city_code)!=EOF)
    {
      // ;
      // if (feof(fp)){
      //   break;// break if we have reached the end of the file!
      // }
      if (city_code == "\n" || city_code == "\0"){
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
void display(Route *route){
  
  Station *station = route->first_station;
  while (station != NULL)
  {
    printf("%s\n", station->code);
    station = station->next;
  }
}

int search(Route *route, char search_code[STATION_CODE_LENGTH])
{
  Station *station = route->first_station;
  int position = 0;
  while (station != NULL)
  {
    ++position;

    if (strcmp(station->code, search_code) == 0)
    {
      printf("Code position: %d\n", position);

      if (position == route->num_stations - 1)
      {
        printf("The next two codes:\n");
        station = station->next;
        printf("%s\n", station->code);
        printf("Beyond the end of line.\n");
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
      }
    }
    station = station->next;

    if (position == route -> num_stations && station -> next == NULL){
        printf("Code not found in the list!");
    }
  }


}

int main()
{
  FILE *fp;
  fp = fopen("code.txt", "r");
  Route *route = read_stations(fp);
  display(route);

  char search_code[STATION_CODE_LENGTH];
  printf("Enter code to search: ");
  scanf("%s", search_code);
  search(route, search_code);
  return 0;
}