#include "givenA3.h"

int readFromFile (char fName [30],
    char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
    char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
    int data [NUMBER_PLAYERS][6]){
    FILE *file = fopen(fName, "data.txt"); 
    // Open the file for reading
    if (!file) {
    return -1; // File not found
    }
                    
    int i = 0;

    while(i < NUMBER_PLAYERS && !feof(file)){
    // \t skip over tabbed areas in the text file
    // one scan for playernames nad one for country names
    // the rest for the data
    fscanf(file, "%49s\t%49s\t%d\t%d\t%d\t%d\t%d\t%d", 
    playerNames[i], countryNames[i], &data[i][0],&data[i][1],
    &data[i][2],&data[i][3],&data[i][4],&data[i][5]);
    i++;
    }
        fclose(file);
        return 1;
}

int howManyFromCountryX (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
    char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
    int data [NUMBER_PLAYERS][6],
    char whichCountry [MAX_LEN_CNAME]){
        
        int count = 0;
        for(int i =0; i < NUMBER_PLAYERS; i++){
            if(strcmp(countryNames[i], whichCountry) == 0){

                printf("%s, %s, (Rank %d)\n", playerNames[i], countryNames[i], data[i][0]);

                count++;
            }
        }

        printf("%s has %d ranked players\n", whichCountry, count);

        return count;
}

int oldOrYoung (int data [NUMBER_PLAYERS][6], int whichOne, int * howMany){
     int targetAge;      // The age of the oldest/youngest player
    *howMany = 0;       // Initialize the count of players
    
    // Initialize targetAge based on the choice
    if (whichOne == 1) { 
        targetAge = data[0][1]; // Assume the first player's age is the oldest
        for (int i = 1; i < NUMBER_PLAYERS; i++) {
            if (data[i][1] > targetAge) {
                targetAge = data[i][1]; // Update oldest age
            }
        }
    } else if (whichOne == 2) { 
        targetAge = data[0][1]; // Assume the first player's age is the youngest
        for (int i = 1; i < NUMBER_PLAYERS; i++) {
            if (data[i][1] < targetAge) {
                targetAge = data[i][1]; // Update youngest age
            }
        }
    } else {
        return -1; // Invalid input
    }
    
    // Count players with the target age
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        if (data[i][1] == targetAge) {
            (*howMany)++;
        }
    }
    
    return targetAge; // Return the target age
}