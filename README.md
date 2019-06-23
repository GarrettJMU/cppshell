Name: Garrett Hughes
Class username: cssc0849
Class information: CS 570, Summer 2019
Assignment Information: Assignment 2
Filename: README.md

## File Manifest

- main.cpp
- header.hpp
- pam (Executable)
- README.md
- Makefile

## Compiling Instructions
```g++ main.cpp -o player.o```
or 
```make```

## Operating Instructions
```./player```
## List of design decisions
In order of getting rid of the \n on username% I hardcoded it to only take the first 8 charachters.

## List of extra features
No extra features for this assignment.

## List of known bugs


## Lessons learned
1) Log into EDORAS first. I ran into all sorts of trouble by doing this locally on my Mac, that would've just worked had I been doing it on the EDORAS environment.
2) Should've refactored at the beginning. I had 4 if statements then had individual hard coded values in each if block. In doing so I introduced a bug, (sem_post instead of sem_wait at the beginning). I spent 2 hours diagnosing it, and in doing so refactored to try and get to the root of the problem (multiple people in the critical section and calling free). Once I refactored out to a single function I noticed the issue almost immediately.
3) Edit in CLion (or whatever IDE) then `cat > main.cpp` and copy in. This sped up my workflow at least 2x
4) I'm sure it would've been quicker and probably easier to have a partner but I'm glad I did this solo so I could learn all the nuances of the SDSU system etc. 
5) Read your emails thoroughly :)
