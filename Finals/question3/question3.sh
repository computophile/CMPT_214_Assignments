#!/bin/bash

# Name: Mohammed Thamidur Rashid
# Class: CMPT-214
# Student Number: 11280257

# going to the music directory

# going into the music directory
cd ./music
ls

echo "---------------------------------------------"
read -p "Select a genre from the above: " GENRE
echo "---------------------------------------------"

GENRE=${GENRE,,} #converting GENRE to lowercase

if [ "$GENRE" = "indie" ] || [ "$GENRE" = "hip-hop" ] || [ "$GENRE" = "metal" ] || [ "$GENRE" = "pop" ] || [ "$GENRE" = "punk" ] || [ "$GENRE" = "rap" ] || [ "$GENRE" = "rock" ]; then
  
  cd $GENRE
  mkdir $GENRE #make a directory in the name of the genre to show up as option
  echo *$GENRE* | tr " " "\n" #print the sub-directories to the console
  rmdir $GENRE #remove the directory as it is not longer required after it is echoed

  echo "---------------------------------------------"
  read -p "Select a sub - genre from above: " SUB_GENRE
  echo "---------------------------------------------"

  SUB_GENRE=${SUB_GENRE,,} #convert SUB_GENRE to lowercase

  touch ../../"${SUB_GENRE}_artists.txt" #create text file in the question3.sh directory
  
  if [ "$SUB_GENRE" = "$GENRE" ]; then
    ls | grep -v "${GENRE}" >../../"${SUB_GENRE}_artists.txt" #write to the created text file the name of the artists only
    echo "The total number of artists in the genre ${GENRE}/${SUB_GENRE} were: $(wc -l < ../../"${GENRE}_artists.txt")"
  else
    cd ${SUB_GENRE}
    ls > ../../../"${SUB_GENRE}_artists.txt" #write to the created text file the name of the artists only
    echo "The total number of artists in the genre ${GENRE}/${SUB_GENRE} were: $(wc -l <../../../"${SUB_GENRE}_artists.txt")"
  fi
  # create a new file in the same directory as question3.sh


else #normal directories that don't have sub-directories
  cd $GENRE
  touch ../../"${GENRE}_artists.txt" #create text file in the question3.sh directory
  ls >../../"${GENRE}_artists.txt" #write to the created text file the name of the artists in the genre
  echo "The total number of artists in the genre ${GENRE} were: $(wc -l <../../"${GENRE}_artists.txt")"
fi