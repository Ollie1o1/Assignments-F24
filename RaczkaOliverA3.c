#include "givenA3.h"

int readFromFile (char fName [30],
    char playerNames[NUMBER_PLAYERS][MAX_LEN_PNAME],
    char countryNames[NUMBER_PLAYERS][MAX_LEN_CNAME],
    int data[NUMBER_PLAYERS][6]) {

   FILE *file = fopen(fName, "r");
    if (!file) {
        return -1; // File not found
    }

    int i = 0;
    while (i < NUMBER_PLAYERS && fscanf(file, "%49[^\t]\t%49[^\t]\t%d\t%d\t%d\t%d\t%d\t%d\n", 
        playerNames[i], countryNames[i], &data[i][0], &data[i][1], &data[i][2],
        &data[i][3], &data[i][4], &data[i][5]) == 8) {

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

    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        // Compare the country names
        if (strcmp(countryNames[i], whichCountry) == 0) {
            // If a match is found, print the player's name and rank
            printf("%s, %s (Rank %d)\n", playerNames[i], countryNames[i], data[i][0]);
            count++;
        }
    }

    // Print the final count of players from the given country
    printf("\n%s has %d ranked players\n", whichCountry, count);
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

void printVerticalHistogramMatches(int data[NUMBER_PLAYERS][6]) {
    int matches[NUMBER_PLAYERS];
    int maxHeight = 0;

    // Calculate normalized matches and find max height
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        matches[i] = data[i][2] - 21;
        if (matches[i] > maxHeight) {
            maxHeight = matches[i];
        }
    }

    // Print the original number of matches played
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        printf("%2d ", data[i][2]);
    }
    printf("\n\n\n");
    

    // Print the histogram
    for (int height = maxHeight; height > 0; height--) {
        for (int i = 0; i < NUMBER_PLAYERS; i++) {
            if (matches[i] >= height) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    // Print player ranks
    for (int i = 1; i <= NUMBER_PLAYERS; i++) {
        printf("%2d ", i);
    }
    printf("\n");
}

void rankTopN (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME], char countryNames[NUMBER_PLAYERS][MAX_LEN_CNAME],
               int data [NUMBER_PLAYERS][6],
               int whichOne,
               int n){
      // Array to store player indices for sorting
    int indices[NUMBER_PLAYERS];
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        indices[i] = i;  // Initialize with player indices
    }

    // Sort indices based on the specified criteria
    for (int i = 0; i < NUMBER_PLAYERS - 1; i++) {
        for (int j = i + 1; j < NUMBER_PLAYERS; j++) {
            int value1 = data[indices[i]][whichOne + 2]; // Adjust index for criteria
            int value2 = data[indices[j]][whichOne + 2];
            if (value1 < value2) { // Sort in descending order
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Print the top N players
    printf("Top %d players ranked on ", n);
    switch (whichOne) {
        case 1:
            printf("Aces\n");
            break;
        case 2:
            printf("Double Faults\n");
            break;
        case 3:
            printf("Service Games Won\n");
            break;
        default:
            printf("Invalid criteria.\n");
            return;
    }

    for (int i = 0; i < n && i < NUMBER_PLAYERS; i++) {
        int idx = indices[i];
        printf("%s, %s, %d (Rank %d)\n",
               playerNames[idx],
               countryNames[idx],
               data[idx][whichOne + 2],  // Adjust index for criteria
               data[idx][0]);           // Rank from data array
    }
}
    