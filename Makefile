CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS= 
LFLAGS = -lSDL2_image -lSDL2
SOURCE = -I/usr/include/SDL2
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard unitTest/*.cc)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)
EXEC= main 


all: $(EXEC)

testcase : $(OBJ_TEST) 
	g++ -std=c++11 -Wall -o $@ $^ 

$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@ $(LFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ $(SOURCE) -c $< 

.depend:
	g++ -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	rm -f $(OBJ_TEST) testcase
distclean : clean cleantest

