Name: Garrett Hughes
Class username: cssc0849
Class information: CS 570, Summer 2019
Assignment Information: Assignment 2
Filename: README.md

## File Manifest

- main.cpp
- execute.cpp
- fork.cpp
- parse.cpp
- pipes.cpp
- header.hpp
- pam (Executable)
- README.md
- Makefile
- /git (decided to use version controlling this time)

## Compiling Instructions
```g++ main.cpp -o pam```
or 
```make```

## Operating Instructions
```./pam```
## List of design decisions
In order of getting rid of the \n on username% I hardcoded it to only take the first 8 charachters.

## List of extra features
No extra features for this assignment.

## List of known bugs
When piping it creates concats the username. I didn't have enough time to figure that out so as a fix I add a new line on line 22 of main.cpp
i.e.
```
  ls
  do exec
  cssc0849% back to waiting for input
```
when piped:
```
  ls | sort
  do exec
  cssc0849% cssc0849% back to waiting for input
```
My (hacky) solution:
```
  ls | sort
  do exec
  cssc0849%
  cssc0849% back to waiting for input
```
So I put a line break above to protect against the double username (but now it's just an empty line).

## Lessons learned
1) Use version controlling. Since I'm not using VIM (I find it faster to edit in my IDE the cat > filename into edoras file).
2) By using version controlling I can keep track of local and remote (ssh) development.
