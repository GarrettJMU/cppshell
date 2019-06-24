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
            int currentCount = 0;
            for (int j = i; j < numberOfArgsIncludingCommand - 1; j++) {
                right[j - i] = arguments[j + 1];
                currentCount++;
            }

            right[currentCount] = NULL;
            int pipes[2];
            pipe(pipes);

            pid_t leftPid = fork();
            if (leftPid == 0) {
                //Child Process we update the FD and execvp
                updateFileDescriptors(pipes[1], STDOUT_FILENO);
                execvp(command, arguments);
            } else {
                //Parent Process we update the FD and exec
                pid_t rightPid = fork();
                close(pipes[1]);
                if (rightPid == 0) {
                    //Child Process we update the FD and then toss back to execute.cpp to determine output
                    updateFileDescriptors(pipes[0], STDIN_FILENO);
                    maybeExecutePipeForkOrExit(right[0], right, currentCount);
                } else { 
                    //Wait for parent
                    waitpid(rightPid, 0, 0);
                }
            }
            break;
        }

    }
}

void updateFileDescriptors(int fd1, int fd2 ) {
    dup2(2, 1);
    dup2(fd1, fd2);
}

#endif