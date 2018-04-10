#include<stdio.h>
#include<conio.h>
#include<windows.h>
struct process
{
		int priority;
		int id;
		int burst;
		int arrival;
		int response;
		int wait;
		int turnaround;
		int non;
		int time;
		process *link;
}
*p=NULL,*q1 = NULL, *q2 = NULL, *q3 = NULL,
*start=NULL,*start1=NULL,*start2=NULL,*start3=NULL,
*ptr=NULL,*ptr1=NULL,*ptr2=NULL,*ptr3=NULL,
*lptr=NULL,*temp=NULL;
int time=1;
void create()
{	
	p=new process;
	printf("\n\nEnter Process ID : ") ;
	scanf("%d",&(p->id)) ;
	printf("Enter Arrival Time : ") ;
	scanf("%d",&(p->arrival)) ;
	printf("Enter Burst Time : ") ;
	scanf("%d",&(p->burst)) ;
	if ((p->burst <= 0) || p->arrival < 0)
   	{
       printf("Wrong process details entered\n");
       exit(0);
    }
	printf("Enter Priority : ") ;
	scanf("%d",&(p->priority)) ;
	p->response = p->burst ;
	p->wait=0;
	p->turnaround=0;
	if(start==NULL){
        start=p;
    }
    else
	{
        ptr=start;
        while(ptr->link!=NULL)
		{
            ptr=ptr->link;
        }
        ptr->link=p;
    }
}
void traverse()
{
    p=start;
    printf("Process Id\tArrival Time\tBurst Time\tPriority\n");
    while(p!=NULL)
	{
        printf("P%d\t\t%d\t\t%d\t\t%d\n",p->id,p->arrival,p->burst,p->priority);
        p=p->link;
    }
}
void traverse1()
{
    q1=start1;
    printf("Process Id\tArrival Time\tBurst Time\tPriority\n");
    while(q1!=NULL)
	{
        printf("P%d\t\t%d\t\t%d\t\t%d\n",q1->id,q1->arrival,q1->burst,q1->priority);
        q1=q1->link;
    }
}
void traverse2()
{
    q2=start2;
    printf("Process Id\tArrival Time\tBurst Time\tPriority\n");
    while(q2!=NULL)
	{
        printf("P%d\t\t%d\t\t%d\t\t%d\n",q2->id,q2->arrival,q2->burst,q2->priority);
        q2=q2->link;
    }
}
void traverse3()
{
    q3=start3;
    printf("Process Id\tArrival Time\tBurst Time\tPriority\n");
    while(q3!=NULL)
	{
        printf("P%d\t\t%d\t\t%d\t\t%d\n",q3->id,q3->arrival,q3->burst,q3->priority);
        q3=q3->link;
    }
}
void putinQueue()
{
	int non1=0,non2=0,non3=0;
	p=start;
	while(p!=NULL)
	{
	if((p->priority)>=1 && (p->priority)<=20)
	{
		non1++;
		q1=new process;
		q1->id=p->id;
		q1->arrival=p->arrival;
		q1->burst=p->burst;
		q1->priority=p->priority;
		if(start1==NULL)
		{
        	start1=q1;
    	}
    	else
		{
        	ptr1=start1;
        	while(ptr1->link!=NULL)
			{
            	ptr1=ptr1->link;
        	}
        	ptr1->link=q1;
    	}
	}
	else if((p->priority)>=21 && (p->priority)<=40)
	{
		non2++;
		q2=new process;
		q2->id=p->id;
		q2->arrival=p->arrival;
		q2->burst=p->burst;
		q2->priority=p->priority;
		if(start2==NULL)
		{
        	start2=q2;
    	}
    	else
		{
        	ptr2=start2;
        	while(ptr2->link!=NULL)
			{
            	ptr2=ptr2->link;
        	}
        	ptr2->link=q2;
    	}
	}
	else
	{
		non3++;
		q3=new process;
		q3->id=p->id;
		q3->arrival=p->arrival;
		q3->burst=p->burst;
		q3->priority=p->priority;
		if(start3==NULL)
		{
        	start3=q3;
    	}
    	else
		{
        	ptr3=start3;
        	while(ptr3->link!=NULL)
			{
            	ptr3=ptr3->link;
        	}
        	ptr3->link=q3;
    	}
	}
	p=p->link;
	}
	q1->non=non1;
	q2->non=non2;
	q3->non=non3;
}
void swap(struct process *a, struct process *b)
{
    int temp = a->id;
    a->id = b->id;
    b->id = temp;
    temp=a->arrival;
    a->arrival=b->arrival;
    b->arrival=temp;
    temp=a->burst;
    a->burst=b->burst;
    b->burst=temp;
    temp=a->priority;
    a->priority=b->priority;
    b->priority=temp;
}
void sort1()
{
	ptr1=start1;
	lptr=NULL;
    while(ptr1!=lptr)
    {
        while (ptr1->link != NULL)
        {
            if (ptr1->arrival > ptr1->link->arrival)
            { 
                swap(ptr1, ptr1->link);
            }
            ptr1 = ptr1->link;
		}
		lptr=ptr1;
    }
}
/*void sort2()
{
	ptr2=start2;
	lptr=NULL;
    while(ptr2!=lptr)
    {
        while (ptr2->link != NULL)
        {
            if (ptr2->arrival > ptr2->link->arrival)
            { 
                swap(ptr2, ptr2->link);
            }
            ptr2 = ptr2->link;
		}
		lptr=ptr2;
    }
	ptr2=start2;
	lptr=NULL;
    while(ptr2!=lptr)
    {
        while (ptr2->link != NULL)
        {
            if (ptr2->priority > ptr2->link->priority)
            { 
                swap(ptr2, ptr2->link);
            }
            ptr2 = ptr2->link;
		}
		lptr=ptr2;
    }
}
*/
void sort3()
{
	ptr3=start3;
	lptr=NULL;
    while(ptr3!=lptr)
    {
        while (ptr3->link != NULL)
        {
            if (ptr3->arrival > ptr3->link->arrival)
            { 
                swap(ptr3, ptr3->link);
            }
            ptr3 = ptr3->link;
		}
		lptr=ptr3;
    }
}

