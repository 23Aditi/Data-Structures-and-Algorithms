# Student Database Management System

This C++ program implements a simple Student Database Management System that allows the user to:

- Create a student database.
- Add student information.
- Delete student information.
- Search and display student information.
- Display all student records in a tabular format.

The program uses file handling to store and manage student records in a sequential text file.

## Features

### 1. Create Student Database
The program allows the user to create a new student database file. If the database file already exists, it will be overwritten.

### 2. Add Student Information
The user can add multiple student records to the database, including:
- Roll Number
- Name
- Division
- Address

### 3. Delete Student Information
The user can delete a student record by providing a search key (Roll Number). The program will remove the record if it exists.

### 4. Search for a Student
The program allows searching for a student by Roll Number or any keyword. If the student is found, the details are displayed. Otherwise, an appropriate message is shown.

### 5. Display All Student Records
The program displays all student records in a tabular format with fields for Roll Number, Name, Division, and Address.

## File Format

The student records are stored in a text file called `students.txt`. Each record is saved in the following format:

```
RollNo||Name||Division||Address
```

For example:

```
1||John Doe||A||123 Main Street
```

## Code Explanation

- **Student Structure:** The program uses a structure `Student` to define the attributes of a student.
- **createStudentDatabase:** This function creates the `students.txt` file, initializing it as an empty database.
- **addStudent:** This function allows the user to add a student record by taking input for Roll Number, Name, Division, and Address.
- **add:** A helper function that adds multiple student records.
- **display:** This function reads and displays all the student records from the file in a tabular format.
- **search:** This function allows the user to search for a student by Roll Number or keyword and displays the record if found.
- **deletekey:** This function deletes a student record from the file based on the provided Roll Number or keyword.

## Sample Output

```
Enter Roll No : 1
Enter Name : John Doe
Enter Division : A
Enter Address : 123 Main Street
Enter Roll No : 2
Enter Name : Jane Smith
Enter Division : B
Enter Address : 456 Oak Avenue

Student Records added successfully !!

Roll No        Name                Division       Address
--------------------------------------------------------------------------------
1              John Doe            A              123 Main Street
2              Jane Smith          B              456 Oak Avenue

Searching for student with key '1':
1||John Doe||A||123 Main Street
Record Found Successfully !

Roll No        Name                Division       Address
--------------------------------------------------------------------------------
2              Jane Smith          B              456 Oak Avenue

After deletion of Roll No 1:
Roll No        Name                Division       Address
--------------------------------------------------------------------------------
2              Jane Smith          B              456 Oak Avenue
```

## How to Run

1. Ensure that you have a C++ compiler installed (e.g., GCC, Clang).
2. Compile the program:

```bash
g++ student_database.cpp -o student_database
```

3. Run the program:

```bash
./student_database
```

4. Follow the on-screen prompts to add, search, delete, and display student records.

## Conclusion

This program provides a basic functionality for managing student records using a text file. It allows users to perform CRUD (Create, Read, Update, Delete) operations on the student database, making it a useful tool for educational purposes.

---
