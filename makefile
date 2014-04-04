CC = gcc
DEBUG = -g -pg
CFLAGS = -c -g -pg -Wall
LFLAGS = -Wall

OBJS = Knapsack.o List.o

tp3: $(OBJS) main.c
	$(CC) $(DEBUG) $(LFLAGS) $(OBJS) main.c -o tp4
Knapsack.o: Knapsack.h Knapsack.c List.o
	$(CC) $(CFLAGS) Knapsack.c 
List.o: List.h List.c
	$(CC) $(CFLAGS) List.c
clean:
	\rm *.o *~ tp4
