//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: pipes.cpp
#include "header.hpp"

#ifndef PIPES_CPP
#define PIPES_CPP

void handlePiping(char *command, char *arguments[], int numberOfArgsIncludingCommand) {
    for (int i = 0; i < numberOfArgsIncludingCommand; i++) {
        if (strcmp(arguments[i], "|") == 0) {
            arguments[i] = NULL;
            char *right[numberOfArgsIncludingCommand - i];
            int c = 0;
            for (int j = i; j < numberOfArgsIncludingCommand - 1; j++) {
                right[j - i] = arguments[j + 1];
                c++;
            }
            right[c] = NULL;
            int p[2];
            pipe(p);
            pid_t leftPid = fork();
            if (leftPid == 0) {
                //Child Process we update the FD and exec
                dup2(2, 1);
                dup2(p[1], STDOUT_FILENO);
                execvp(command, arguments);
            } else {
                //Parent Process we update the FD and exec
                pid_t rightPid = fork();
                close(p[1]);
                if (rightPid == 0) {
                    //Child Process we update the FD and then toss back to execute.cpp
                    dup2(2, 1);
                    dup2(p[0], STDIN_FILENO);
                    maybeExecutePipeForkOrExit(right[0], right, c);
                }
            }
            break;
        }
    }
}
#endif