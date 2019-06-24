###########################################################
# Makefile for CS570 Assignment 2
# Garrett Hughes
# cssc0849
# CS 570 Summer 2019
###########################################################

FILE=main.cpp
CC=g++
NAMEFILE=pam

run:
	$(CC) $(FILE) -o $(NAMEFILE)

clean:
	rm -f *.o
	rm -f $(NAMEFILE)