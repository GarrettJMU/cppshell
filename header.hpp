//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment Information: Assignment 2
//Filename: header.hpp
#ifndef HEADER_HPP
#define HEADER_HPP
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

using namespace std;
FILE *input = NULL;
int batch = 0;
int endProcess = 0;
int maxArguments = 1;
char *argv[1];

void batchParse(char *line);
void getUserName();
void handleFork(char *command, char *arguments[], int numberOfArgsIncludingCommand);
void handlePiping(char *command, char *arguments[], int numberOfArgsIncludingCommand);
void maybeExecutePipeForkOrExit(char *command, char *argv[], int numberOfArgsIncludingCommand);
void parse(char *line);
void setNull();
#endif