#include<stdio.h>
#include<stdlib.h>
#include "fcfs_sjf.h"

int total_burst1=0,lst_arrival1=0;
int p1=0;
void runFirst1()
{
	/*
		this function will reinitilize the et and rbt , wt and tt .
	*/
	temp1=front1;
	while(temp1!=NULL)
	{
		temp1->rbt=temp1->bt;
		temp1->wt=0;
		temp1->tt=0;
		temp1->et=0;
		temp1->pv=100;
		temp1=temp1->next;
	}
}
void insert1(int b,int a){
	temp1=front1;
	new = (struct process *)malloc(sizeof(struct process));
	new->pid=++p1;
	new->bt=b;
	new->at=a;

	new->wt=0;
	new->tt=0;
	new->et=0;
	new->rbt=b;		// FOR SRTF
	new->next=NULL;
	if(front1==NULL)
		front1=new;
	else
	{
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=new;		
	}
}
void display1(int n){
	float avgWT=0,avgTT=0;
	temp1=front1;
	printf("\n PROCESS ID\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURNAROUND TIME");
	while(temp1!=NULL)
	{
		printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d",temp1->pid,temp1->bt,temp1->at,temp1->wt,temp1->tt);
		avgWT+=temp1->wt;
		avgTT+=temp1->tt;
		temp1=temp1->next;
	}
	printf("\n Average WAITING TIME \t %f \t Average TURNAROUND TIME\t %f \n",(avgWT/n),avgTT/n);
}
void sjf_1(){
	// NON PREEMPTIVE 
	// SHORTEST JOB FIRST YO !!
	int time=0;
	int min=total_burst1;			//min = minimum burst time ; here it is initilized with total burst time for comparision
	runFirst1();
	temp1=front1;
	while(time<=total_burst1){
			//SCAN FOR THE SHORTEST BURST TIME whose arrival time is less than or equals to the time
			
			ganttchart=NULL;
			temp1=front1;
			min=total_burst1;
			while(temp1!=NULL)
			{
				if(temp1->et==0)
				{
					if((time>=temp1->at)&&(temp1->bt<min))
					{
						min=temp1->bt;
						ganttchart=temp1;
					}	
				}
				temp1=temp1->next;
			}
			if(ganttchart==NULL)
			{
				//no process was found ..there fore idle time
		//printf("\n CPU IDLE at %d",time);
			time++;
			}

			else{
				//printf("\n Process %d at Time %d",ganttchart->pid,time);
				time+=ganttchart->bt;
				ganttchart->et+=1;
				ganttchart->wt=time-(ganttchart->at+ganttchart->bt);
				ganttchart->tt=time-(ganttchart->at);
			}
			
	}
}
void sjf()
{
	int ch,i,n,a,b;
	// INSERT ONCE ONLY ..
	// AND DISPLAY .. 
	printf("Enter the no of process \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("\n Enter the Burst time And Arrival Time for Process \t %d \t",p1+1);
			scanf("%d %d",&b,&a);
			insert1(b,a);
			/*
				NOT REQUIRED FOR FCFS
			*/
			if(i==0||i==n-1)
				total_burst1+=a; 	// APPLICABLE FOR SJF	
			total_burst1+=b;			
			//lst_arrival=a;
		}
		sjf_1();
		display1(n);
	}
