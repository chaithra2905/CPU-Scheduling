struct process{
	int pid;		//process id
	int bt;			//busrt time
	int at;			//arival time
	int wt;			//waiting time
	int tt;			//turn around time

	int et;			//start of execution time	needed for SJF

	int rbt;		// remaining burst time ; needed for SRTF 
	int pv;			// priority value ; needed for priority scheduling (lower the value higher the priority)
	struct process *next;
};
struct process *front=NULL,*new,*temp=NULL;
struct process *ganttchart;	//		needed for SJF
