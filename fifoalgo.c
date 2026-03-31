#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, hit, faults = 0, hits = 0, index = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) 
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) 
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                hits++;
                hit = 1;
                break;
            }
        }

        if(!hit) {
            frames[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }
    }

    printf("\nPage Faults: %d\n", faults);
    printf("Hits: %d\n", hits);
    printf("Hit Ratio: %.2f\n", (float)hits / n);

    return 0;
}