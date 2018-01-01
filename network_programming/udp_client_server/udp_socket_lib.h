#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>

int UDP_Open(int port);
int UDP_FillSockAddr(struct sockaddr_in *addr, char *hostName, int port);
int UDP_Write(int sd, struct sockaddr_in *addr, char *buffer, int n);
int UDP_Read(int sd, struct sockaddr_in *addr, char *buffer, int n);
