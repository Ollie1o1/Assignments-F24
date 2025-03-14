#include "../include/givenA3.h"
#include <stdlib.h>

void deletePlayList(A3Song **headLL) {
    A3Song *current = *headLL;
    while (current != NULL) {
        A3Song *temp = current;
        current = current->nextSong;
        free(temp);
    }
    *headLL = NULL;
}