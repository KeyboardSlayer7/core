#if defined(_WIN32) || defined(_WIN64)
    #include <WinSock2.h>
    #include <WS2tcpip.h>
#elif

#endif

#include "network.h"

void createSocketAddress(struct sockaddr_in* sock_addr, const char* host, int port)
{
    sock_addr->sin_family = AF_INET;
    sock_addr->sin_port = htons(port);
    inet_pton(AF_INET, host, &sock_addr->sin_addr);
}

SOCKET createUDPSocketWindows(const char* host, int port)
{
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (host != NULL && port != -1)
    {
        SOCKADDR_IN address;
        memset(&address, 0, sizeof(address));

        createSocketAddress(&address, host, port);

        bind(sock, (SOCKADDR*)&address, sizeof(address));
    }

    return sock;
}

int createUDPSocketLinux(const char* host, int port)
{
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (host != NULL && port != -1)
    {
        struct sockaddr_in address;
        memset(&address, 0, sizeof(address));

        createSocketAddress(&address, host, port);

        bind(sock, (struct sockaddr*)&address, sizeof(address));
    }

    return sock;
}

SOCKET createTCPSocketWindows(const char* host, int port)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (host != NULL && port != -1)
    {
        SOCKADDR_IN address;
        memset(&address, 0, sizeof(address));

        createSocketAddress(&address, host, port);

        bind(sock, (SOCKADDR*)&address, sizeof(address));
    }

    return sock;
}

int createTCPSocketLinux(const char* host, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (host != NULL && port != -1)
    {
        struct sockaddr_in address;
        memset(&address, 0, sizeof(address));

        createSocketAddress(&address, host, port);

        bind(sock, (struct sockaddr*)&address, sizeof(address));
    }

    return sock;
}