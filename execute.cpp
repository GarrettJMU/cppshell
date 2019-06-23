//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: execute.cpp
#include "header.hpp"

#ifndef EXECUTE_CPP
#define EXECUTE_CPP

void maybeExecutePipeForkOrExit(char *command, char *arguments[], int numberOfArgsIncludingCommand) {
    //This determines whether to execute, pipe, fork or exit based off of input
    int piping = 0;

    //Default piping to false then check if piping is present
    for (int i = 0; i < numberOfArgsIncludingCommand; i++) {
        if (strcmp(arguments[i], "|") == 0) { piping = 1; }
    }

    //Handle the exit command and set break loop for main
    if ((strcmp(command, "exit") == 0)) {
        endProcess = 1;
    } else if (piping) {
        handlePiping(command, arguments, numberOfArgsIncludingCommand);
    } else {
        handleFork(command, arguments, numberOfArgsIncludingCommand);
    }
}

#endif