//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: execute.cpp
#include "header.hpp"

#ifndef EXECUTE_CPP
#define EXECUTE_CPP

void maybeExecutePipeForkOrExit(char *command, char *args[], int numberOfArgsIncludingCommand) {
    //This determines whether to execute, pipe or fork based off of input
    int piping = 0;

    //Default piping to false then check if piping is available
    for (int i = 0; i < numberOfArgsIncludingCommand; i++) {
        if (strcmp(args[i], "|") == 0) { piping = 1; }
    }

    //Handle the exit command and set break loop for main
    if ((strcmp(command, "exit") == 0)) {
        endProcess = 1;
    } else if (piping) {
        handlePiping(command, args, numberOfArgsIncludingCommand);
    } else {
        handleFork(command, args, numberOfArgsIncludingCommand);
    }
}

#endif