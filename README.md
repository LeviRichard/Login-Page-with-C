# Simple Login System

Welcome to the Simple Login System project. This project, written in C, provides a basic framework for user authentication. It includes functionalities such as signup, login, password recovery, password change, and account deletion. User data is stored in a file named 'account.txt'.

## Getting Started

These instructions will help you get a copy of the project up and running on your local machine.

### Prerequisites

To use this project, you need to have the GCC compiler installed on your system.

### Installation

Once you have the GCC compiler installed, you can compile the source code using the following command:

```bash
gcc -o login login.c
```

This command will create an executable file named 'login'. 

### Running the Program

You can run this file using the following command:

```bash
./login
```

## Features

After running the program, you will be presented with a menu. You can navigate the menu using the arrow keys and select an option by pressing the Enter key. The program provides the following functionalities:

- **Signup**: Register a new user by providing their personal information and setting a password.
- **Login**: Log in using an existing username and password.
- **Forgot Password or Username**: Retrieve your username or password.
- **Change Password**: Update your password.
- **Delete Account**: Delete your account permanently.
- **Exit**: Close the program.

## License

This project is licensed under the MIT License.

## Acknowledgments and Warning

This project is a simple demonstration of a login system. It does not provide comprehensive security features such as hashing and salting passwords, two-factor authentication, or encryption. Please note that storing sensitive information in plain text can pose significant security risks. It is highly recommended to implement robust security measures when dealing with real-world user data.

