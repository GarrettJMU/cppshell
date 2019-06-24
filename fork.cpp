//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: fork.cpp
#include "header.hpp"

#ifndef FORK_CPP
#define FORK_CPP

void handleFork(char *command, char *arguments[], int numberOfArgsIncludingCommand) {
    if (numberOfArgsIncludingCommand > 2) {
        printf("Error: You entered too many arguments. Only use one argument. Exiting now.\n");
        endProcess = -1;
    } else {
        pid_t childID = fork();

        if (childID < 0) {
            //Check if there is any sort of error then break loop in main and exit
            printf("Error after attempting to fork(). Exiting now.\n");
            endProcess = 1;
        } else if (childID == 0) {
            //Child process
            execvp(command, arguments);

            //Print error if error.present?
            perror(command);
            endProcess = 1;
        } else {
            if (waitpid(childID, 0, 0) < 0) {
                printf("Error when waiting for child.\n");
                endProcess = 1;
            }
        }
    }
}

#endif