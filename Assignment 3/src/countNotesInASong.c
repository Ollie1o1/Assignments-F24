#include "../include/givenA3.h"
#include <string.h>

int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4]) {
    A3Song *current = headLL;
    while (current != NULL) {
        if (current->songId == givenSongId) {
            int count = 0;
            for (int i = 0; i < 21; i++) {
                if (strcmp(current->songNotes[i], whichNote) == 0) {
                    count++;
                }
            }
            return count;
        }
        current = current->nextSong;
    }
    return -1;
}