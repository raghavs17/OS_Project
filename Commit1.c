#include<stdio.h>
#include<conio.h>
struct process {
		int priority;
		int id;
		int burst;
		int arrival;
		int response;
};
void create(int n, struct process p[])
{	
	for(int i=0; i<n; i++)
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
	for(int i=0; i<n; i++)
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
	}
