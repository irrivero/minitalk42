# minitalk42
Client Checklist
  In the "client.c" file, you will...
- Write a program (main) in which the client takes two parameters/arguments: The PID of the server to which it wants to send the message. A message.
- Encrypt the message (I did the encryption via bits)
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
