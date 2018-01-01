#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <assert.h>
#include <strings.h>
#include <netdb.h>

#define BUFFER_SIZE 64

int UDP_Open(int port);
int UDP_FillSockAddr(struct sockaddr_in *addr, char *hostName, int port);
int UDP_Write(int sd, struct sockaddr_in *addr, char *buffer, int n);
int UDP_Read(int sd, struct sockaddr_in *addr, char *buffer, int n);
