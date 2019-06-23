//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment Information: Assignment 2
//Filename: header.hpp
#ifndef HEADER_HPP
#define HEADER_HPP
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;
FILE *input = NULL;
int batch = 0;
int endProcess = 0;
int maxArguments = 1;
char *argv[1];
int backgroundProcess = 0;

void batchParse(char *line);

void execute(char *command, char *argv[], int numberOfArgsIncludingCommand);

void parse(char *line);

void setNull();

void getUserName();

void createPipe(char *command, char *args[], int numberOfArgsIncludingCommand);

void handleFork(char *command, char *args[], int numberOfArgsIncludingCommand);

void handlePiping(char *command, char *args[], int numberOfArgsIncludingCommand);
#endif