void rRobin()
{
	while(time<=10)
	{
	q1=start1;
	int time1 =0,flag=0,quanta = 4,wTime=0,taTime=0 ;
	printf("\n\nProcess\t\tWaiting Time    Turnaround Time\n\n"); 
  	for(time1=0;q1->burst!=0 && q1!=NULL;)
	{  	 
	    if((q1->burst<=quanta) && (q1->burst)>0)
		{ 
			time1=time1+q1->burst; 
	    	q1->burst=0; 
	      	flag=1; 
	    }
	    else if(q1->burst>quanta)
	    {
	    	q1->burst=(q1->burst)-quanta;
	    	time1=time1+4;
		}
		q1=q1->link;
	}
	time++;
	}
}
void priority()
{
	q2=start2;
	int i;
	temp=q2;
	//int ar=q2->arrival;
	while(q2!=NULL)
	{
	for(i=0;i<q2->non;i++)
	{
		q2=q2->link;
		if(q2->priority<temp->priority && q2->arrival<temp->arrival)
		{
			temp=q2;
		}
	}
	if((q2->burst)>0)
	{
		time++;
	   	q2->burst=(q2->burst)-1; 
	}
	}
}
void fcfs()
{
	q3=start3;
	int time=q2->time;
	for(time;time<time+10 && q3!=NULL;time)
	{
		if(q3->burst!=0)
		{
		time++;
		q3->burst=(q3->burst)-1;
		}
		else
		{
			q3=q3->link;
		}
	}
}
int main()
{
	int n,i;
	printf("Enter no of Processes : ") ;
	scanf("%d",&n) ;
	if (n <= 1)
   	{
       printf("No. of processes is less than 2");
       exit(0);
   	}
	printf("\n\nCreate %d processes : \n\n",n);
	for(i=0;i<n;i++)
	{
	create();
	}
	printf("Displaying %d processes : \n",n);
	traverse();
	putinQueue();
	printf("\n\n\nAll processes placed in Queue's according to their priority range.\n\n\n");
	traverse1();
	traverse2();
	traverse3();
	sort1();
	traverse1();
	traverse2();
	sort3();
	traverse3();
}
