#include<stdio.h>
#include<stdlib.h>
#include"fcfs_sjf.h"

int total_burst=0,lst_arrival=0;
int p=0;
void runFirst()
{
	/*
		this function will reinitilize the et and rbt , wt and tt .
	*/
	temp=front;
	while(temp!=NULL)
	{
		temp->rbt=temp->bt;
		temp->wt=0;
		temp->tt=0;
		temp->et=0;
		temp->pv=100;
		temp=temp->next;
	}
}
void insert(int b,int a){
	temp=front;
	new = (struct process *)malloc(sizeof(struct process));
	new->pid=++p;
	new->bt=b;
	new->at=a;

	new->wt=0;
	new->tt=0;
	new->et=0;
	new->rbt=b;		// FOR SRTF
	new->next=NULL;
	if(front==NULL)
		front=new;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;		
	}
}
void display(int n){
	float avgWT=0,avgTT=0;
	temp=front;
	printf("\n PROCESS ID\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURNAROUND TIME");
	while(temp!=NULL)
	{
		printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d",temp->pid,temp->bt,temp->at,temp->wt,temp->tt);
		avgWT+=temp->wt;
		avgTT+=temp->tt;
		temp=temp->next;
	}
	printf("\n Average WAITING TIME \t %f \t Average TURNAROUND TIME\t %f \n",(avgWT/n),avgTT/n);
}
void fcfs_1(void)
{
	//draw the gantt chart for FCFS 
	int time=0;
	//ganttchart=front;
	temp=front;
	while(temp!=NULL)
	{
		if(time>=temp->at)
		{
			
			//printf("\n Process %d at Time %d ",temp->pid,time);
			time+=temp->bt;
			//therefore time=completion time now
			temp->wt=time-(temp->at+temp->bt);
			temp->tt=time-(temp->at);
			temp=temp->next;			
			
		}
		else
		{
			//printf("\n CPU IDLE : %d",time);
			time++;
		}
	}

}
void fcfs(void)
{
	int ch,i,n,a,b;
	// INSERT ONCE ONLY ..
	// AND DISPLAY .. 
	printf("Enter the no of process \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("\n Enter the Burst time And Arrival Time for Process \t %d \t",p+1);
			scanf("%d %d",&b,&a);
			insert(b,a);
			/*
				NOT REQUIRED FOR FCFS
			*/
			if(i==0||i==n-1)
				total_burst+=a; 	// APPLICABLE FOR SJF	
			total_burst+=b;			
			//lst_arrival=a;
	}
	fcfs_1();
	display(n);
}
