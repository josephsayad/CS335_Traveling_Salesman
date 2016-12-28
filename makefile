CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -Wall

# EXECUTABLE_NAME is the name of the program to run.
# SOURCES includes all the .cpp files to compile.

EXECUTABLE_NAME = Project2
SOURCES = main.cpp Country.cpp InputParser.cpp MethodControl.cpp MethodOne.cpp MethodTwo.cpp MethodThree.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS) 
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE_NAME)