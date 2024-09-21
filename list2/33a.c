/*
---------------------------------------------------------------------
NAME:33.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048

DESCRIPTION:Write a program to communicate between two machines using socket.
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
    int server_fd, new_socket;
    struct sockaddr_in address;
    /*
    struct sockaddr_in {
    short            sin_family;   // Address family (IPv4)
    unsigned short   sin_port;     // Port number (in network byte order)
    struct in_addr   sin_addr;     // Internet address (IPv4)
    char             sin_zero[8];  // Padding for alignment
};

    */
    
    int addrlen = sizeof(address);
   

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to localhost and port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};
    read(new_socket, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);

    return 0;
}

/*
The expression address.sin_addr.s_addr = INADDR_ANY; is used to bind the server socket to all available IP addresses on the machine. This means that the server will accept incoming connections from any of the machine’s network interfaces, regardless of which IP address is being used to connect.

Here's how INADDR_ANY works in detail and how it binds to all available IP addresses:

1. Network Interfaces and IP Addresses
A server machine can have multiple network interfaces, each with its own IP address. For example, a machine may have:

A loopback interface (127.0.0.1), used for internal communication (localhost).
A private network interface (e.g., 192.168.1.10 for local LAN connections).
A public IP address (e.g., 203.0.113.25 for internet connections).
Each network interface can have a different IP address, and the server may need to listen on all of them to accept incoming connections from different networks.

2. Meaning of INADDR_ANY
INADDR_ANY is a constant with a value of 0.0.0.0 (for IPv4). It represents "any available interface."
When a socket is bound using INADDR_ANY, it tells the operating system that the server should listen for incoming connections on all available network interfaces, not just a specific one.
This allows the server to be reachable via any IP address assigned to any of its network interfaces.
3. How Binding Works with INADDR_ANY
When you set address.sin_addr.s_addr = INADDR_ANY; and then call the bind() function, the following happens:

The server does not bind to a specific IP address but instead binds to all available IP addresses on the host machine.
When a client attempts to connect to the server using any IP address assigned to the machine, the operating system will route that connection to the socket that was bound to INADDR_ANY.
For example, suppose your server has the following IP addresses:

127.0.0.1 (loopback)
192.168.1.10 (private LAN)
203.0.113.25 (public IP)
By binding with INADDR_ANY, your server will accept connections on all these IP addresses.

4. What Happens Under the Hood?
When the bind() function is called after assigning INADDR_ANY to sin_addr.s_addr, the operating system does the following:

It maps the socket to all IP addresses assigned to the server’s network interfaces.
If a client connects to any of those IP addresses (e.g., 127.0.0.1, 192.168.1.10, or 203.0.113.25), the operating system will accept the connection on the socket and allow the server to handle the request.
The binding process looks like this:

IP Address Selection: Instead of restricting the server to a specific IP (e.g., 192.168.1.10), INADDR_ANY tells the OS, "accept connections on any IP address available to the server."
Listening on All IPs: The server effectively listens on all interfaces without having to bind multiple sockets manually for each IP address.
5. Why Use INADDR_ANY?
Convenience: You don't need to bind separate sockets for each IP address or interface. INADDR_ANY allows you to bind once and listen on all addresses.
Flexibility: It allows the server to handle connections from multiple networks simultaneously. For example, it can handle both local network clients (192.168.x.x) and clients from the internet (public IP).
Portability: The same code can work on any machine, regardless of how many network interfaces or IP addresses it has.
6. Example Scenario
Consider a web server on a machine with the following setup:

Interface 1: Loopback interface with IP 127.0.0.1
Interface 2: Ethernet interface with private IP 192.168.1.10
Interface 3: Public interface with IP 203.0.113.25
By setting address.sin_addr.s_addr = INADDR_ANY;, the server will bind to all these interfaces and listen for connections on any of these IP addresses. Here’s how the connection will work:

Client 1: Connects to 127.0.0.1 (localhost) – the server accepts the connection.
Client 2: Connects to 192.168.1.10 (private network) – the server accepts the connection.
Client 3: Connects to 203.0.113.25 (public network) – the server accepts the connection.
7. Binding to a Specific IP
If you don’t want to bind to all IP addresses, you can specify a particular IP address instead of INADDR_ANY. For example, to bind only to the loopback interface (127.0.0.1), you would use:

c
Copy code
inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
This restricts the server to listening only on the loopback interface, meaning it will only accept connections from the local machine (not from any other network).

Summary:
INADDR_ANY (0.0.0.0) tells the operating system to bind the socket to all available network interfaces (IP addresses).
This allows the server to accept incoming connections on any IP address assigned to the machine.
It simplifies the server code by eliminating the need to bind multiple sockets for different network interfaces or IP addresses.
The server becomes accessible via any IP address the machine has, making it flexible for local and remote connections.







**********************************************************************************
Why to use 0 in socket(domain, type,number)?????


In the function call socket(AF_INET, SOCK_STREAM, 0), the zero (0) in the third argument represents the protocol to be used with the socket. Specifically, the value 0 tells the system to automatically select the default protocol for the given combination of address family (AF_INET) and socket type (SOCK_STREAM).

Detailed Explanation:
The third argument in socket() is used to specify the protocol to be used. The socket function prototype looks like this:

c
Copy code
int socket(int domain, int type, int protocol);
domain (or address family): Specifies the communication domain or address family (e.g., AF_INET for IPv4).
type (or socket type): Specifies the type of communication (e.g., SOCK_STREAM for TCP or SOCK_DGRAM for UDP).
protocol: Specifies the exact protocol to be used within the specified domain and socket type.
What Does 0 Mean in the Protocol Field?
When the protocol field is set to 0, it indicates that the system should automatically use the default protocol for the given domain and type. For example:

When AF_INET (IPv4) is combined with SOCK_STREAM, the default protocol is TCP (Transmission Control Protocol).
When AF_INET is combined with SOCK_DGRAM, the default protocol is UDP (User Datagram Protocol).
Why Use 0?
You use 0 when:

You don't need to explicitly specify a protocol because the combination of the address family and socket type already implies the protocol (e.g., SOCK_STREAM implies TCP).
It simplifies the code, as you don't need to remember the protocol number for each combination of address family and socket type.
Example:
socket(AF_INET, SOCK_STREAM, 0): Here, 0 tells the system to use the default protocol for an IPv4 stream socket, which is TCP.
socket(AF_INET, SOCK_DGRAM, 0): In this case, 0 tells the system to use the default protocol for an IPv4 datagram socket, which is UDP.
Optional Use of Protocol:
In rare cases, you might want to use a specific non-default protocol, and instead of passing 0, you would pass the protocol number explicitly. For example, if there were multiple protocols for a particular address family and socket type, you could choose a specific one by passing its protocol number.

Summary:
The 0 in socket(AF_INET, SOCK_STREAM, 0) allows the operating system to automatically select the default protocol, which is TCP for a stream socket (SOCK_STREAM) over IPv4 (AF_INET).
************************************************************************************

Place where 0 cannot be used, in creating soxket()?

In socket(AF_INET, SOCK_STREAM, 0), the 0 represents the protocol to be used with the socket. It tells the system to select the default protocol for the given socket type. For AF_INET and SOCK_STREAM, this default protocol is TCP.

You typically pass 0 when you want the system to automatically choose the appropriate protocol. However, if you want to explicitly specify a protocol, you would pass the protocol number instead of 0. For example, if you're creating a raw socket for working directly with the IP layer, you could specify the ICMP protocol (used for ping), like this:

c
Copy code
socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
In this case, you are explicitly specifying the protocol number for ICMP (IPPROTO_ICMP) instead of using 0.





*****************************************************************************8
The function call listen(server_fd, 3) is used to mark a socket as a listening socket, which means that it is ready to accept incoming connection requests from clients. This is an essential step in the server-side socket programming workflow.

Breakdown of the Parameters:
server_fd:

This is the file descriptor for the socket that was created and bound to an address using the socket() and bind() functions, respectively.
It represents the socket that will listen for incoming connection requests.
3:

This parameter specifies the backlog size, which indicates the maximum number of pending connections that can be queued for acceptance.
When a client tries to connect to the server, if the server is not yet ready to accept that connection (e.g., it's still handling a previous connection), the connection request is placed in a queue.
The value 3 means that up to three connection requests can be queued while the server is busy handling other connections. If more than three clients try to connect simultaneously, additional connection attempts may be refused or result in errors, depending on the operating system's behavior.



How listen() Works:
By calling listen(), the socket server_fd transitions from the "passive" state to the "listening" state. This means it is now ready to accept incoming connections.
The server can then call accept() on the same socket to retrieve the file descriptor for a new connection when a client connects.
Return Value:
Success: listen() returns 0.
Failure: If it fails (e.g., if the socket is not properly set up), it returns -1, and an error code is set, which can be checked using perror() or errno.
Summary:
listen() prepares a socket to accept incoming connection requests, marking it as a listening socket.
The backlog parameter defines how many connection requests can be queued while the server is busy.
After calling listen(), the server can use accept() to handle incoming connections.
***************************************************************************







*/
