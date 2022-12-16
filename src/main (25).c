#include<stdio.h>
#include<stdlib.h>

void fcfs(void);
void sjf(void);
void rr(void);
//void compare(void);

int main()
{
	int choice;
	printf("Enter your Choice\n");

	printf("1:First Come First Serve\n2:Shortest Job First\n3:Round Robin\n4:Quit\n");

	scanf("%d",&choice);

	switch(choice)
	{
		case 1: fcfs();
			break;

		case 2: sjf();
			break;

		case 3: rr();
			break;

		//case 4: compare();
			//break;

		case 4:exit(0);

		 default:printf("Invalid choice\n");
	
	}
}
