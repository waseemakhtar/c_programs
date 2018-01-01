/* UDP client code
* Compilation step on linux server: gcc -o udp_client udp_client.c udp_socket_lib.h udp_socket_lib.c
*/

#include "udp_socket_lib.h"

int main(int argc, char *argv[])
{
  int sd = UDP_Open(20000);
  struct sockaddr_in addr, addr2;
  int rc = UDP_FillSockAddr(&addr, "localhost", 10000);
  char message[BUFFER_SIZE];
  char buffer[BUFFER_SIZE];

  while (1) {
    printf("Type the message for server [ctrl+c to exit]: ");
    scanf("%s", message);
    rc = UDP_Write(sd, &addr, message, BUFFER_SIZE);
    if (rc > 0) {
      rc = UDP_Read(sd, &addr2, buffer, BUFFER_SIZE);
    }
  
    printf("Server reply = %s\n", buffer);
  }
  return 0;
}
