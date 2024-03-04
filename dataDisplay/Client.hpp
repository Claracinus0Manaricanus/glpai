#ifndef CLIENT
#define CLIENT

#include <sys/socket.h> //(libc, -lc)
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdint>

extern "C"{
    #include <errno.h>
    #include <unistd.h>
}

int connectTo(const char* IPV4, uint16_t port);
int sendDataTo(int sfd, float x, float y);
int sendStopTo(int sfd);
int sendClearTo(int sfd);

#endif