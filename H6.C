#include<stdio.h>
int main(){
    int pid[15];
    int bt[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the process id of all processes:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&pid[i]);
    }
    printf("Enter the burst time of all processes:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    int i=0,wt[n];
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float twt=0.0,tat=0.0;
    for(i=0;i<n;i++){
        printf("%d\t",pid[i]);
        printf("%d\t",bt[i]);
        printf("%d\t",wt[i]);
        printf("%d\t",wt[i]+bt[i]);
        printf("\n");
        twt+=wt[i];
        tat+=(wt[i]+bt[i]);
    }
    float att,awt;
    awt=twt/n;
    att=tat/n;
    printf("Average Waiting Time: %f\n",awt);
    printf("Average Turnaround Time: %f\n",att);
    return 0;
}
