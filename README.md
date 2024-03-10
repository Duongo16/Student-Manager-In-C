# Student-Manager-In-C

This is a simple console-based Student Management System implemented in C. It allows you to perform various operations such as adding, deleting, and displaying student records. The system also supports reading and writing student information to a file for persistent storage.

Table of Contents
Introduction
Features
Usage
Compilation
File Handling
License
Introduction
The Student Management System is designed to manage and manipulate student records efficiently. It provides a menu-driven interface with options to perform different operations like adding students, deleting students, printing the student list, saving to a file, and exiting the program.

Features
Add Students: Allows you to input information for multiple students and adds them to the system.
Delete Students: Enables you to delete a student by providing their ID.
Print Student List: Displays the details of all students in a tabular format.
Save to File: Writes the student information to a specified file.
Read from File: Reads student information from a specified file.
Exit: Terminates the program after providing an option to save the data.
Usage
Run the program.
Choose options from the menu to perform different operations.
For file operations, enter the file name or address when prompted.
Follow the on-screen instructions to interact with the system.
Compilation
To compile the program, use a C compiler such as gcc:

bash
Copy code
gcc student_management_system.c -o student_management_system
Execute the compiled program:

bash
Copy code
./student_management_system
File Handling
Save to File: Saves the student information to a specified file. The file name must end with ".txt".
Read from File: Reads student information from a specified file. The file must be in a tabular format with columns separated by tabs.
License
This project is licensed under the MIT License - see the LICENSE file for details. Feel free to modify and use it according to your needs.
