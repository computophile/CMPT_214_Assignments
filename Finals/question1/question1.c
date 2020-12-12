/*
# Name: Mohammed Thamidur Rashid
# Class: CMPT-214
# Student Number: 11280257
*/
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

MiningData *read_geosurvey(char FILENAME[30])
{
  /*
  To store and read the mining data from the file to the data structure
  Parameters: FILENAME: Filename where the geosurvey data is stored
  Return: a pointer to a newly-allocated instance of that
  data structure containing the geosurvey data from the file.
  */

  FILE *fp;
  fp = fopen(FILENAME, "r");

  short int rows, columns;
  fscanf(fp, "%hd %hd", &rows, &columns);

  // dynamically allocating the memomory location;
  MiningData *data = (MiningData *)malloc(sizeof(MiningData) * rows * columns);

  for (short int i = 0; i < rows * columns; i++)
  {
    fscanf(fp, "%hd %hd %hd", &data[i].R, &data[i].F, &data[i].M);
    data[i].S = data[i].R + data[i].M + (1.5 * data[i].F); //calculating the value of S
  }
  fclose(fp);
  return data;
}

LocationDetails *camp_location(MiningData *data, char FILENAME[30])
{
  /*
  Function to determine from the geosurvey data the grid location that has
  the optimal suitability measure S ( r, c ) and also optimal M and F locations
  Parameters; *data: Pointer to instance of that data structure containing the  geosurvey data.
              FILENAME: Filename where the geosurvey data is stored
  returns:   details: pointer to the data structure that holds relevant information;
  */
  FILE *fp;
  fp = fopen(FILENAME, "r");

  LocationDetails *details = (LocationDetails *)malloc(sizeof(LocationDetails));

  fscanf(fp, "%hd %hd", &details->rows, &details->columns);

  short int minimum_S = 0;
  short int minimum_F = 0;
  short int minimum_M = 0;

  for (short int i = 0; i < details->rows; i++)
  {
    if (i == 0)
    {
      // initializing the base minimum distance
      minimum_S = data[0].S;
      minimum_F = data[0].F;
      minimum_M = data[0].M;
    }
    // getting the optimal position of R, F, M
    for (short int j = 0; j < details->columns; j++)
    {
      if (data[i * details->rows + j].S < minimum_S)
      {
        minimum_S = data[i * details->rows + j].S; //accessing one dimensional view of a 2D array
        details->location_R[0] = i;
        details->location_R[1] = j;
      }
      if (data[i * details->rows + j].F < minimum_F)
      {
        minimum_F = data[i * details->rows + j].F; //accessing one dimensional view of a 2D array
        details->location_F[0] = i;
        details->location_F[1] = j;
      }
      if (data[i * details->rows + j].M < minimum_M)
      {
        minimum_M = data[i * details->rows + j].M; //accessing one dimensional view of a 2D array
        details->location_M[0] = i;
        details->location_M[1] = j;
      }
    }
  }
  // printf("The location of smallest F: (%hd, %hd)\n", details->location_F[0], details->location_F[1]);
  // printf("The location of smallest M: (%hd, %hd)\n", details->location_M[0], details->location_M[1]);
  printf("The best location for the mining camp is grid coordinate: %hd, %hd.\n", details->location_R[0], details->location_R[1]);
  fclose(fp);
  return details;
}

void print_survey_map(MiningData *data, char FILEOUTPUT[20], LocationDetails *location_details)
{
  /*
  Function to write to the provided filename a visualization of the geosurvey.
    Parameters; *data: Pointer to instance of that data structure containing the  geosurvey data.
                FILEOUTPUT: Filename where the geosurvey data visually output
                details: pointer to the data structure that holds relevant information;
  */
  FILE *fp;
  fp = fopen(FILEOUTPUT, "w");
  for (short int i = 0; i < location_details->rows; i++)
  {
    if (location_details->location_R[0] == i) //river row
    {
      for (short int j = 0; j < location_details->columns; j++)
      { //a camp can appear anywhere
        if (location_details->location_R[0] == i && location_details->location_R[1] == j)
        {
          fprintf(fp, "*");//highest priority
          continue;
        }
        // F and M can be located on a river bank
        if (location_details->location_F[0] == i && location_details->location_F[1] == j)
        {
          fprintf(fp, "F");
          continue;
        }
        if (location_details->location_M[0] == i && location_details->location_M[1] == j)
        {
          fprintf(fp, "M");
          continue;
        }

        fprintf(fp, "=");
      }
    }
    else
    {
      for (short int j = 0; j < location_details->columns; j++)
      {
        //a camp can appear anywhere
        if (location_details->location_R[0] == i && location_details->location_R[1] == j)
        {
          fprintf(fp, "*");//highest priority
          continue;
        }
        if (location_details->location_F[0] == i && location_details->location_F[1] == j)
        {
          fprintf(fp, "F");
          continue;
        }
        if (location_details->location_M[0] == i && location_details->location_M[1] == j)
        {
          fprintf(fp, "M");
          continue;
        }
        else
        {
          fprintf(fp, ".");
        }
      }
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}

void deallocate_geosurvey(MiningData *data, LocationDetails *location_details)
{
  /*
    Function: De allocates the dynamic allocations
    Parameters; *data: Pointer to instance of that data structure containing the  geosurvey data.
                details: pointer to the data structure that holds relevant information;
  */
  free(data);
  free(location_details);
}

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
      printf("Error reading file or not enough permission.\n");
      return 1;
    }
    else
    {
      fclose(fp);
      MiningData *data = read_geosurvey(argv[1]);
      LocationDetails *location_details = camp_location(data, argv[1]);
      print_survey_map(data, argv[2], location_details);
      deallocate_geosurvey(data, location_details);
    }
    return 0;
  }
  else{
    printf("Not enought arguments. Expected 2!\n");
    return 1;
  }
}