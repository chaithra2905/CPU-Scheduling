#include<stdio.h>
//#include<conio.h>
#include <limits.h>
#include<stdlib.h>
#include"rr.h"
 
int tat_find(int tat[],int comp[],int arr[],int d)
 {
 	int i;
 	double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		tat[i]=comp[i]-arr[i];
 		sum=sum+(double)(comp[i]-arr[i]);
	 }

	 return sum;
 }
 int wt_find(int wt[],int bur[],int tat[],int d)
 {
 	int i=0;
 double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		wt[i]=tat[i]-bur[i];
 		sum=sum+(double)(tat[i]-bur[i]);
	 }
	 return sum;
 }
 void display2(int pid[],int arr[],int bur[],int comp[],int tat[],int wt[],int d,double avg_wt,double avg_tat){
 	int i;
 	printf("\nPROCESS ID\tBURST TIME\tARRIVAL TIME\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n");
 	for(i=0;i<d;i++)
 	{
 		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],bur[i],arr[i],comp[i],wt[i],tat[i]);
	 }
	 printf("\naverage wating time =%lf",avg_wt);
	 printf("\nturn around time=%lf",avg_tat);
 }
void find_completion_time(int comp[],int n)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		int i;
		struct Node1 *temp=head;
		for(i=0;i<n;i++)
		{
			temp=head;
		while(temp!=NULL)
		{
			if(temp->data==i+1)
			{
				comp[i]=temp->com;	
			}	
			temp=temp->next;
		}	
		}
	}
}
struct Node * deleteNode_ready(struct Node *head1,struct Node* del) 
{ 
   if(head1==NULL)
   {
   	return NULL;
   }
   else
   {
   	struct Node *temp=head1;
   	struct Node *temp1=NULL;
   	while(temp!=NULL && temp!=del)
   	{
   		temp1=temp;
   		temp=temp->next;
	}
	if(temp==head1)
	{
		head1=head1->next;
		free(temp);
		return head1;
	}
	else
	{
	temp1->next=temp->next;
	free(temp);	
	return head1;
	}
   }
}
 void add_to_result_list(int i,int c,int p)
{
	if(head==NULL)
	{
	struct Node1 *ptr=(struct Node1 *)malloc(sizeof(struct Node1));
	ptr->data=p;
	ptr->init=i;
	ptr->com=i+c;
	ptr->next=NULL;
		head=ptr;
		tail2=head;
	}
	else
	{
	struct Node1 *ptr=(struct Node1 *)malloc(sizeof(struct Node1));
	ptr->data=p;
	ptr->init=i;
	ptr->com=ptr->init+c;
	ptr->next=NULL;
		tail2->next=ptr;
		tail2=tail2->next;
	}
}
struct Node * add_to_ready(int p,int a,int b)
{
	
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->pid=p;
	ptr->arri=a;
	ptr->bur=b;
	ptr->next=NULL;
	if(start1==NULL)
	{
	start1=ptr;
	tail1=start1;	
	}
	else
	{
			tail1->next=ptr;
			tail1=tail1->next;
	}
	return start1;
}
void search(int p,int a,int b,int c,int q)
{
if(start1==NULL && c!=0)
{
	return;
}
else
{
	if(start!=NULL)
	{
		if(c==0)
		{
			struct Node *temp=start;
			while(temp!=NULL)
			{
				if(tail2->com>=temp->arri)
				{
				
					start1=add_to_ready(temp->pid,temp->arri,temp->bur);
					start=deleteNode_ready(start,temp);
				}
				temp=temp->next;
			}
			start1=add_to_ready(p,a,b);
		}
	}
			struct Node *temp3=start1;
			if(temp3->bur==0)
			{
				if(start1!=NULL)
				start1=start1->next;
			}
			else if(temp3->bur-q<0)
			{
				add_to_result_list(tail2->com,temp3->bur,temp3->pid);
				if(start!=NULL){
				struct Node *temp5=start;
			while(temp5!=NULL)
			{
				if(tail2->com>=temp5->arri)
				{
					start1=add_to_ready(temp5->pid,temp5->arri,temp5->bur);
					start=deleteNode_ready(start,temp5);
				}
				temp5=temp5->next;
			}
			}
			start1=add_to_ready(temp3->pid,temp3->arri,0);
			start1=deleteNode_ready(start1,temp3);
			}
			else if(temp3->bur-q>=0)
			{
			add_to_result_list(tail2->com,q,temp3->pid);
				if(start!=NULL){
				struct Node *temp5=start;
			while(temp5!=NULL)
			{
				if(tail2->com>=temp5->arri)
				{
					start1=add_to_ready(temp5->pid,temp5->arri,temp5->bur);
					start=deleteNode_ready(start,temp5);
				}
				temp5=temp5->next;
			}
		}
			start1=add_to_ready(temp3->pid,temp3->arri,temp3->bur-q);
			start1=deleteNode_ready(start1,temp3);
			}
			struct Node *temp6=start1;
			while(temp6!=NULL)
			{
				temp6=temp6->next;
			}
}
search(p,a,b,1,q);
}
void competion_time(int q)
{
	if(start==NULL)
	{
	return;	
	}
	else
	{
			struct Node *temp=start;
		if(temp->arri!=start->next->arri)
		{
		if(temp->bur-q<0)
		{
			add_to_result_list(temp->arri,temp->bur,temp->pid);
			int e,f,g;
			e=temp->pid;
			f=temp->arri;
			start=deleteNode_ready(start,temp);
			search(e,f,0,0,q);
		}
		else
		{
			
		add_to_result_list(temp->arri,q,temp->pid);	
		int e,f,g;
			e=temp->pid;
			f=temp->arri;
			g=temp->bur-q;
		start=deleteNode_ready(start,temp);
		search(e,f,g,0,q);
		}
		}
		else
		{
			temp=start->next;
struct Node  *temp1=NULL;
int small=start->bur;
while(temp!=NULL)
{
	if(temp->bur<=small && start->arri==temp->arri)
	{
		temp1=temp;
		small=temp->bur;
	}
	temp=temp->next;
}
if(temp1!=NULL){
if(start->arri==temp1->arri)
{
if(start->bur>temp1->bur)	
{
if(temp1->bur-q<0)
		{
			add_to_result_list(temp1->arri,temp1->bur,temp1->pid);
			int e,f,g;
			e=temp1->pid;
			f=temp1->arri;
			start=deleteNode_ready(start,temp1);
			search(e,f,0,0,q);
		}
		else if(temp1->bur-q>=0)
		{
			
		add_to_result_list(temp1->arri,q,temp1->pid);	
		int e,f,g;
			e=temp1->pid;
			f=temp1->arri;
			g=temp1->bur-q;
		start=deleteNode_ready(start,temp1);
		search(e,f,g,0,q);
		}
}
else
{
if(start->bur-q<0)
		{
			add_to_result_list(start->arri,start->bur,start->pid);
			int e,f,g;
			e=start->pid;
			f=start->arri;
			start=deleteNode_ready(start,start);
			search(e,f,0,0,q);
		}
		else if(start->bur-q>=0)
		{
			
		add_to_result_list(start->arri,q,start->pid);	
		int e,f,g;
			e=start->pid;
			f=start->arri;
			g=start->bur-q;
		start=deleteNode_ready(start,start);
		search(e,f,g,0,q);
		}
}
}
		}
	}
}	
}
 void  sort(struct Node *head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		struct Node *temp=head;
		struct Node *temp1=NULL;
		int t;
		while(temp!=NULL)
		{
			temp1=temp->next;
			while(temp1!=NULL)
			{
				if(temp->arri>temp1->arri)
				{
					//swap the arrival time
					t=temp->arri;
					temp->arri=temp1->arri;
					temp1->arri=t;
					//swap the process
					t=temp->pid;
					temp->pid=temp1->pid;
					temp1->pid=t;
					//swap the burst time
					t=temp->bur;
					temp->bur=temp1->bur;
					temp1->bur=t;
				}
				temp1=temp1->next;
			}
			temp=temp->next;
		}
	}
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}   
void selectionSort(int arri[],int pid[],int bur[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (pid[j] < pid[min_idx]) 
            min_idx = j; 
        swap(&arri[min_idx], &arri[i]); 
        swap(&pid[min_idx],&pid[i]);
        swap(&bur[min_idx],&bur[i]);
    } 
} 
 void rr()
{
	int n;
	
	printf("enter the number of process\n");
	scanf("%d",&n);
	int i;
	int a,b,c;
	int q;
	printf("enter the time quantum\n");
	scanf("%d",&q);
	int arr[n],burs[n],tat[n],wt[n];
	for(i=0;i<n;i++)
	{
	printf("Enter the burst time and arrival time for process %d\n",i+1);
	scanf("%d %d",&a,&b);
       // printf("enter the burst time of the process %d\n",i+1);
	//scanf("%d",&b);
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->arri=a;
	ptr->bur=b;
	ptr->pid=i+1;
	ptr->next=NULL;
	if(start==NULL)
	{
	start=ptr;
	tail=start;	
	}	
	else
	{
		tail->next=ptr;
		tail=tail->next;
	}
	}
	sort(start);
	struct Node *temp=start;
	i=0;
	int pid[n];
	while(temp!=NULL)
	{
		pid[i]=temp->pid;
		arr[i]=temp->arri;
		burs[i]=temp->bur;
		temp=temp->next;
		i++;
	}
	selectionSort(arr,pid,burs,n);
	competion_time(q);
	int comp[n];
	find_completion_time(comp,n);
double avg_tat=tat_find(tat,comp,arr,n);
double avg_wt=wt_find(wt,burs,tat,n);
double avg_w=(avg_wt/(double)n);
double avg_t=(avg_tat/(double)n);
display2(pid,arr,burs,comp,tat,wt,n,avg_w,avg_t);
	return ;
//	getc();
}
