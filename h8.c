#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst[n], priority[n], index[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &priority[i]);
        index[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (priority[j] < priority[m]) {
                m = j;
            }
        }
        if (m != i) {
            swap(&priority[i], &priority[m]);
            swap(&burst[i], &burst[m]);
            swap(&index[i], &index[m]);
        }
    }

    int t = 0;
    printf("Order of execution of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d is executed from %d to %d\n", index[i], t, t + burst[i]);
        t += burst[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int totalWait = 0;
    int totalTurnaround = 0;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        int waiting = currentTime;
        int turnaround = waiting + burst[i];

        printf("P%d\t%d\t%d\t%d\n", index[i], burst[i], waiting, turnaround);

        totalWait += waiting;
        totalTurnaround += turnaround;
        currentTime += burst[i];
    }

    float avgWait = (float) totalWait / n;
    float avgTurnaround = (float) totalTurnaround / n;

    printf("\nAverage waiting time: %.2f\n", avgWait);
    printf("Average turnaround time: %.2f\n", avgTurnaround);

    return 0;
}