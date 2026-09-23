# SafeDM: Encrypted Console Messaging Application

SafeDM is a secure, console-based Direct Messaging software developed entirely in standard C++. The application provides user authentication and encrypted message exchange by utilizing a file-based synchronization architecture, operating independently of high-level networking frameworks.

## System Overview

* **User Authentication:** Manages secure local login and registration credentials.
* **Peer-to-Peer Chat Rooms:** Establishes isolated direct messaging sessions between specific authenticated users.
* **Data Encryption:** Applies custom cryptographic algorithms to all message payloads prior to disk storage, ensuring data privacy at rest.
* **File-Based State Synchronization:** Utilizes local file systems or shared network/cloud directories (e.g., Google Drive) to propagate messages across distributed environments without requiring a dedicated TCP/IP server.

## Technical Specifications

* **Language:** C++ (Standard C++11/14/17 compliant)
* **Architecture:** Object-Oriented Programming (OOP) principles and encapsulation.
* **Data Persistence:** Advanced utilization of standard file streams (`<fstream>`) for read/write operations, data parsing, and local state management.
* **Memory & Data Structures:** Implementation of dynamic memory management, pointers/references, and Standard Template Library (STL) containers (`std::vector`, `std::map`) for efficient user and message handling.
* **Compatibility:** Decoupled from platform-specific dependencies to maintain standard compiler compatibility across operating systems.

## Interface Details

![Start Screen](https://github.com/user-attachments/assets/559e3e00-ebf9-48ec-9401-44f385367b83)
![Registration Screen](https://github.com/user-attachments/assets/cfe634ac-6c7e-4e24-b7a3-91c49936a331)
![Pre-chat Screen](https://github.com/user-attachments/assets/2f1f332b-40c8-45a7-9448-223eae4566aa)
![Encrypted File Example](https://github.com/user-attachments/assets/2e4f28fd-58da-4ff2-b6bf-f488a2426a65)

## Installation and Build Instructions

### Prerequisites
* A standard C++ compiler (e.g., GCC, Clang, or MSVC)
* Git

### Build Steps
1. Clone the repository:
   ```bash
   git clone [https://github.com/Strajja/SafeDM.git](https://github.com/Strajja/SafeDM.git)
