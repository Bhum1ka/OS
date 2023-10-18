#include<stdio.h>
main()
{
	int i,bt[20],wt[20],tat[20],k,n,temp,p[20],pri[20];
	float wtavg,tatavg;
	printf("Enter the number of processes--",n);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Burst Time & Priority of the process%d--",i+1);
		scanf("%d %d",&bt[i],&pri[i]);
		p[i]=i;
	}
	for(i=0;i<n;i++){
		for(k=i+1;k<n;k++){
			if(pri[i]>pri[k]){
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				temp=pri[i];
				pri[i]=pri[k];
				pri[k]=temp;
			}
		}
	}
	wt[0]=wtavg=0;
	tat[0]=tatavg=bt[0];
	for(i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg+tat[i];
	}
	printf("\tPROCESS \t BURST TIME \t PRIORITY \t WAITING TIME \t TURNAROUND TIME\n");
	for(i=0;i<n;i++){
		printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],pri[i],wt[i],tat[i]);
   }
	printf("\nThe Average Waiting Time--%f",(wtavg/n));
	printf("\nThe Average Turnaround Time--%f",(tatavg/n));
}
