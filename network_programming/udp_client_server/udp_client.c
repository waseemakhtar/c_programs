// udp client code
#include "udp_socket_lib.h"

int main(int argc, char *argv[])
{
  int sd = UDP_Open(20000);
  struct sockaddr_in addr, addr2;
  int rc = UDP_FillSockAddr(&addr, "localhost", 10000);
  char message[BUFFER_SIZE];

  sprintf(message, "hello world");
  rc = UDP_Write(sd, &addr, message, BUFFER_SIZE);
  if (rc > 0) {
    int rc = UDP_Read(sd, &addr2, buffer, BUFFER_SIZE);
  }

  return 0;
}
