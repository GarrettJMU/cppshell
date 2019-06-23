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
    } else if (childID == 0) { //Child process
        for (int i = 0; i < numberOfArgsIncludingCommand; i++) {
            if (strcmp(args[i], ">") == 0) {
                int newstdout = open(args[i + 1], O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
                close(1);
                dup(newstdout);
                close(newstdout);
                args[i] = NULL;
            } else if (strcmp(args[i], "<") == 0) {
                int newstdin = open(args[i + 1], O_RDONLY);
                close(0);
                dup(newstdin);
                close(newstdin);
                args[i] = NULL;
            }
        }
        execvp(command, args);
        perror(command); //only happens when there is an error
        endProcess = 1;
    } else {
        if (!backgroundProcess) { //if not a background process, wait for it
            if (waitpid(childID, 0, 0) < 0) {//parent process
                endProcess = 1;
                perror("Error when waiting for child");
            }
        }
    }
}

#endif