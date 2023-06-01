#include <stdio.h>
#include <math.h>

int main() {
    int seats, votes, lists, i;
    printf("Total number of seats: ");
    scanf("%d", &seats);
    printf("Total number of votes: ");
    scanf("%d", &votes);
    printf("Total number of lists: ");
    scanf("%d", &lists);

    int votesPerList[lists];
    int automaticSeats[lists];
    int remainder[lists];
    int totalAutomaticSeats = 0;

    for (i = 0; i < lists; i++) {
        printf("Votes for list %d: ", i+1);
        scanf("%d", &votesPerList[i]);
        automaticSeats[i] = votesPerList[i] / seats;
        remainder[i] = votesPerList[i] % seats;
        totalAutomaticSeats += automaticSeats[i];
        printf("Automatic seat for list %d: %d\n", i+1, automaticSeats[i]);
        printf("Remainder for list %d: %d\n", i+1, remainder[i]);
    }

    int remainingSeats = seats - totalAutomaticSeats;
    while (remainingSeats > 0) {
        int maxRemainderIndex = -1;
        int maxRemainder = -1;
        for (i = 0; i < lists; i++) {
            if (remainder[i] > maxRemainder) {
                maxRemainderIndex = i;
                maxRemainder = remainder[i];
            }
        }
        if (maxRemainderIndex == -1) {
            // No more seats to allocate
            break;
        }
        automaticSeats[maxRemainderIndex]++;
        remainder[maxRemainderIndex] = votesPerList[maxRemainderIndex] % seats;
        remainingSeats--;
        printf("Automatic seat for list %d: %d\n", maxRemainderIndex+1, automaticSeats[maxRemainderIndex]);
        printf("Remainder for list %d: %d\n", maxRemainderIndex+1, remainder[maxRemainderIndex]);
    }

    return 0;
}
