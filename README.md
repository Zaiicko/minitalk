# Minitalk

[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  

## Introduction

`Minitalk` is a project that involves creating a communication program using UNIX signals. It consists of a client and a server that communicate through the signals `SIGUSR1` and `SIGUSR2`. The goal of this project is to practice inter-process communication and signal handling in C.

## Features

- **Server**:
  - Prints its PID upon startup.
  - Receives messages from clients and prints them.
  - Handles messages from multiple clients consecutively without restarting.

- **Client**:
  - Takes the server PID and a string as parameters.
  - Sends the string to the server using UNIX signals.

- **Communication**:
  - Uses only `SIGUSR1` and `SIGUSR2` for communication between client and server.

- **Requirements**:
  - Proper error handling to avoid unexpected crashes.
  - No memory leaks.
  - Optional use of `libft` for utility functions.

## Makefile Commands

- **`make`**: Compiles the project, creating the `client` and `server` executables.
- **`make clean`**: Removes object files, keeping only the source code.
- **`make fclean`**: Cleans the project by removing the compiled executables and object files.
- **`make re`**: Performs a full recompilation by cleaning and then recompiling the project.

## Usage

Here is an example of using `Minitalk`:

1. **Start the server**:
  ```sh
  ./server
  ```
2. **Run the client with the server PID and message**:
  ```sh
  ./client <server_pid> "Hello, World!"
  ```
   - Replace <server_pid> with the PID displayed by the server.

## Screenshot

<img width="218" alt="Capture d’écran 2024-08-02 à 02 34 22" src="https://github.com/user-attachments/assets/b31d7548-e77f-4e5c-868e-a9778e56e8fb">
