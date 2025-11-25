# C-Based-Tourism-Information-Management-System

A modular, file-based Tourism Information Management System developed in C.
This project allows efficient management of tourist records with features like adding, updating, deleting, searching, and sorting. Data is stored persistently using binary file handling, demonstrating robust use of dynamic memory, structures, and multi-file programming in C.

✨ Features
✔ Core Functionalities

Add Tourist – Insert new tourist records with validation.

Display Tourists – Tabular viewing format with proper alignment.

Search Tourist – Search by unique ID.

Update Tourist – Modify name, destination, or duration.

Delete Tourist – Remove records dynamically.

Sort Records

Sort by ID

Sort by Name

✔ Technical Features

Multi-file architecture (main.c, operations.c, operations.h)

Dynamic memory handling (malloc, realloc)

Persistent storage using binary file I/O (tourists.dat)

Bubble sort implementation

Modular, extendable code design

📁 Project Structure
📦 Tourism-Management-System
├── main.c
├── operations.c
├── operations.h
└── README.md

🛠️ How to Compile & Run
Compile
gcc main.c operations.c -o tourism

Run
./tourism

📌 Sample Menu
--- Tourism Management System ---
1. Add Tourist
2. Display Tourists
3. Search Tourist
4. Update Tourist
5. Delete Tourist
6. Sort by ID
7. Sort by Name
8. Exit
Enter choice:
