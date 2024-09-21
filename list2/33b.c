/*
---------------------------------------------------------------------
NAME:33.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048

DESCRIPTION: Write a program to communicate between two machines using socket.
DATE: SEP 21 2024
---------------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    struct sockaddr_in address;
    int sock = 0;
    char *hello = "Hello from client";

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    return 0;
}
/*
______________________________________________________________________
The function call send(sock, hello, strlen(hello), 0) is used to send data over a connected socket. In this case, it sends a message (or data) from the client to the server.

Breakdown of the Parameters:
sock:

This is the file descriptor for the connected socket that was previously created and connected using socket() and connect(). It represents the endpoint for communication with the server.
hello:

This is a pointer to the data buffer that you want to send. In this context, hello is expected to be a string or a character array containing the message you wish to transmit (e.g., "Hello, Server!").
strlen(hello):

This specifies the number of bytes to send. It calculates the length of the data to be sent using the strlen() function, which returns the number of characters in the string, excluding the null terminator.
0:

This is the flags parameter, which can modify the behavior of the send() function. Passing 0 means that you are using the default behavior. Other flag options include:
MSG_DONTWAIT: Send the data in a non-blocking mode.
MSG_NOSIGNAL: Prevent sending the SIGPIPE signal if the peer has closed the connection.
______

How send() Works:
The send() function transmits the specified amount of data from the buffer (hello) to the connected socket (sock).
If the transmission is successful, send() returns the number of bytes sent.
If it fails (e.g., due to a broken connection), it returns -1, and an error code is set.
Summary:
send() is used to send data over a connected socket.
It requires the socket file descriptor, a pointer to the data buffer, the length of the data, and optional flags.
Successful calls allow for the transmission of messages or data from the client to the server.
____

MSG_DONTWAIT is a flag that can be used with the send() and recv() functions in socket programming to indicate non-blocking behavior. When this flag is set, the function will return immediately if it cannot complete the operation, rather than blocking the calling thread until it can.



______
The function call connect(sock, (struct sockaddr *)&address, sizeof(address)) is used by a client to establish a connection to a server socket. This is a fundamental step in socket programming, allowing the client to initiate communication with a server.

Breakdown of the Parameters:
sock:

This is the file descriptor for the client socket. It should have been created using the socket() function earlier in the code. It serves as an endpoint for sending and receiving data.
(struct sockaddr *)&address:

This is a pointer to a struct sockaddr, which contains the address information of the server the client is attempting to connect to. The address variable is typically defined as a struct sockaddr_in for IPv4 connections.
The cast to (struct sockaddr *) is necessary because connect() expects a pointer to a generic socket address structure.
sizeof(address):

This specifies the size of the address structure. It tells the connect() function how much memory to read for the address information. This is important for proper interpretation of the structure.


___

How connect() Works:
When you call connect(), the client socket attempts to establish a connection to the specified server at the provided address and port.
If the connection is successful, connect() returns 0, indicating that the socket is now ready for communication.
If the connection fails (e.g., if the server is not available or the address is incorrect), connect() returns -1, and you can check errno for the specific error.
Summary:
connect() is a crucial function in client-server socket programming, used to establish a connection to a server.
It requires the client socket file descriptor, a pointer to the server's address structure, and the size of that structure.
After a successful connection, the socket can be used for data transmission with the server.______
_____________________________________________

*/
