# Contact Book v1.5 (C)

## Description
A small console app written in C.
The program allows users to store contacts in memory and persist them using a CSV file.

This is my first programming (mini)project, built as part of my learning process while following Harvard's CS50 course.
It focuses on fundamental C concepts such as structs, pointers, dynamic memory allocation, file I/O.

## Features
- Add new contacts
- List all contacts
- Save contacts to a CSV file
- Load contacts from a CSV file at startup

## Technical Concepts Practiced
- Structs and arrays
- Pointers and pass-by-reference
- Heap vs stack memory
- Dynamic allocation (strdup, free)
- File handling (fopen, fgets, fprintf)
- String tokenization with strtok
- Basic input handling using the CS50 library

## What's Next
- v2.0
    - Add search functionality
    - Add delete contact option
    - Improve structure and code quality

## Compilation
clang main.c contacts.c -lcs50 -o main
./main
