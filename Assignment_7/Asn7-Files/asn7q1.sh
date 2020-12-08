

# START PROVIDED TO STUDENTS
FILENAME='../music.txt'

# File column numbers (starts at 1 instead of 0)
ENTRY_NUMBER_COL=1
ALBUM_TYPE_COL=2
ALBUM_NAME_COL=3
ARTIST_COL=4
FEAT_ARTIST_COL=5
SONG_NAME_COL=6
GENRE_COL=7
RELEASE_YEAR_COL=8
PREV_URL_COL=9

# Main Music Genres
PUNK="punk"
POP="pop"
INDIE="indie"
ROCK="rock"

# This funciton is a black box.  Under no circumstances are you to edit it.
# Furthermore, it is a black box because if something in this function was not taught to you in the textbook
# or in the background section for this assignment, do not use it.  In otherwords, everything you need is in
# the assignment specifications and textbook.
create_directory_structure() {
    IFS=$'\n'   # input field separator (or internal field separator)
    FILE_GENRES=( `cat $FILENAME | cut -d $'\t' -f $GENRE_COL | sort -u ` )
    
    for GENRE in ${FILE_GENRES[@]}; do 
        if [[ $GENRE == "Genre" ]]; then
            continue
        fi

        IFS=' '
        read -ra GENRE_SPLIT <<< $GENRE
        GENRE=`echo "$GENRE" | tr ' ' '-' `
        COUNT=1
        FOUND=1
        NUM_SPLIT="${#GENRE_SPLIT[@]}"

        for SPLIT in ${GENRE_SPLIT[@]}; do
            if [[ $SPLIT == *$INDIE* ]] && [[ ${GENRE_SPLIT[*]} != $INDIE ]]; then
                PARENT_GENRE=$INDIE
            elif [[ $SPLIT == *$PUNK* ]] && [[ ${GENRE_SPLIT[*]} != $PUNK ]]; then
                PARENT_GENRE=$PUNK
            elif [[ $SPLIT == *$POP* ]] && [[ ${GENRE_SPLIT[*]} != $POP ]]; then
                PARENT_GENRE=$POP
            elif [[ $SPLIT == *$ROCK* ]] && [[ ${GENRE_SPLIT[*]} != $ROCK ]]; then
                PARENT_GENRE=$ROCK
            else
                if [ "$GENRE" = "None" ]; then
                    mkdir -p "uncategorized"
                    break
                elif [[ $FOUND -eq 0 ]]; then   
                    if [[ $COUNT -eq $NUM_SPLIT ]]; then                        
                        break
                    fi
                    
                    (( COUNT+=1 ))
                    continue
                elif [ $COUNT -ne $NUM_SPLIT ] && [ $FOUND -eq 1 ]; then
                    (( COUNT+=1 ))
                    continue
                else
                    mkdir -p "${GENRE}"
                    continue
                fi
            fi

            mkdir -p "${PARENT_GENRE}/${GENRE}"
            FOUND=0
            (( COUNT+=1 ))
        done
    done
}
# END PROVIDED TO STUDENTS

# TODO: everything after this point