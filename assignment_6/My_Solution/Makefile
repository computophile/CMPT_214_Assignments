# Name: Mohammed Thamidur Rashid
# Student No: 11280257
# Course: CMPT 214

.PHONY: clean all

CDEVFLAGS = -Wall -Wextra
LDFLAGS= 

all: venting

venting: list.o list-adders.o vents.o
	gcc -o venting list.o list-adders.o vents.o

list.o: list.c  list.h
	gcc $(CDEVFLAGS) -c list.c

list-adders.o: list-adders.c
	gcc $(CDEVFLAGS) -c list-adders.c
	
vents.o: vents.c vents.h
	gcc $(CDEVFLAGS) -c vents.c

clean:
	rm -f venting *.o 
    
	
