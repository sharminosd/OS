#include <stdio.h>

int main() {
    // Matrix for storing Process Id, Burst Time, Waiting Time, and Turn Around Time.
    int A[100][4];
    int i, j, n, total = 0, temp;
    float avg_wt, avg_tat;

    printf("Enter number of process: ");
    scanf("%d", &n);

    // User Input Burst Time and allocating Process Id.
    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;  // Process ID
    }

    // Sorting process according to their Burst Time using Bubble Sort
    // to maintain the order for processes with the same burst time.
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (A[j][1] > A[j + 1][1]) {
                // Swap Burst Time
                temp = A[j][1];
                A[j][1] = A[j + 1][1];
                A[j + 1][1] = temp;

                // Swap Process ID
                temp = A[j][0];
                A[j][0] = A[j + 1][0];
                A[j + 1][0] = temp;
            }
        }
    }

    A[0][2] = 0;  // Waiting time for the first process is 0

    // Calculation of Waiting Times
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];
        total += A[i][2];
    }
    avg_wt = (float)total / n;
    total = 0;

    printf("P     BT     WT     TAT\n");
    // Calculation of Turn Around Time and printing the data.
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2];  // Turn Around Time
        total += A[i][3];
        printf("P%d     %d     %d      %d\n", A[i][0], A[i][1], A[i][2], A[i][3]);
    }
    avg_tat = (float)total / n;

    printf("Average Waiting Time= %f", avg_wt);
    printf("\nAverage Turnaround Time= %f", avg_tat);

    return 0;
}
