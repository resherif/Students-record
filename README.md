# Students-record
# Student Record System

A C++ program to manage student records, allowing users to add, display, search, update, delete, and sort student data, with persistent storage in a text file.

## Features
- **Add Students**: Input student details (ID, name, age, grade).
- **Display All Students**: View all student records from `Student.txt`.
- **Search by ID**: Find a student by their ID.
- **Update Student**: Modify a student’s name, age, or grade.
- **Delete Student**: Remove a student by ID.
- **Sort Students**: Sort students by grade (highest first).
- **Save/Load Data**: Store records in `Student.txt` and load them on startup.

## Requirements
- C++ compiler (e.g., g++ for MinGW on Windows, clang++ on macOS/Linux).
- Standard C++ libraries (`<iostream>`, `<vector>`, `<fstream>`, `<algorithm>`, `<unordered_map>`).
- A text file named `Student.txt` in the same directory as the executable (created automatically if it doesn’t exist).

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/resherif/Students-record.git
   cd Students-record
Compile the program:





g++ main.cpp -o student_record
Run the program:





./student_record
Usage
Run the program, and a menu will appear with options:
text



Hello to students record
please choose the no of operation You want !
1- add student
2- Display All Students
3- Search Student by ID
4- Update Student
5- Delete Student
6- Sort Students (By Name / Grade / ID)
7- Save to File
8- Display Student data
9- Exit
Enter a number (1–9) to select an operation.
Follow prompts to input data (e.g., student ID, name, age, grade).
After each operation, choose y to continue or n to exit.
File Structure
main.cpp: Main program with the menu-driven interface.
Student.h: Header file defining the Student struct and function prototypes.
Student.txt: Text file for storing student records (auto-generated).
Example
Input:

text



please choose the no of operation You want !
1
how many time you wanna do this operation
1
student name? John Doe
student id? 101
student age? 20
student grade? 85.5
Do you want any other service? y:n
y
please choose the no of operation You want !
3
student ID?
101
101 John Doe 20 85.5
Output in Student.txt:

text



101 John_Doe 20 85.5
Contributing
Feel free to fork this repository and submit pull requests for improvements.
Contact
For questions, reach out via GitHub.