//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: fork.cpp
#include "header.hpp"

#ifndef FORK_CPP
#define FORK_CPP

void handleFork(char *command, char *args[], int numberOfArgsIncludingCommand) {
    pid_t childID = fork();
    if (childID < 0) {
        perror("Error when forked");
        endProcess = 1;
    } else if (childID == 0) {
        //Child process
        execvp(command, args);
        //Print error if error.present?
        perror(command);

        endProcess = 1;
    } else {
        if (waitpid(childID, 0, 0) < 0) {//parent process
            endProcess = 1;
            perror("Error when waiting for child");
        }
    }
}

#endif