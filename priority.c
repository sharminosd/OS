#include <stdio.h>

// Function to calculate waiting time
void calculateWaitingTime(int n, int burstTime[], int waitingTime[]) {
    waitingTime[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
    }
}

// Function to calculate turnaround time
void calculateTurnaroundTime(int n, int burstTime[], int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

// Function to perform priority scheduling
void priorityScheduling(int processes[], int n, int burstTime[], int priority[]) {
    // Sorting processes based on priority (descending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] < priority[j]) {
                // Swap priority
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                // Swap burst time
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
                // Swap process IDs
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Arrays for waiting and turnaround times
    int waitingTime[n], turnaroundTime[n];

    // Calculate waiting time and turnaround time
    calculateWaitingTime(n, burstTime, waitingTime);
    calculateTurnaroundTime(n, burstTime, waitingTime, turnaroundTime);

    // Print results
    printf("\nProcesses  Burst Time  Priority  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("   %d           %d        %d          %d               %d\n",
               processes[i], burstTime[i], priority[i], waitingTime[i], turnaroundTime[i]);
    }

    // Calculate average waiting time and turnaround time
    float avgWT = 0, avgTAT = 0;
    for (int i = 0; i < n; i++) {
        avgWT += waitingTime[i];
        avgTAT += turnaroundTime[i];
    }
    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);
}

int main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], priority[n];

    // Input burst time and priority for each process
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Process IDs
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    // Call the priority scheduling function
    priorityScheduling(processes, n, burstTime, priority);

    return 0;
}

