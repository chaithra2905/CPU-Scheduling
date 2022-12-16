a.out : main.o rr.o sjf.o fcfs.o 
		gcc  main.o rr.o sjf.o fcfs.o  -o a.out

main.o: main.c
		gcc -c main.c

rr.o : rr.c
		gcc -c rr.c

sjf.o : sjf.c 
		gcc -c sjf.c
		
fcfs.o :fcfs.c
		gcc -c fcfs.c

clean :
		rm *.o 
		rm a.out
				
