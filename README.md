# minitalk42
Client Checklist
  In the "client.c" file, you will...
- Write a program (main) in which the client takes two parameters/arguments: The PID of the server to which it wants to send the message. A message.
- Encrypt the message
- Send the message to the server (via its PID)
- Create a stop condition so that the server knows when it has finished receiving the message

Server Checklist
  In the "server.c" file, you will...
- Display its PID
- Create an endless loop so that the server can receive signals at any time
- Receive signals
- Decrypt signals: For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action.

Basic Checklist
  Of course you will also need to do these three things:
- Makefile (create the "server" and "client" executables)
- Manage errors & remove all leaks
- Deal with the holy norminette

# Why the global variable on the servers file:
- Communication between Signal Handlers and Main Function:
The main purpose of the g_int variable is to indicate whether subsequent characters received after processing the PID are part of the message or not. This is essential because the signal_handler function handles the reception of individual bits that are then assembled into characters. The state of g_int helps distinguish whether a received bit is part of the message or part of the PID.

- Maintaining State Across Functions:
In a program like this, where you're dealing with multiple signal handlers and the main function, it's important to maintain state information consistently across these functions. Using a global variable is a simple way to achieve this, as it allows multiple functions to access and modify the same state.

- Limited Scope and Controlled Usage:
The use of a global variable is limited to this specific source file (server.c). It's not being exposed outside of the file, which reduces the potential risks associated with global variables (such as unintended modification from unrelated parts of the code). This helps encapsulate the variable's usage and scope.

- Simplicity and Readability:
Given the relatively small scope of the program and its primary focus on handling signals and assembling characters, using a global variable provides a straightforward way to manage the state of whether characters are part of the message or part of the PID. While more sophisticated methods like passing a state variable to each function or using a struct could be considered, they might introduce unnecessary complexity in this specific context