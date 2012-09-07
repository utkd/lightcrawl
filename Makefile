#Makefile for lightcrawl
#Author: Utkarsh Desai

CC=g++
CPPFLAGS=-std=c++0x -pthread 
LDFLAGS=

PROG = lightcrawl
HDRS = src/controller.h src/utils.h src/urlqueue.h
SRCS = src/main.cpp src/controller.cpp src/urlqueue.cpp src/utils.cpp

#Object files have same name as sources except with a .o
OBJS = $(SRCS:.cpp=.o)

#Build the program using object files (default rule)
$(PROG) : $(OBJS)
	$(CC) -pthread -o $(PROG) $(OBJS) 

#Rules for source files
main.o : src/main.cpp src/controller.cpp src/controller.h src/utils.cpp src/utils.h

controller.o : src/controller.cpp src/controller.h src/urlqueue.cpp src/urlqueue.h

queue.o : src/urlqueue.cpp src/urlqueue.h

utils.o : src/utils.cpp src/utils.h

#Clean target
clean:
	rm -f $(PROG) $(OBJS)
