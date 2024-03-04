#include "../Client.hpp"

int connectTo(const char* IPV4, uint16_t port){
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1){
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = (port<<8) + (port>>8);
    inet_pton(AF_INET, IPV4, &addr.sin_addr.s_addr);

    if(connect(sfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in)) == -1){
        close(sfd);
        return -1;
    }

    return sfd;
}

int sendDataTo(int sfd, float x, float y){
    char buffer[8];

    int* iX = (int*)&x;
    int* iY = (int*)&y;

    buffer[0] = 0xFF & (*iX);
    buffer[1] = 0xFF & ((*iX) >> 8);
    buffer[2] = 0xFF & ((*iX) >> 16);
    buffer[3] = 0xFF & ((*iX) >> 24);

    buffer[4] = 0xFF & (*iY);
    buffer[5] = 0xFF & ((*iY) >> 8);
    buffer[6] = 0xFF & ((*iY) >> 16);
    buffer[7] = 0xFF & ((*iY) >> 24);

    int ret = send(sfd, buffer, 8, 0);

    close(sfd);
    return ret;
}

int sendStopTo(int sfd){
    char buffer[9] = {0};
    buffer[8] = 'e';
    
    int ret = send(sfd, buffer, 9, 0);

    close(sfd);
    return ret;
}

int sendClearTo(int sfd){
    char buffer[9] = {0};
    buffer[8] = 'c';
    
    int ret = send(sfd, buffer, 9, 0);

    close(sfd);
    return ret;
}