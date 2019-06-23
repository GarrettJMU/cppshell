//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: parse.cpp
#include "header.hpp"

#ifndef PARSE_CPP
#define PARSE_CPP


////parses each line into commands
//void batchParse(char *line) { //separate commands based on ; and new lines
//    char *p = strtok(line, ";\n");
//    while (p) {
//        if (p != " ") {
//            if (batch) { cout << "Command: " << p << endl; }
//            parse(p);
//        }
//        p = strtok(NULL, ";\n");
//    }
//}

//parses each command into the command and arguments
void parse(char *line) { //separate commands and arguments based in whitespace
    int i = 0;
    string buf; // Have a buffer string
    stringstream ss(line); // Insert the string into a stream
    vector<char *> tokens; // Create vector to hold our words
    while (ss >> buf) {
        char *temp = new char[buf.length() + 1];
        strcpy(temp, buf.c_str());
        tokens.push_back(temp);
    }
    char **argv = new char *[tokens.size() + 1]; //set char array to hold arguments
    for (int k = 0; k < tokens.size(); k++) { //TODO: EXECUTE COMMANDS
        argv[k] = tokens[k];
    }
    argv[tokens.size()] = NULL;
    maybeExecutePipeForkOrExit(argv[0], argv, tokens.size());
}

#endif