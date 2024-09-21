/*
---------------------------------------------------------------------
NAME:34a.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048

DESCRIPTION: Write a program to create a concurrent server.
a. use fork
b. use pthread_create

DATE: SEP 21 2024
---------------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void handle_client(int client_socket) {
    char buffer[1024];
    // memset(buffer, 0, sizeof(buffer));

/*
   It is used to clear or initialize a block of memory. Here's a breakdown of the components:

Breakdown:
buffer: This is the pointer to the memory area you want to set (in this case, the buffer).
0: This is the value that you want to set in each byte of the memory. Here, 0 is used to initialize the buffer to all zeros.
sizeof(buffer): This determines the number of bytes to set to zero, which is the size of the buffer.
Purpose:
Clearing the buffer: The function sets all the bytes in buffer to zero, ensuring no residual data remains in memory before using it.
Prevention of garbage data: It prevents old or random data (from previous operations or memory usage) from interfering with the program.


The ASCII value 0 corresponds to the NULL character, represented as '\0'. It is a non-printable control character used to signify the end of a string in C and many other programming languages.

Key points about ASCII value 0 (NULL or '\0'):
String terminator: In languages like C, '\0' is used to mark the end of a string. It signals to functions like strlen() or printf() where the string ends.
Non-printable: It's not a visible character and doesn't produce any output when printed.
Null pointer constant: In C, 0 is also used to represent a null pointer (though in modern code, NULL is preferred).
In summary, ASCII value 0 is the NULL character ('\0'), widely used as a string terminator in many programming languages.

is used to receive data from a connected socket (in this case, client_socket). Here's a breakdown of the parameters:


client_socket: This is the file descriptor for the socket from which you want to receive data. It represents the connection to the client.

buffer: This is a pointer to the memory area where the received data will be stored. It should be large enough to hold the incoming data.

sizeof(buffer): This specifies the maximum number of bytes to read from the socket. It should be the size of the buffer to ensure you don't exceed the allocated memory.

0: This is the flags parameter. A value of 0 means no special options are set for the reception. You can use flags for specific behaviors (like MSG_WAITALL), but 0 is standard for basic reception.

*/
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);
    
    printf("Received message: %s\n", buffer);

    const char* response = "Hello from the server!";
    send(client_socket, response, strlen(response), 0);

    close(client_socket);
}

