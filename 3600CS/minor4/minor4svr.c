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

    if(argc != 2) {
	perror("invalid amount of arguments");
	exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int sockfd;
    char buffer[MAXLINE];

    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);

    srand(time(NULL));
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd < 0) {
	perror("socket failed");
	exit(EXIT_FAILURE);
    }

    // printf("UDP socket successfully created. Descriptor = %d\n", sockfd);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
	perror("bind\n");
	exit(EXIT_FAILURE);
    }

    printf("Server waiting on port %d ... \n", PORT);

    int count = 0;

    while(1) {
	ssize_t n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr*)&cliaddr, &len);

	if (n < 0) {
	    perror("error with receive from in the server");
	    continue;
	}
	buffer[n] = '\0';
	count++;

	int loss = rand() % 10;
	if(loss < 3) {
	    printf("Packet lost");
	    continue;
	}

	//successful at this point
	printf("Received ping %d from %s: %s", count, inet_ntoa(cliaddr.sin_addr), buffer);

	const char* pong = "PONG";
	sendto(sockfd, pong, strlen(pong), 0, (struct sockaddr*)&cliaddr, len);
    }

    close(sockfd);
    return 0;
}
