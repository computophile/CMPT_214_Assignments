# Karthaveerya Jammuladinne
# kaj886
# 11242508
# CMPT 214

.PHONY: clean all

CFLAGS= -Wall -Wextra
LDFLAGS= 

all: venting

venting: list.o list-adders.o vents.o
	gcc -o venting list.o list-adders.o vents.o

list.o: list.c  list.h
	gcc $(CFLAGS) -c list.c

list-adders.o: list-adders.c
	gcc $(CFLAGS) -c list-adders.c

vents.o: vents.c vents.h
	gcc $(CFLAGS) -c vents.c

clean:
	rm -f *.o venting
    
	