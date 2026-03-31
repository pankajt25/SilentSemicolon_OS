#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, pos, faults = 0, hits = 0, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter pages: ");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                hits++;
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found) {
            pos = 0;
            for(j = 1; j < f; j++)
                if(time[j] < time[pos]) pos = j;

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }
    }

    printf("\nPage Faults: %d\n", faults);
    printf("Hits: %d\n", hits);
    printf("Hit Ratio: %.2f\n", (float)hits / n);

    return 0;
}