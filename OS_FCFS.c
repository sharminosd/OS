#include<stdio.h>
void findWT(int process[],int n,int bt[],int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]= bt[i-1] + wt[i-1] ;
    }
}
void findTAT(int process[],int n,int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
void AVG(int process[],int n,int bt[])
{
    int wt[n],tat[n],total_wt=0,total_tat=0;
    findWT(process,n, bt, wt);
    findTAT(process,n, bt, wt, tat);
    printf("Processes   Burst time   Waiting time   Turn around time\n");
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("       %d ", bt[i] );
        printf("           %d",wt[i] );
        printf("               %d\n", tat[i] );
    }
    float s=total_wt / n;
    float t=total_tat / n;
    printf("Average waiting time = %.2f",s);
    printf("\n");
    printf("Average turn around time = %.2f ",t);
}
int main() {
    int n;

    // Asking the user for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare arrays for process IDs and burst times
    int process[n], bt[n];

    // Taking user input for process IDs
    printf("Enter the process IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d ID: ", i + 1);
        scanf("%d", &process[i]);
    }

    // Taking user input for burst times
    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", process[i]);
        scanf("%d", &bt[i]);
    }

    // Call the function to calculate average time
    AVG(process, n, bt);
    return 0;
}
