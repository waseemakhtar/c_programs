#include "udp_socket_lib.h"
/*Opens UDP connection by creating a socket and binding it to given
* IP and port
*/
int UDP_Open(int port)
{
  int sd;
  if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) { return -1; }
  struct sockaddr_in myaddr;
  bzero(&myaddr, sizeof(myaddr));
  myaddr.sin_family = AF_INET;
  myaddr.sin_port = htons(port);
  myaddr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sd, (struct sockaddr *) &myaddr, sizeof(myaddr)) == -1) {
    close(sd);
    return -1;
  }
  return sd;
}

//Fills all the information required to set up UDP datagram socket
int UDP_FillSockAddr(struct sockaddr_in *addr, char *hostName, int port)
{
  bzero(addr, sizeof(struct sockaddr_in));
  addr->sin_family = AF_INET; // host byte order
  addr->sin_port = htons(port); // short, network byte order
  struct in_addr *inAddr;
  struct hostent *hostEntry;
  if ((hostEntry = gethostbyname(hostName)) == NULL) { return -1; }
  inAddr = (struct in_addr *) hostEntry->h_addr;
  addr->sin_addr = *inAddr;
  return 0;
}

//Sends / writes using the provided socket descriptor
int UDP_Write(int sd, struct sockaddr_in *addr, char *buffer, int n)
{
  int addrLen = sizeof(struct sockaddr_in);
  return sendto(sd, buffer, n, 0, (struct sockaddr *) addr, addrLen);
}

//Receives incoming UDP datagram requests / responses
int UDP_Read(int sd, struct sockaddr_in *addr, char *buffer, int n)
{
  int len = sizeof(struct sockaddr_in);
  return recvfrom(sd, buffer, n, 0, (struct sockaddr *) addr,
                  (socklen_t *) &len);
}
