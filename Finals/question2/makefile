.PHONY: clean runfile

CFLAGS = -Wall -ggdb3 -Wextra

question2: statsdb.o randomindex.o encounter.o question2.o

statsdb.o: statsdb.c statsdb.h

randomindex.o: randomindex.c randomindex.h

encounter.o: encounter.c encounter.h statsdb.h randomindex.h

question2.o: statsdb.o randomindex.o encounter.o  question2.c

clean:
		rm -f *.o question2