int main() {

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);// created socket at server side, with ipv4 and tcp , default protocol 
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);// host to network short
    server_address.sin_addr.s_addr = INADDR_ANY;// all the interface ips 

    int opt = 1;
    /*
    The variable opt is set to 1 because:

Setting opt = 1 enables the SO_REUSEADDR socket option. This allows the server to reuse the address (port) immediately after the socket is closed, instead of waiting for the TIME_WAIT period to expire.
The value 1 is used as a boolean true to indicate the option is enabled. If opt were 0, it would disable SO_REUSEADDR.
In short, opt = 1 is used to turn on the address reuse option.
    
    */
    
    //SOL_SOCKET is the level at which socket options are defined in the socket API, allowing you to set options that affect the socket itself, such as SO_REUSEADDR and buffer sizes.
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {// configure the socket
        perror("Error setting socket options");
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {// binding is nothing but we are attaching the ip with the socket
        perror("Error binding socket");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {// 
        perror("Error listening for connections");
        exit(1);
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        // here I'm building simple server model, I do not want the cients information to store, 
        // infact the second holds the structure which store the information ip and socket
        // Third is a pointer to it
        if (client_socket < 0) {
            perror("Error accepting client connection");
            exit(1);
        }

        if (fork() == 0) {
            close(server_socket);
            handle_client(client_socket);
            exit(0);
        } else {
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

/*
************************************************************
The function accept() in the context of a socket server is used to accept an incoming connection request from a client. Here's a breakdown of the usage in your example:

c
Copy code
accept(server_socket, NULL, NULL);
Breakdown of accept() parameters:
server_socket: This is the file descriptor of the server's socket, which is in a listening state after calling listen(). The accept() function will block until a client connects to this socket.

NULL (second argument): Normally, this would be a pointer to a struct sockaddr that contains the address of the client connecting to the server. By passing NULL, you're saying you don't need to capture the client's address.

NULL (third argument): This would typically be a pointer to a socklen_t variable that specifies the size of the client address structure. By passing NULL, you indicate that you don't care about the size of the client's address.

What does accept(server_socket, NULL, NULL) do?
It accepts a new incoming client connection on the server socket (server_socket).
Since the second and third arguments are NULL, the server is ignoring the client's address information. This is fine if the server doesn’t need to know which client is connecting.
The function returns a new socket descriptor (file descriptor), which represents the connection with the client. This new socket is used to communicate with the client, while the original server_socket continues to listen for new connections.
When to use NULL in accept():
Simple servers: If you don’t need to know or log the client's address, passing NULL simplifies the code.
More advanced cases: If you need to know the client's address (e.g., for logging or access control), you should provide a struct sockaddr and its size.
Example usage:
c
Copy code
int client_socket = accept(server_socket, NULL, NULL);
if (client_socket < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
}

// Now, you can use client_socket to communicate with the client.
In short, accept(server_socket, NULL, NULL) is valid when you don't need to know the client's address, and you just want to accept the connection and proceed.






The setsockopt() function is used to configure options on a socket. It allows you to customize the behavior of a socket by setting various options, such as timeout values, buffer sizes, and other protocol-specific settings.

Purpose of setsockopt():
Modify socket behavior: It allows you to control socket options like reusing addresses (SO_REUSEADDR), setting timeouts, toggling broadcast mode, or adjusting buffer sizes.
Improve performance: Some options can help optimize performance, such as adjusting buffer sizes to suit the needs of the application.
Handle special cases: Options like SO_REUSEADDR allow a server to reuse a port, which is useful when restarting a service that needs to bind to the same port without waiting for the port to become free again.
In summary, setsockopt() is used to fine-tune and customize socket behavior to suit the needs of a specific network application.


Why is SO_REUSEADDR used?
When a server closes a socket, the address/port used by the socket enters a TIME_WAIT state for a period of time.
During this period, the port cannot be reused for a new connection unless SO_REUSEADDR is set.
SO_REUSEADDR allows you to bind to the same address/port again, which is especially useful for server applications that need to restart and bind to the same port quickly.
This option doesn't let multiple processes listen on the same port simultaneously (which would be SO_REUSEPORT in some systems), but it does help in avoiding the problem where the server is prevented from restarting because the port is still in use.




The setsockopt() function is used to configure options on a socket. It allows you to customize the behavior of a socket by setting various options, such as timeout values, buffer sizes, and other protocol-specific settings.

Yes, a socket has associated buffers that act like queues for both sending and receiving data. These buffers help manage data flow between the application and the network.

How socket buffers work:
Receive Buffer: When data is received from the network, it is stored in the receive buffer until the application reads it. If the buffer is full, incoming packets may be dropped until space becomes available.

Send Buffer: When the application sends data, it is stored in the send buffer until it can be transmitted over the network. If the buffer is full, the send() function may block (or return an error if set to non-blocking) until space becomes available.

These buffers serve as a queue, allowing the system to handle fluctuations in the rate at which data is sent and received. The size of these buffers can be adjusted using the setsockopt() function with options like SO_RCVBUF (receive buffer) and SO_SNDBUF (send buffer).

Example for setting buffer size:
c
Copy code
int rcvbuf_size = 1024 * 1024;  // 1 MB receive buffer
setsockopt(socket_fd, SOL_SOCKET, SO_RCVBUF, &rcvbuf_size, sizeof(rcvbuf_size));
Why are these buffers important?
Data flow management: The buffers ensure smooth transmission and reception, preventing data loss due to mismatched data rates between the network and the application.
Handling bursty traffic: They can absorb temporary bursts of data without overwhelming the application or network stack.
In short, the socket buffers act as queues, holding data temporarily until it can be processed by either the network or the application.


*************************************************************
*/
