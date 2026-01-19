# TARGETS: dependencies
# <TAB> command

############# our own variable ############
DEBUG = 1
CXX_STANDARD = c++17
CXX_WARNINGS = -Wall -Wextra -Wpedantic
EXECUTABLE_NAME = main
###########################################

##### default variable in Make ############
CXX = g++
CXXFLAGS =  $(CXX_WARNINGS) -std=$(CXX_STANDARD)
# LDFLAGS = -lmath	# as this wont work now in windows machine we can comment it and use empty LDFLAGS below
LDFLAGS = 
###########################################

###########################################
# += means we are appending into the CXXFLAGS
ifeq($(DEBUG), 1)   # if DEBUG equal to 1
CXXFLAGS += -g -O0  # add debug flag as well as no optimization
else
CXXFLAGS += -O3     # if DEBUG is not equal to 1 then add debug flag with high optimazation
endif
###########################################

########### our own variable ##############
CXX_COMPILER_CALL = $(CXX) $(CXXFLAGS)
###########################################

# we can use any name we want but for undestanding am using build here
build: main.o print.o
	$(CXX_COMPILER_CALL) main.o print.o $(LDFLAGS) -o $(EXECUTABLE_NAME)

main.o:
	$(CXX_COMPILER_CALL) main.cc -c main.o

print.o:
	$(CXX_COMPILER_CALL) print.cc -c # another valid way to generate print.o without explicitly naming it

execute:
	./main

clean:
	rm -f *.o	# remove all the .o files
	rm -f main	# remove the main executable