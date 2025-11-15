#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

//for sockets specifically
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAXLINE 256
#define NUMPINGS 10

int main(int argc, char *argv[]) {

    if(argc != 3) {
	fprintf(stderr,"Usage: %s, <hostname> <port>", argv[0]);
	exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *port = argv[2];
    struct addrinfo hints, *res, *rp;
    int sockfd, retval;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_DGRAM;   // UDP
    hints.ai_family   = AF_UNSPEC;    // IPv6 first, then IPv4

    retval = getaddrinfo(hostname, port, &hints, &res);
    if (retval != 0) {
	fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
	exit(EXIT_FAILURE);
    }

    // Try each result until a socket works
    for (rp = res; rp != NULL; rp = rp->ai_next) {
	sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
	if (sockfd != -1)
	    break;  // success
    }

    if (rp == NULL) {
	fprintf(stderr, "Failed to create socket for IPv4/IPv6\n");
	freeaddrinfo(res);
	exit(EXIT_FAILURE);
    }

    int sent = 0, received = 0;
    double min_rtt = 999999, max_rtt = 0, sum_rtt = 0;

    struct timeval timeout;
    timeout.tv_sec = 1;   // 1 second timeout
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    char buffer[MAXLINE];

    for (int i = 1; i <= NUMPINGS; i++) {

	const char *msg = "PING";
	ssize_t bytes = sendto(sockfd, msg, strlen(msg), 0,
			rp->ai_addr, rp->ai_addrlen);
	if (bytes < 0) {
	    perror("sendto");
	    continue;
	}

	sent++;

	struct timeval start, end;
	gettimeofday(&start, NULL);

	socklen_t addrlen = rp->ai_addrlen;

	ssize_t n = recvfrom(sockfd, buffer, MAXLINE, 0,
		      rp->ai_addr, &addrlen);

	gettimeofday(&end, NULL);

	if (n < 0) {
	    printf("%d: Sent... Timed Out\n", i);
	    continue;
	}

	buffer[n] = '\0';

	double rtt = ((end.tv_sec - start.tv_sec) * 1000) + ((end.tv_usec - start.tv_usec) / 1000);

	printf("%d: Sent... RTT=%.6f ms\n", i, rtt);

	received++;
	sum_rtt += rtt;
	if (rtt < min_rtt) min_rtt = rtt;
	if (rtt > max_rtt) max_rtt = rtt;
    }

    freeaddrinfo(res);
    close(sockfd);

    double loss_rate = 100.0 * (sent - received) / sent;
    double avg_rtt = (received > 0) ? sum_rtt / received : 0;

    printf("%d pkts xmited, %d pkts rcvd, %.0f%% pkt loss ",
	   sent, received, loss_rate);

    if (received > 0) {
	printf("min: %.6f ms, max: %.6f ms, avg: %.6f ms\n",
	min_rtt, max_rtt, avg_rtt);
    } else {
	printf("(no RTT stats, no packets received)\n");
    }

    return 0;
}
