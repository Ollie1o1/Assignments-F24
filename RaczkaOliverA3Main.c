#include "givenA3.h"

int main (int argc, char * argv[]) {

    //declare all variables here
    int choice;
    int readFromFile (char fName [30],
                  char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
                  char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
                  int data [NUMBER_PLAYERS][6]);
   
    do {
        printf ("\nHere is the menu - enter a number between 1 and 6 \n\n");
       printf ("1.   Given a country name, find the total number of players from that country \n");
       printf ("2.   Based on user’s choice, find the age and count of the youngest or oldest player (s) \n");
       printf ("3.   Find the average number of aces among players ranked from x to y \n");
       printf ("4.   Print a vertical histogram of the number of matches played \n");
       printf ("5.   Rank the top N players based on the number of aces, double faults or Service Games Won \n");
       printf ("6.   Exit \n");
        
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        if(choice < 1 || choice > 6){
            return;
        }
        else{
            switch (choice) {
            case 1:
                int howManyFromCountryX (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
                         char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
                         int data [NUMBER_PLAYERS][6],
                         char whichCountry [MAX_LEN_CNAME]);
                break;
            case 2:
                
                int oldOrYoung (int data [NUMBER_PLAYERS][6], int whichOne, int * howMany);
                break;
            
            case 3:
                float avgNumberAcesRanksXToY (int data [NUMBER_PLAYERS][6], int lower, int upper);
                break;
            case 4:
                void printVerticalHistogramMatches (int data [NUMBER_PLAYERS][6]);
                break;

            case 5:
                void rankTopN (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
                    char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
                    int data [NUMBER_PLAYERS][6],
                    int whichOne,
                    int n);
                break;
                // and so on, write all other cases
            
            case 6: printf ("Goodbye\n");
              break;
            }
        }
        
       // make sure you add statements to validate the user's choice here - should be a number between 1 and 6
     
    } while (choice != 6);
    
    
   return 0;
}

