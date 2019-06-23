//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: pipes.cpp
#include "header.hpp"

#ifndef PIPES_CPP
#define PIPES_CPP

void createPipe(char *command, char *args[], int numberOfArgsIncludingCommand) {
    int piping = 0;
    for (int i = 0; i < numberOfArgsIncludingCommand; i++) {
        if (strcmp(args[i], "|") == 0) { piping = 1; }
    }
    if (strcmp(args[numberOfArgsIncludingCommand - 1], "&") == 0) {
        backgroundProcess = 1;
    }
    if ((strcmp(command, "exit") == 0) || (strcmp(command, "quit") == 0)) { //built-in command quit
        endProcess = 1;
    } else if (piping) {
        handlePiping(command, args, numberOfArgsIncludingCommand);
    } else {
        handleFork(command, args, numberOfArgsIncludingCommand);
    }
    endProcess = 1;
}

void handlePiping(char *command, char *args[], int numberOfArgsIncludingCommand) {
    for (int i = 0; i < numberOfArgsIncludingCommand; i++) {
        if (strcmp(args[i], "|") == 0) {
            args[i] = NULL;
            char *right[numberOfArgsIncludingCommand - i];
            int c = 0;
            for (int j = i; j < numberOfArgsIncludingCommand - 1; j++) {
                right[j - i] = args[j + 1];
                c++;
            }
            right[c] = NULL;
            int p[2];
            pipe(p);
            pid_t leftPid = fork();
            if (leftPid == 0) {//left (child)
                dup2(2, 1);
                dup2(p[1], STDOUT_FILENO);
                execvp(command, args);
            } else {//right (parent)
                pid_t rightPid = fork();
                close(p[1]);
                if (rightPid == 0) { //right child
                    dup2(2, 1);
                    dup2(p[0], STDIN_FILENO);
                    createPipe(right[0], right, c);
                } else { //parent
                    if (!backgroundProcess) { waitpid(rightPid, 0, 0); }
                }
            }
            break;
        }
    }
}

#endif