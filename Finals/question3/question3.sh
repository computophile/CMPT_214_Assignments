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

GENRE=${GENRE,,}

if [ "$GENRE" = "indie" ] || [ "$GENRE" = "hip-hop" ] || [ "$GENRE" = "metal" ] || [ "$GENRE" = "pop" ] || [ "$GENRE" = "punk" ] || [ "$GENRE" = "rap" ] || [ "$GENRE" = "rock" ]; then
  cd $GENRE
  mkdir $GENRE
  echo *$GENRE* | tr " " "\n"
  rmdir $GENRE

  echo "---------------------------------------------"
  read -p "Select a sub - genre from above: " SUB_GENRE
  echo "---------------------------------------------"
  SUB_GENRE=${SUB_GENRE,,}
  touch ../../"${SUB_GENRE}_artists.txt"
  if [ "$SUB_GENRE" = "$GENRE" ]; then
    ls | grep -v "${GENRE}" >../../"${SUB_GENRE}_artists.txt"
    echo "The total number of artists in the genre ${GENRE}/${SUB_GENRE} were: $(wc -l < ../../"${GENRE}_artists.txt")"
  else
    cd ${SUB_GENRE}
    ls > ../../../"${SUB_GENRE}_artists.txt"
    echo "The total number of artists in the genre ${GENRE}/${SUB_GENRE} were: $(wc -l <../../../"${SUB_GENRE}_artists.txt")"
  fi
  # create a new file in the same directory as question3.sh
else
  cd $GENRE
  touch ../../"${GENRE}_artists.txt"
  ls >../../"${GENRE}_artists.txt"
  echo "The total number of artists in the genre ${GENRE} were: $(wc -l <../../"${GENRE}_artists.txt")"
fi