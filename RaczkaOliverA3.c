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

        // Debugging: Print the data to verify it's being read correctly
        printf("Read Player: %s, Country: %s, Rank: %d\n", playerNames[i], countryNames[i], data[i][0]);
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
            printf("%s, %s, (Rank %d)\n", playerNames[i], countryNames[i], data[i][2]);
            count++;
        }
    }

    // Print the final count of players from the given country
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
    int minMatches = data[0][2];  // Initialize minMatches to the first player's matches played
    int maxHeight = 0;

    // Find the minimum number of matches played (for scaling)
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        if (data[i][2] < minMatches) {
            minMatches = data[i][2];
        }
    }

    // Subtract 21 from each player's matches played and find the maximum height for the histogram
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        matches[i] = data[i][2] - 21;  // Normalize by subtracting 21
        if (matches[i] > maxHeight) {
            maxHeight = matches[i];  // Find the maximum height for scaling
        }
    }

    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        printf("%-3d ", data[i][2]);  // Print the original number of matches played with proper alignment
    }
    printf("\n");

    // Print the histogram vertically
    for (int height = maxHeight; height > 0; height--) { // Start from max height
        for (int i = 0; i < NUMBER_PLAYERS; i++) {
            if (matches[i] >= height) {
                printf("* ");  // Print a star if the player's normalized matches >= height
            } else {
                printf("  ");  // Print space if the player's normalized matches < height
            }
        }
        printf("\n");  // New line after each row
    }

    
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        printf("%-3d ", i + 1);  // Print player ranks with proper alignment
    }
    printf("\n");
}

void rankTopN (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME], char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
               int data [NUMBER_PLAYERS][6],
               int whichOne,
               int n){
    struct Player {
        char name[MAX_LEN_PNAME];
        char country[MAX_LEN_CNAME];
        int aces;
        int doubleFaults;
        int serviceGamesWon;
        int rank;
    };

    struct Player players[NUMBER_PLAYERS];

    // Populate the players array with data from the arrays
    for (int i = 0; i < NUMBER_PLAYERS; i++) {
        strncpy(players[i].name, playerNames[i], MAX_LEN_PNAME);
        strncpy(players[i].country, countryNames[i], MAX_LEN_CNAME);
        players[i].aces = data[i][0];
        players[i].doubleFaults = data[i][1];
        players[i].serviceGamesWon = data[i][2];
        players[i].rank = data[i][3];  // Rank is assumed to be in data[i][3]
    }

    // Sort the players array based on the chosen criteria (1 for aces, 2 for double faults, 3 for service games won)
    for (int i = 0; i < NUMBER_PLAYERS - 1; i++) {
        for (int j = i + 1; j < NUMBER_PLAYERS; j++) {
            int compare = 0;

            switch (whichOne) {
                case 1:
                    compare = players[i].aces - players[j].aces;
                    break;
                case 2:
                    compare = players[i].doubleFaults - players[j].doubleFaults;
                    break;
                case 3:
                    compare = players[i].serviceGamesWon - players[j].serviceGamesWon;
                    break;
                default:
                    printf("Invalid choice for ranking criteria.\n");
                    return;
            }

            // Swap players if the current player has a lower value for the selected criterion
            if (compare < 0) {
                struct Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    // Print the top N players based on the selected criteria
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
            printf("Invalid choice\n");
            return;
    }

    // Print the top N players
    for (int i = 0; i < n; i++) {
        printf("%s, %s, %d (Rank %d)\n", players[i].name, players[i].country, 
               (whichOne == 1) ? players[i].aces : (whichOne == 2) ? players[i].doubleFaults : players[i].serviceGamesWon, 
               players[i].rank);
    }
}
    