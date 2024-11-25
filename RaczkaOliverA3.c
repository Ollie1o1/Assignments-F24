#include "givenA3.h"

int readFromFile (char fName [30],
    char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
    char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
    int data [NUMBER_PLAYERS][6]){
    FILE *file = fopen(fName, "r"); 
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

                printf("%s, %s, (Rank %d)\n", playerNames[i], whichCountry, data[i][0]);

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

float avgNumberAcesRanksXToY (int data [NUMBER_PLAYERS][6], int lower, int upper){
     if (lower > upper) {
        return -1; // Return -1 if the range is invalid
    }
    
    int sum = 0;
    int count = 0;

    // Loop through the range of ranks
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        if (data[i][0] >= lower && data[i][0] <= upper) {
            sum += data[i][3]; // Access the 'aces' column (index 3)
            count++;
        }
    }

    return count == 0 ? 0 : (float)sum / count;
}

void printVerticalHistogramMatches (int data [NUMBER_PLAYERS][6]){
    int matches[NUMBER_PLAYERS];
    int minMatches = data[0][4];
    int maxHeight = 0;

    for(int i =0; i < NUMBER_PLAYERS; i++){
        if(data[0][4] < minMatches){
            minMatches = data[i][4];
        }
    }

    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        matches[i] = data[i][4] - (minMatches - 1); // Scale values
        if (matches[i] > maxHeight) {
            maxHeight = matches[i];
        }
    }

    // Step 3: Print the histogram vertically
    for (int height = maxHeight; height > 0; height--) { // Start from max height
        for (int rank = 0; rank < NUMBER_PLAYERS; rank++) {
            if (matches[rank] >= height) {
                printf("* ");
            } else {
                printf(" "); // Empty space for alignment
            }
        }
        printf("\n"); // New line after each row
    }

    // Step 4: Print the x-axis (player ranks)
    for (int rank = 1; rank <= NUMBER_PLAYERS; rank++) {
        printf("%d ", rank);
    }
    printf("\n");
}

void rankTopN (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME], char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
               int data [NUMBER_PLAYERS][6],
               int whichOne,
               int n);
    