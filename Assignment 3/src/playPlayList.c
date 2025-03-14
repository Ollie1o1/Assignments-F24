#include "../include/givenA3.h"
#include <stdio.h>

void playPlayList(A3Song *headLL) {
    A3Song *current = headLL;
    while (current != NULL) {
        printf("Song ID: %d\n", current->songId);
        printf("Song Name: %s\n", current->songName);
        printf("Notes: ");
        for (int i = 0; i < 21; i++) {
            printf("%s.", current->songNotes[i]);
        }
        printf("\n\n");
        current = current->nextSong;
    }
}