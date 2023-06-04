# README

## Project Description
This code represents a Deterministic Finite State Machine (DFSM) implemented in C++. The program reads input from a file named "DFSM.txt" and interacts with the user to test the FSM using various inputs.

## Prerequisites
To compile and run this code, you need to have a C++ compiler installed on your system.

## Getting Started
1. Clone or download the code files from the repository.
2. Open the terminal or command prompt and navigate to the project directory.

## File Structure
- `Project.cpp`: This is the main file containing the code for the DFSM implementation.
- `DFSM.txt`: This file contains the input data for the FSM. Make sure it is present in the same directory as the code file.

## Compilation and Execution
To compile the code, use the following command:

```
g++ Project.cpp -o dfs_machine
```

To run the program, execute the following command:

```
./dfs_machine
```

## Usage
1. The program will attempt to open the "DFSM.txt" file to read the input data. If the file cannot be opened, an error message will be displayed, and the program will exit.
2. If the file is successfully opened, the program will display a message indicating the successful file opening.
3. The program will then read the input data from the file, including the alphabet, number of states, and acceptance states.
4. The user will be prompted to enter an input for the DFSM. Enter "E" to exit the program.
5. The program will evaluate the input using the DFSM and display whether the input is accepted or not.
6. Steps 4 and 5 will repeat until the user enters "E" to exit the program.

## Notes
- The input data in the "DFSM.txt" file should follow the specified format: alphabet (two characters separated by a comma), number of states (single digit), and acceptance states (comma-separated list of single-digit numbers).
- The program assumes that the input data in the file is valid and follows the expected format.
