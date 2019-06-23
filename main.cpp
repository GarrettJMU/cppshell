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
        if (argc == 1 && !endProcess) { //listening
            while (!endProcess) {
                setNull(); //set argv to null
                string commandLine;
                getUserName();
                if (getline(cin, commandLine) == 0) { endProcess = 1; }
                char *command = new char[commandLine.length() + 1];
                strcpy(command, commandLine.c_str());
                if ((command != " ") && (command != "\n") && (!endProcess)) {
                    setNull();
                    batchParse(command);
                }
//                printf("1: hitting here inside of the while loop\n");
            }
//            printf("1: hitting here outside of the while loop\n");
        } else if ((argc == 2) && !endProcess) { //executing
//            printf("2: hitting here outside of the while loop\n");
            batch = 1;
            ifstream file(argv[1]);
            string nextinst;
            while (getline(file, nextinst) && !endProcess) {
                //parse command
                char *inst = new char[nextinst.length() + 1];
                strcpy(inst, nextinst.c_str());
                if ((inst != "") && (inst != " ") && (inst != "\n") && (inst != "\t") && (inst != "\0")) {
                    batchParse(inst);
                }
//                printf("2: hitting here inside of the while loop\n");
            }
            argc = 0;
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