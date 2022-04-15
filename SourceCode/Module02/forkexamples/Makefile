CC=g++
CFLAGS=-I.
LIBS=-lstdc++
DEPS= 
OBJ= 

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

all: fork_ex wait_ex waitorkill exec_ex dup_ex

fork_ex: fork_ex.o $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

wait_ex: wait_ex.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

waitorkill: waitorkill.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

exec_ex: exec_ex.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

dup_ex: dup_ex.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

clean:
	-rm *.o core fork_ex wait_ex waitorkill exec_ex dup_ex

rebuild: clean all

