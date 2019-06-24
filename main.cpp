//Name: Garrett Hughes
//Class username: cssc0849
//Class information: CS 570, Summer 2019
//Assignment information: Assignment 2
//Filename: main.cpp
#include "header.hpp"
#include "fork.cpp"
#include "parse.cpp"
#include "pipes.cpp"
#include "execute.cpp"

int main(int argc, char *argv[]) {
    if (!endProcess) {
        if (argc == 1 && !endProcess) {
            while (!endProcess) {
                //Reset and have username generated
                setNull();
                string commandLine;
                getUserName();

                // Check input
                if (getline(cin, commandLine) == 0) { endProcess = 1; }
                char *command = new char[commandLine.length() + 1];
                strcpy(command, commandLine.c_str());

                // printf("\n"); // This protects against the username stacking. Not in love with this solution so commented out.
                if ((command != " ") && (!endProcess)) {
                    //Handling parsing here
                    setNull();
                    parse(command);
                }
            }
        } else if (endProcess) { return 0; }
    }
    return 0;
}

void getUserName() {
    char text[255];
    FILE *name;
    name = popen("whoami", "r");
    fgets(text, 9, name);
    cout << text << "% ";
    pclose(name);
}

void setNull() {
    for (int i = 0; i < 100; i++) {
        argv[i] = NULL;
    }
}