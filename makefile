CC=g++

debug: CCFLAGS+=-g
debug: project1

all: project1

project1: mainp.o functions.o tree.o
	$(CC) $(CCFLAGS) mainp.o functions.o tree.o -o project1

mainp.o: mainp.cpp functions.h tree.h
	$(CC) $(CCFLAGS) -c mainp.cpp

functions.o: functions.cpp functions.h tree.h
	$(CC) $(CCFLAGS) -c functions.cpp

tree.o: tree.cpp tree.h
	$(CC) $(CCFLAGS) -c tree.cpp

clean:
	rm -rf *o project1