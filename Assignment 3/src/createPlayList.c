#include "../include/givenA3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return -1; // File not found
    }

    char line[500];
    int numSongs = 0;

    // Skip header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        A3Song *newSong = malloc(sizeof(A3Song));
        if (newSong == NULL) {
            fclose(file);
            return numSongs; // Partial load
        }

        // Parse CSV line
        char *token = strtok(line, ",");
        strcpy(newSong->songName, token);

        // Generate songId: strlen(name) + random 1-1000
        newSong->songId = strlen(newSong->songName) + (rand() % 1000 + 1);

        // Parse 21 notes
        for (int i = 0; i < 21; i++) {
            token = strtok(NULL, ",\r\n");
            if (token) {
                strcpy(newSong->songNotes[i], token);
            }
        }

        // Insert at BEGINNING of list
        newSong->nextSong = *headLL;
        *headLL = newSong;
        numSongs++;
    }

    fclose(file);
    return numSongs;
}