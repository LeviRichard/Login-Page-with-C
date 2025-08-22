# Login Management System

## Objective

This C project implements a console-based login management system. It allows users to create accounts, log in, recover forgotten usernames or passwords, change passwords, and delete accounts. The system uses file-based storage to persist account data.

### Skills Learned

* Implementing account creation and login systems.
* Handling file operations in C (`fopen`, `fread`, `fwrite`).
* Masking password input using `getch()`.
* Basic input validation and error handling.
* Structuring C programs with modular functions.

### Tools Used

* C programming language
* Windows console (using `conio.h` and `windows.h`)
* File-based storage for persistence (`.txt` file)

## File Structure

```
Login-Management-System/
│
├─ main.c                 # Main program file containing all functions
├─ account.txt            # Stores user account data
└─ README.md              # Project documentation
```

## Steps

1. **Compile the program:**

   Using GCC:

   ```bash
   gcc LOGIN.c -o main
   ```

2. **Run the application:**

   ```bash
   ./main
   ```

3. **Navigate the CLI menus:**

   * **Signup**: Create a new account with first name, last name, username, phone, gender, date of birth, and password.
   * **Login**: Access your account using username and password.
   * **Forgot Password/Username**: Recover your account details.
   * **Change Password**: Securely update your password using a random verification code.
   * **Delete Account**: Permanently delete your account.

4. **Password Handling:**

   * Passwords are masked using `*` during input.
   * Confirmation is required during account creation and password change.

5. **File-Based Storage:**

   * All account data is stored in `account.txt`.
   * The system reads from and writes to this file to persist user accounts.

6. **Error Handling:**

   * Checks for incorrect usernames or passwords.
   * Provides recovery options and verification codes for password changes.
   * Prevents deletion without confirmation.

## ⚠️ Security Warning

* This application stores passwords in **plain text**. There is **no encryption or hashing**.
* Do **not use any sensitive or real credentials** while testing this application.
* This project is intended **for educational purposes only** to demonstrate file handling, user input, and basic account management in C.

## Future Improvements

* **Password Encryption/Hashing**: Use secure hashing algorithms like SHA-256 or bcrypt to store passwords instead of plain text.
* **Multi-User Support**: Allow multiple accounts to be stored and managed concurrently.
* **Role-Based Access**: Implement roles like admin, staff, or user to control access to certain functions.
* **Improved File Storage**: Use structured storage formats like JSON or SQLite instead of plain text for better data management.
* **Input Validation**: Add stricter checks for phone numbers, usernames, and passwords to prevent invalid entries.
* **Cross-Platform Compatibility**: Remove Windows-specific headers (`conio.h`, `windows.h`) to make the system portable across platforms.

