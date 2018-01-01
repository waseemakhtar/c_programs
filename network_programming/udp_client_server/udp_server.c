/* UDP server code
* Compilation step on linux server: gcc -o udp_server udp_server.c udp_socket_lib.h udp_socket_lib.c
*/
#include "udp_socket_lib.h"

int main(int argc, char *argv[])
{
  int sd = UDP_Open(10000);
  assert(sd > -1);

  while (1) {
    struct sockaddr_in s;
    char buffer[BUFFER_SIZE];
    printf("Waiting for client request or ctrl+c to exit\n");
    int rc = UDP_Read(sd, &s, buffer, BUFFER_SIZE);
    printf("Client Message: %s\n", buffer);
    if (rc > 0) {
      char reply[BUFFER_SIZE];
      sprintf(reply, "Hey Client!!");
      rc = UDP_Write(sd, &s, reply, BUFFER_SIZE);
    }
  }
  return 0;
}
