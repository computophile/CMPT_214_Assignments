#include <stdio.h>
#include <stdlib.h>

typedef struct mining_data
{
  short int R, F, M, S;
  // R is the shortest distance from grid location (r,c) to the river
  // M ins the shortest distance from grid location (r,c) to the nearest mine
  // F is the distance from the grid location (r,c) to the factory
  // The best location for the minig camp is the grid location (r,c) that minimizes S(r,c)
} MiningData;

typedef struct location_details
{
  short int rows, columns; //total numbers of rows and columns in the grid
  short int location_R[2]; //location of R(r,c)
  short int location_F[2]; //location of F(r,c)
  short int location_M[2]; //location of M(r,c)
} LocationDetails;

MiningData *read_geosurvey(FILE *fp)
{
  /*
  To store and read the mining data from the file to the data structure
  Parameters: FILE *fp : Pointer to the file where the relevant data is stored;
  Return: a pointer to a newly-allocated instance of that
  data structure containing the geosurvey data from the file.
  */
  short int rows, columns;
  fscanf(fp, "%hd %hd", &rows, &columns);

  // dynamically allocating the memomory location;
  MiningData *data = (MiningData *)malloc(sizeof(MiningData) * rows * columns);

  for (size_t i = 0; i < rows * columns; i++)
  {
    fscanf(fp, "%hd %hd %hd", &data[i].R, &data[i].F, &data[i].M);
    data[i].S = data[i].R + data[i].M + (1.5 * data[i].F); //calculating the value of S
  }
  return data;
}

LocationDetails *camp_location(MiningData *data, FILE *fp)
{
  /*
  Function to determine from the geosurvey data the grid location that has
  the optimal suitability measure S ( r, c )
  Parameters; *data: Pointer to instance of that data structure containing the  geosurvey data.
              *fp: pointer to the file where the relevant data is stored;
  returns:   details: pointer to the data structure that holds relevant information;
  */
  rewind(fp);

  LocationDetails *details = (LocationDetails *)malloc(sizeof(LocationDetails));

  fscanf(fp, "%hd %hd", &details->rows, &details->columns);

  short int minimum_S = 0;
  short int minimum_F = 0;
  short int minimum_M = 0;

  for (size_t i = 0; i < details->rows; i++)
  {
    if (i == 0)
    {
      // initializing the base minimum distance
      minimum_S = data[0].S;
      minimum_F = data[0].F;
      minimum_M = data[0].M;
    }
    for (size_t j = 0; j < details->columns; j++)
    {
      // printf("(%ld, %ld): %hd ", i, j, data[i * rows + j].S);
      if (data[i * details->rows + j].S < minimum_S)
      {
        minimum_S = data[i * details->rows + j].S;
        details->location_R[0] = i;
        details->location_R[1] = j;
      }
      if (data[i * details->rows + j].F < minimum_F)
      {
        minimum_F = data[i * details->rows + j].F;
        details->location_F[0] = i;
        details->location_F[1] = j;
      }
      if (data[i * details->rows + j].M < minimum_M)
      {
        minimum_M = data[i * details->rows + j].M;
        details->location_M[0] = i;
        details->location_M[1] = j;
      }
    }
  }
  printf("The location of smallest F: (%hd, %hd)\n", details->location_F[0], details->location_F[1]);
  printf("The location of smallest M: (%hd, %hd)\n", details->location_M[0], details->location_M[1]);
  printf("The location of smallest S: (%hd, %hd)\n", details->location_R[0], details->location_R[1]);

  return details;
}

void print_survey_map(MiningData *data, char FILEOUTPUT[20], LocationDetails *location_details)
{
  // write to this file;
  FILE *fp;
  fp = fopen(FILEOUTPUT, "w");
  for (size_t i = 0; i < location_details->rows; i++)
  {
    if (location_details->location_R[0] == i)
    {
      for (size_t j = 0; j < location_details->columns; j++)
      {
        if (location_details->location_R[0] == i && location_details->location_R[1] == j)
        {
          fprintf(fp, "*");
          printf("*");
        }
        else
        {
          fprintf(fp, "=");
          printf("=");
        }
      }
    }
    else
    {
      for (size_t j = 0; j < location_details->columns; j++)
      {
        if (location_details->location_F[0] == i && location_details->location_F[1] == j)
        {
          fprintf(fp, "F");
          printf("F");
          continue;
        }
        if (location_details->location_M[0] == i && location_details->location_M[1] == j)
        {
          fprintf(fp, "M");
          printf("M");
          continue;
        }
        else
        {
          fprintf(fp, ".");
          printf(".");
        }
      }
    }
    fprintf(fp, "\n");
    printf("\n");
  }
  fclose(fp);
}

void deallocate_geosurvey(MiningData *data, LocationDetails *location_details)
{
  free(data);
  free(location_details);
}

int main(int argc, char *argv[])
{
  FILE *fp;
  fp = fopen("candy-geosurvey-small.txt", "r");
  if (fp != NULL)
  {
    MiningData *data = read_geosurvey(fp);
    LocationDetails *location_details = camp_location(data, fp);
    print_survey_map(data, "river_output.txt", location_details);
    deallocate_geosurvey(data, location_details);
  }
  fclose(fp);
  return 0;
}