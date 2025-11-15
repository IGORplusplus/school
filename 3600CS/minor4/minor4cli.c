#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

//for sockets specifically
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAXLINE 256

int main(int argc, char *argv[]) {

    if(argc != 3) {
	fprintf(stderr,"Usage: %s, <hostname> <port>", argv[0])
	exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    char *port = argv[2];

    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;
    socklen_t len = sizeof(servaddr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
	perror("socket");
	exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sockfd, "Hello from client", 18, 0, (struct sockaddr*)&servaddr, len);

    recvfrom(sockfd, buffer, MAXLINE, 0, NULL, NULL);
    printf("Server replied: %s\n", buffer);

    close(sockfd);
    return 0;

}
