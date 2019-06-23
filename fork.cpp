//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: fork.cpp
#include "header.hpp"

#ifndef FORK_CPP
#define FORK_CPP

void handleFork(char *command, char *args[], int numberOfArgsIncludingCommand) {
    if (numberOfArgsIncludingCommand > 2) {
        perror("Error: You entered too many arguments. Only use one argument\n");
        endProcess = 1;
    } else {
        pid_t childID = fork();

        if (childID < 0) {
            //Check if there is any sort of error then break loop in main and exit
            perror("Error after attempting to fork()\n");
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
                perror("Error when waiting for child\n");
            }
        }
    }
}

#endif