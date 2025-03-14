#include "../include/givenA3.h"
#include <stdlib.h>

int deleteASongGivenId(A3Song **headLL, int givenSongId) {
    A3Song *current = *headLL;
    A3Song *prev = NULL;

    while (current != NULL) {
        if (current->songId == givenSongId) {
            if (prev == NULL) {
                *headLL = current->nextSong;
            } else {
                prev->nextSong = current->nextSong;
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->nextSong;
    }
    return -1;
}