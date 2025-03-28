#ifndef NETWORK_H
#define NETWORK_H

#if defined(_WIN32) || defined(_WIN64)
    #include <WinSock2.h>
    #include <WS2tcpip.h>
    #define createUDPSocket createUDPSocketWindows
    #define createTCPSocket createTCPSocketWindows
#elif defined(__linux__)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define createUDPSocket createUDPSocketLinux
    #define createTCPSocket createTCPSocketLinux
    #define SOCKET int
    #define SOCKADDR_IN struct sockaddr_in
    #define SOCKADDR struct sockaddr
#endif

void createSocketAddress(struct sockaddr_in* sock_addr, const char* host, int port);

SOCKET createUDPSocketWindows(const char* host, int port);
int createUDPSocketLinux(const char* host, int port);

SOCKET createTCPSocketWindows(const char* host, int port);
int createTCPSocketLinux(const char* host, int port);

#endif // NETWORK_H