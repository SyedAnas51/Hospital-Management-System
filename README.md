# Hospital Management System

This repository contains an Object-Oriented Programming (OOP) project implemented in C++, developed by Fayaz Ahmed and Syed Muhammad Anas. The project is a comprehensive Hospital Management System designed to manage hospital staff and patient records efficiently.

## Features

- **Staff Management**:
  - Add, display, and delete staff records.
  - Support for different types of staff including Doctors, Surgeons, Dentists, and Nurses.
  - Each staff type has specific attributes, such as specialization and years of experience.

- **Patient Management**:
  - Add, display, and delete patient records.
  - Automatically assigns unique IDs to each patient.

- **File Operations**:
  - Save and load staff and patient records to and from text files.
  - Persistent storage ensures data is not lost between sessions.

## Class Structure

- **Staff**: Base class for all staff members with attributes like name, age, gender, and ID.
- **Doctor**: Inherits from Staff, adds specialization.
- **Surgeon**: Inherits from Doctor, adds number of operations performed.
- **Dentist**: Inherits from Staff, adds specialization and degree.
- **Nurse**: Inherits from Staff, adds years of experience.
- **Patient**: Class to store patient details like name, age, gender, illness, and a unique ID.
- **Hospital**: Manages arrays of staff and patients, and provides functions for adding, displaying, deleting records, and handling file operations.

## How to Run

1. Clone the repository:
   git clone https://github.com/hospital-management-system.git
   cd hospital-management-system

2. Compile the program:
   g++ -o hospital main.cpp
 

3. Run the executable:
   ./hospital

 Usage

Upon running the program, you will be presented with a menu offering the following options:

1. Add staff record
2. Display staff records
3. Delete staff record
4. Add patient record
5. Display patient records
6. Delete patient record
7. Save staff records
8. Save patient records
9. Load staff records
10. Load patient records
11. Quit

Choose the desired option by entering the corresponding number.

 File Structure

- main.CPP: Contains the main function and the implementation of the Hospital Management System.

 Contributors

- Fayaz Ahmed
- Syed Muhammad Anas

Feel free to contribute to this project by opening issues and submitting pull requests. Your contributions are highly appreciated!

