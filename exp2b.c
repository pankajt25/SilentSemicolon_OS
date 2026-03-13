#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n];

    for(int i = 0; i < n; i++) {
        printf("P%d Arrival & Burst Time: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;

    while(completed < n) {
        int executed = 0;

        for(int i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                executed = 1;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if(!executed) time++;
    }

    float totalWT = 0, totalTAT = 0;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        int tat = ct[i] - at[i];
        int wt = tat - bt[i];
        totalTAT += tat;
        totalWT += wt;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat, wt);
    }

    printf("\nAverage TAT = %.2f", totalTAT/n);
    printf("\nAverage WT = %.2f\n", totalWT/n);

    return 0;
}
