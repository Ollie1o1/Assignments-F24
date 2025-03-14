#include "../include/givenA3.h"
#include <stdio.h>

int playSongGivenId(A3Song *headLL, int givenSongId) {
    A3Song *current = headLL;
    while (current != NULL) {
        if (current->songId == givenSongId) {
            printf("Song ID: %d\n", current->songId);
            printf("Song Name: %s\n", current->songName);
            printf("Notes: ");
            for (int i = 0; i < 21; i++) {
                printf("%s.", current->songNotes[i]);
            }
            printf("\n");
            return 1;
        }
        current = current->nextSong;
    }
    return -1;
}