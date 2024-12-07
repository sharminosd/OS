#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]) {
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n; i++) {
        // Add burst time of previous processes
        service_time[i] = service_time[i - 1] + bt[i - 1];

        // Find waiting time for current process = service_time[i] - at[i]
        wt[i] = service_time[i] - at[i];

        // If waiting time for a process is in negative, make it zero
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average waiting and turn-around times
void findavgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, at);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    printf("Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        int compl_time = tat[i] + at[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], wt[i], tat[i], compl_time);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turn around time = %.2f\n", (float)total_tat / n);
}

// Driver code
int main() {
    int n;

    // Asking the user for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare arrays for process IDs and burst times
    int processes[n], burst_time[n],arrival_time[n];

    // Taking user input for process IDs
    printf("Enter the process IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d ID: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Taking user input for burst times
    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", processes[i]);
        scanf("%d", &burst_time[i]);
    }
    printf("Enter the arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival time for process %d: ", processes[i]);
        scanf("%d", &arrival_time[i]);
    }

    // Call the function to calculate average time
    findavgTime(processes, n, burst_time, arrival_time);
    return 0;
}


