#include <stdio.h>
#include <string.h>

#define NUMBER_PLAYERS 30
#define MAX_LEN_PNAME 50
#define MAX_LEN_CNAME 10

/* Task 1 */
int readFromFile (char fName [30],
                  char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
                  char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
                  int data [NUMBER_PLAYERS][6]);

/* Task 2 */
int howManyFromCountryX (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
                         char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
                         int data [NUMBER_PLAYERS][6],
                         char whichCountry [MAX_LEN_CNAME]);

/* Task 3 */
int oldOrYoung (int data [NUMBER_PLAYERS][6],
                int whichOne,
                int * howMany);

/* Task 4 */
float avgNumberAcesRanksXToY (int data [NUMBER_PLAYERS][6],
                              int lower,
                              int upper);

/* Task 5 */
void printVerticalHistogramMatches (int data [NUMBER_PLAYERS][6]);

/* Task 6 */
void rankTopN (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
               char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
               int data [NUMBER_PLAYERS][6],
               int whichOne,
               int n);

// extra function

