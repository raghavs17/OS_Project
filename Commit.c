#include<stdio.h>
#include<conio.h>
struct process
{
		int priority;
		int id;
		int burst;
		int arrival;
		int response;
};
int r1=-1,r2=-1,r3=-1;
int f1=-1,f2=-1,f3=-1;
struct process q1[100], q2[100], q3[100] ;
void create(int n, struct process p[])
{	
	int i;
	for(i=0; i<n; i++)
	{
		printf("\n\nFor process : %d \n",i+1);
		printf("\n\nEnter Process ID : ") ;
		scanf("%d",&p[i].id) ;
		printf("Enter Arrival Time : ") ;
		scanf("%d",&p[i].arrival) ;
		printf("Enter Burst Time : ") ;
		scanf("%d",&p[i].burst) ;
		printf("Enter Priority : ") ;
		scanf("%d",&p[i].priority) ;
		p[i].response = p[i].burst ;
	}
}
void show(int n, struct process p[])
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("\n\nProcess ID : ") ;
		printf("%d\n",p[i].id) ;
		printf("Arrival Time : ") ;
		printf("%d\n",p[i].arrival) ;
		printf("Burst Time : ") ;
		printf("%d\n",p[i].burst) ;
		printf("Priority : ") ;
		printf("%d\n\n",p[i].priority) ;
	}
}
void pushInq1(struct process p)
{
	if(f1 ==-1)
	{
		f1=0 ;
	}
	r1 = r1+1;
	q1[r1] = p;
}
void pushInq2(struct process p)
{
	if(f2 == -1) {
		f2 = 0 ;
	}
	r2 = r2 + 1 ;
	q2[r2] = p ;
}
void pushInq3(struct process p)
{
	if(f3 == -1) {
		f3 = 0 ;
	}
	r3 = r3 + 1 ;
	q3[r3] = p ;
}
void putinQueue(int n, struct process p[])
{
	int i ;
	for(i=0; i<n; i++)
	{
		if((p[i].priority)>=1 && (p[i].priority)<20)
		{
			pushInq1(p[i]) ;
		}
		else if ((p[i].priority)>=20 && (p[i].priority)<40)
		{
			pushInq2(p[i]) ;
		}
		else if ((p[i].priority)>=40 && (p[i].priority)<60)
		{
			pushInq3(p[i]) ;
		} 
	}	
}
void displayQueue()
{
	int i ;
	printf("Queue 1 : ") ;
	for(i=0;i<=r1;i++)
	{
		printf("P%d  ",q1[i].id) ;
	}
	printf("\nQueue 2 : ") ;
	for(i=0;i<=r2;i++)
	{
		printf("P%d  ",q2[i].id) ;
	}
	printf("\nQueue 3 : ") ;
	for(i=0;i<=r3;i++)
	{
		printf("P%d  ",q3[i].id) ;
	}
	printf("\n") ;
}
void rRobin(int n, struct process p[])
{
	int i,j,time,remaining=n,flag=0,quanta = 4,wTime=0,taTime=0 ;
	
	printf("\n\nProcess\t\tWaiting Time    Turnaround Time\n\n"); 
  	for(time=0,i=0;remaining!=0;)
	  {  	 
	    if((p[i].response<=quanta) && (p[i].response)>0)
		{ 
			time+=(p[i].response); 
	      	(p[i].response)=0; 
	      	flag=1; 
	    }
		else if((p[i].response)>0)
		{ 
			(p[i].response)-=quanta; 
			time+=quanta; 
	    }
		if((p[i].response)==0 && flag==1)
		{ 
		    remaining--; 
			printf("Process[%d]\t\t%d\t\t%d\n",p[i].id,time-((p[i].arrival)-(p[i].burst)),time-(p[i].arrival)); 
		    wTime+=time-(p[i].arrival)-(p[i].burst); 
			taTime+=time-(p[i].arrival); 
		    flag=0; 
	    }
		if(i==n-1) 
	    	i=0; 
	    else if((p[i+1].arrival)<=time) 
	    	i++; 
	    else 
	    	i=0; 
	}
}
void fcfs(int n, struct process p[]) {
		float wTime[30], taTime[30];
        float avgWaitTime = 0.0, avgTaTime = 0.0;
        int c, j, nop=n;
        wTime[0] = 0;   
        for(c = 1; c < nop; c++)
        {
                wTime[c] = 0;
                for(j = 0; j < c; j++)
                {
                        wTime[c] = wTime[c] + p[j].burst ;
                }
        }
        printf("\nProcess\t\tWaiting Time\tTurnaround Time\n");
        for(c = 0; c < nop; c++)
        {
                taTime[c] = p[c].burst + wTime[c];
                avgWaitTime = avgWaitTime + wTime[c];
                avgTaTime = avgTaTime + taTime[c];
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f", p[c].id, wTime[c], taTime[c]);
        }
        printf("\n");
        avgWaitTime = avgWaitTime / c;
        avgTaTime = avgTaTime / c;
}
void s1()
{
	rRobin(r1+1, q1) ;
}
void s3()
{
	fcfs(r3+1, q3) ;
}
int main()
	{
	int n ;
	printf("Enter no of Processes : ") ;
	scanf("%d",&n) ;
	struct process p[n] ;
	printf("\n\nCreate %d processes : \n\n",n);
	create(n,p) ;
	printf("Displaying %d processes : \n",n);
	show(n,p);
	putinQueue(n,p);
	displayQueue();
	s1();
	s3();
	}
