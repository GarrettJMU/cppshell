###########################################################
# Makefile for CS570 Assignment 1
# Garrett Hughes
# cssc0849
# CS 570 Summer 2019
###########################################################

FILE=main.cpp
CC=g++
ENDFLAGS=-lpthread
NAMEFILE=player
TEXTFILE=STACK.txt

run:
	$(CC) $(FILE) -o $(NAMEFILE) $(ENDFLAGS)

clean:
	rm -f *.o
	rm -f $(NAMEFILE)
	rm -f $(TEXTFILE)


