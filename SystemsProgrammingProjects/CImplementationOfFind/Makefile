CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs
TARGETS=	search

all:		$(TARGETS)


execute.o:	execute.c search.h
		$(CC) $(CFLAGS) -o execute.o -c execute.c

filter.o:	filter.c search.h
		$(CC) $(CFLAGS) -o filter.o -c filter.c

main.o:		main.c search.h
		$(CC) $(CFLAGS) -o main.o -c main.c

utilities.o:	utilities.c search.h
		$(CC) $(CFLAGS) -o utilities.o -c utilities.c

search.o:	search.c search.h
		$(CC) $(CFLAGS) -o search.o -c search.c

search:		execute.o filter.o main.o search.o utilities.o
		$(LD) $(LDFLAGS) -o search execute.o filter.o main.o search.o utilities.o

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) *.o *.log *.input

.PHONY:		all test benchmark clean

