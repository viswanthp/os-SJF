#include<stdio.h>
int main()
{
    int bt[20],at[20],pa[20],pb[20],wt[20],tat[20],i,j,n,total=0,posa,tempa,posb,tempb;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
    
    printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("pa%d:",i+1);
        scanf("%d",&at[i]);
        pa[i]=i+1;           //contains process number for Arrival Time
    }
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("pb%d:",i+1);
        scanf("%d",&bt[i]);
        pb[i]=i+1;           //contains process number for Burst Time
    }
     //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        posb=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[posb])
                posb=j;
        }
 
        tempb=bt[i];
        bt[i]=bt[posb];
        bt[posb]=tempb;
 
        tempb=pb[i];
        pb[i]=pb[posb];
        pb[posb]=tempb;
    }
    //sorting Arrival time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        posa=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[posa])
                posa=j;
        }
 
        tempa=at[i];
        at[i]=at[posa];
        at[posa]=tempa;
 
        tempa=pa[i];
        pa[i]=pa[posa];
        pa[posa]=tempa;
    }
    
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //calculate average waiting time
    total=0;
 
    printf("\n\nProcess A     Arrival time");
    for(i=0;i<n;i++)
    {
    	printf("\npa%d             %d",pa[i],at[i]);
	}
    printf("\n\nProcess B   Burst Time       Waiting Time     Turnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\npb%d          %d                    %d               %d",pb[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
