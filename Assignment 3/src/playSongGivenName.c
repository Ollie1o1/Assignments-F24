#include "../include/givenA3.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h> // For tolower()

// Helper function to convert a string to lowercase
void toLowerString(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int playSongGivenName(A3Song *headLL, char givenSongName[MAX_LENGTH]) {
    A3Song *current = headLL;
    char lowerGivenName[MAX_LENGTH];
    char lowerCurrentName[MAX_LENGTH];

    // Convert input name to lowercase
    strcpy(lowerGivenName, givenSongName);
    toLowerString(lowerGivenName);

    while (current != NULL) {
        // Convert current song name to lowercase
        strcpy(lowerCurrentName, current->songName);
        toLowerString(lowerCurrentName);

        // Compare lowercase names
        if (strcmp(lowerCurrentName, lowerGivenName) == 0) {
            printf("Song ID: %d\n", current->songId);
            printf("Song Name: %s\n", current->songName);
            printf("Notes: ");
            for (int i = 0; i < 21; i++) {
                printf("%s", current->songNotes[i]);
                if (i < 20) {
                    printf(".");
                }
            }
            printf("\n");
            return 1; // Found
        }
        current = current->nextSong;
    }
    return -1; // Not found
}