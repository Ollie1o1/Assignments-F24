#include "givenA3.h"

int main (int argc, char * argv[]) {

    //declare all variables here
    int choice;
    char playerNames[NUMBER_PLAYERS][MAX_LEN_PNAME];
    char countryNames[NUMBER_PLAYERS][MAX_LEN_CNAME];
    int data[NUMBER_PLAYERS][6];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    if (readFromFile(argv[1], playerNames, countryNames, data) == -1) {
        printf("Failed to read data file: %s\n", argv[1]);
        return -1;
    }
    
    do {
       printf ("\nHere is the menu - enter a number between 1 and 6 \n\n");
       printf ("1.   Given a country name, find the total number of players from that country \n");
       printf ("2.   Based on user's choice, find the age and count of the youngest or oldest player (s) \n");
       printf ("3.   Find the average number of aces among players ranked from x to y \n");
       printf ("4.   Print a vertical histogram of the number of matches played \n");
       printf ("5.   Rank the top N players based on the number of aces, double faults or Service Games Won \n");
       printf ("6.   Exit \n");
        
        printf ("Enter your choice: ");
        scanf ("%d", &choice);

        switch (choice) {
            case 1: {
                char country[MAX_LEN_CNAME];
                printf("Enter country name: ");
                scanf("%s", country);
                howManyFromCountryX(playerNames, countryNames, data, country);
                break;
            }
            case 2: {
                int whichOne, howMany;
                printf("Enter 1 for oldest, 2 for youngest: ");
                scanf("%d", &whichOne);
                int age = oldOrYoung(data, whichOne, &howMany);
                printf("Age: %d, Count: %d\n", age, howMany);
                break;
            }
            case 3: {
                int lower, upper;
                printf("Enter lower rank: ");
                scanf("%d", &lower);
                printf("Enter upper rank: ");
                scanf("%d", &upper);
                float avg = avgNumberAcesRanksXToY(data, lower, upper);
                if (avg == -1) {
                    printf("Invalid range.\n");
                } else {
                    printf("Average aces: %.2f\n", avg);
                }
                break;
            }
            case 4:
                printVerticalHistogramMatches(data);
                break;
            case 5:
                printf("This task is incomplete. Please implement `rankTopN`.\n");
                break;
            case 6:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

