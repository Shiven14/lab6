SYS_LINK=-L/usr/lib
INCS = -I../include
OBJS = ../obj 
FLAGS = -g 
cc = gcc

all : tsh tshtest launch

tsh : lab4.c 
	$(cc) $(EXTRA) $(INCS) $(FLAGS) -o tsh lab4.c -L$(OBJS) -lsng

tshtest : lab4test.c 
	$(cc) $(EXTRA) $(INCS) $(FLAGS) -o tshtest lab4test.c -L$(OBJS) -lsng
	
launch : launch.c 
	$(cc) $(EXTRA) $(INCS) $(FLAGS) -o launch launch.c -L$(OBJS) -lsng