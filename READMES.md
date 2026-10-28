# Student Grading System

A C++ console program that reads the marks of students, calculates their total, percentage and grade, saves the data in a file, and prints a ranked result sheet. It is built to demonstrate **Object-Oriented Programming (OOP)** concepts.

## Features

- Enter details of 5 students (roll number, name, branch) and marks in 5 subjects
- Input validation: marks must be between 0 and 100
- Calculates total marks, percentage and grade for each student
- Saves all records to `result.txt` and reads them back using file handling
- Sorts students by percentage (highest first) and prints a formatted result sheet
- Shows the topper and a count of students in each grade
- Search a student by roll number

## Grading Rules

| Condition | Grade |
|-----------|-------|
| Any subject below 40 | F (fail) |
| Percentage 75 or above | A |
| Percentage 60 to 74.99 | B |
| Percentage 50 to 59.99 | C |
| Percentage 40 to 49.99 | D |
| Below 40 | F |

## OOP Concepts Used

- **Classes and objects:** `Person` and `Student`
- **Inheritance:** `Student` inherits from `Person`
- **Constructors and destructor:** default and parameterized constructors
- **Static data member and static function:** `count` and `getCount()`
- **Operator overloading:** the `>` operator compares two students by percentage
- **File handling:** `ofstream` and `ifstream` to save and read `result.txt`
- **Arrays of objects:** to store and sort student records

## Technologies

- C++
- Any C++ compiler (g++ / MinGW / Code::Blocks / Dev-C++ / Visual Studio)

## How to Run

1. Download `student_grading.cpp`.
2. Compile it:
   ```
   g++ student_grading.cpp -o student_grading
   ```
3. Run it:
   ```
   ./student_grading          (Linux / macOS)
   student_grading.exe        (Windows)
   ```
4. Enter the details of the 5 students when asked. Use names without spaces (for example `Rahul`).

## Sample Output

## Sample Output

**Input (students 1 to 4)**

<img width="391" height="916" alt="Input 1" src="https://github.com/user-attachments/assets/8976ef51-826b-4918-892a-25f29e8376fd" />

**Input (student 5) and file saved**

<img width="340" height="271" alt="Input 2" src="https://github.com/user-attachments/assets/c0721cf2-8d3c-431b-bf73-bb7facd81e8b" />

**Result sheet with topper, grade count and search**

<img width="658" height="463" alt="output" src="https://github.com/user-attachments/assets/cf5b78dc-8ffb-4a6e-af11-fa617a1ed07f" />

## Limitations and Future Scope

- Number of students and subjects is fixed (`N` and `SUB` are set to 5)
- Names cannot contain spaces
- No option to edit or delete a record

Possible improvements: a menu-driven interface, editing and deleting records, taking the number of students at run time, and subject-wise marks display.

## Author

**Sharved Bharati**
Diploma in Computer Technology, Government Polytechnic, Sakoli
GitHub: [@SharvedBharati](https://github.com/SharvedBharati)
