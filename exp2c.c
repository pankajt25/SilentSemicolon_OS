#include <stdio.h>

int main() {
    int n, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], rt[n], ct[n];

    for(int i = 0; i < n; i++) {
        printf("P%d AT BT Priority: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(completed < n) {
        int idx = -1, high = 9999;

        for(int i = 0; i < n; i++)
            if(at[i] <= time && rt[i] > 0 && pr[i] < high) {
                high = pr[i];
                idx = i;
            }

        if(idx != -1) {
            rt[idx]--;
            time++;

            if(rt[idx] == 0) {
                ct[idx] = time;
                completed++;
            }
        } else {
            time++;
        }
    }

    float wt = 0, tat = 0;

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        int TAT = ct[i] - at[i];
        int WT = TAT - bt[i];
        tat += TAT;
        wt += WT;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], TAT, WT);
    }

    printf("\nAverage TAT = %.2f", tat/n);
    printf("\nAverage WT = %.2f\n", wt/n);

    return 0;
}
