//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: parse.cpp
#include "header.hpp"

#ifndef PARSE_CPP
#define PARSE_CPP

//parses each command into the command and arguments
void parse(char *line) { //separate commands and arguments based in whitespace
    // Create buffer as a string and insert into a stream then create vector to hold onto words (using vector instead of array due to sizing).
    string buffer;
    stringstream bufferStream(line);
    vector<char *> words;

    //Use extraction on the buffer
    while (bufferStream >> buffer) {
        //Get chars, convert and push to words vector
        char *tempCharacters = new char[buffer.length() + 1];
        strcpy(tempCharacters, buffer.c_str());
        words.push_back(tempCharacters);
    }

    //using an array (fixed size, no need for vector) to hold all of the chars
    char **argv = new char *[words.size() + 1];

    //Inserting words vector into argv
    for (int i = 0; i < words.size(); i++) {
        argv[i] = words[i];
    }

    argv[words.size()] = NULL;
    maybeExecutePipeForkOrExit(argv[0], argv, words.size());
}

#endif