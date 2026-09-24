# SafeDM: Encrypted Console Messaging System

## 1. Project Overview
SafeDM is a secure, console-based Direct Messaging application engineered entirely in standard C++. Designed to demonstrate practical software architecture and secure data handling, the application facilitates encrypted peer-to-peer communication through file-based synchronization, operating independently of high-level networking frameworks.

## 2. Technical Stack & Core Competencies
* **Language:** C++ (Standard C++11/14/17 compliant)
* **Architecture:** Object-Oriented Programming (OOP) with a focus on encapsulation and modular design.
* **Data Persistence & I/O:** Advanced utilization of standard file streams (`<fstream>`) for read/write operations, data parsing, and state management.
* **Memory & Data Structures:** Implementation of dynamic memory management, pointers/references, and Standard Template Library (STL) containers (`std::vector`, `std::map`).
* **Version Control:** Git & GitHub (including handling of large binaries and `.gitignore` hygiene).

## 3. System Architecture & Features
* **Custom Data Encryption:** Applies cryptographic algorithms to all message payloads prior to disk storage, ensuring data privacy at rest.
* **State Synchronization:** Utilizes local file systems or shared network/cloud directories (e.g., Google Drive) to propagate messages across distributed environments, engineering around traditional TCP/IP server requirements.
* **Authentication Module:** Manages secure local login and registration credential validation.
* **Platform Independence:** Decoupled from Windows-specific libraries (such as `<conio.h>`) to maintain standard compiler compatibility across POSIX and Windows systems.

## 4. Interface Documentation

![Start Screen](https://github.com/user-attachments/assets/559e3e00-ebf9-48ec-9401-44f385367b83)
![Registration Screen](https://github.com/user-attachments/assets/cfe634ac-6c7e-4e24-b7a3-91c49936a331)
![Pre-chat Screen](https://github.com/user-attachments/assets/2f1f332b-40c8-45a7-9448-223eae4566aa)
![Encrypted File Example](https://github.com/user-attachments/assets/2e4f28fd-58da-4ff2-b6bf-f488a2426a65)

## 5. Build and Deployment Instructions

### Prerequisites
* A standard C++ compiler (e.g., GCC, Clang, or MSVC)
* Git

### Local Build
1. Clone the repository:
   ```bash
   git clone [https://github.com/Strajja/SafeDM.git](https://github.com/Strajja/SafeDM.git)
