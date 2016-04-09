#include <stdio.h>
#include <socketapi.h>
#include <WinSock2.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#define RCVBUFSIZE 32

void DieWithError(char *errorMessage) {
	perror(errorMessage);
	exit(1);
}

int main(int argc, char *argv[]) {

	int sock;
	struct sockaddr_in echoServerAddress;
	unsigned short echoServerPort;
	char *serverIP;
	char *echoString;
	char echoBuffer[RCVBUFSIZE];
	unsigned int echoStringLength;
	int bytesRcvd, totalBytesRcvd;

	if ((argc < 3 || argc>4)) {
		fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
		exit(1);
	}

	serverIP = argv[1];
	echoString = argv[2];

	if (argc == 4) {
		echoServerPort = atoi(argv[3]); /* Use given port, if any */
	}
	else {
		echoServerPort = 7; /* 7 is the well-known port for the echo service */
	}

	/* Create a reliable, stream socket using TCP */
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock < 0) {
		DieWithError("socket() failed");
	}

	/* Construct the server address structure */
	memset(&echoServerAddress, 0, sizeof(echoServerAddress));
	//  void *memset(void *str, int c, size_t n) copies the
	// character c (an unsigned char) to the first n characters
	// of the string pointed to, by the argument str.
	echoServerAddress.sin_family = AF_INET;
	echoServerAddress.sin_addr.s_addr = inet_addr(serverIP);
	echoServerAddress.sin_port = htons(echoServerPort);

	/* Establish the connection to the echo server */
	if (connect(sock, (struct sockaddr *)&echoServerAddress, sizeof(echoServerAddress)) < 0) {
		DieWithError("connect() failed");
	}

	echoStringLength = strlen(echoString);
	/* Send the string to the server */
	if (send(sock, echoString, echoStringLength, 0) != echoStringLength) {
		DieWithError("send() sent a different number of bytes than"
			"expected");
	}

	/* Receive the same string back from the server */
	totalBytesRcvd = 0;
	printf("Received: "); /* Setup to print the echoed string */
	while (totalBytesRcvd < echoStringLength) {
		/* Receive up to the buffer size (minus 1 to leave space for
		a null terminator) bytes from the sender */
		if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0) {
			DieWithError("recv() failed or connection closed"
				"prematurely");
		}
		totalBytesRcvd += bytesRcvd;
		echoBuffer[bytesRcvd] = '\0';
		printf(echoBuffer);
	}

	printf("\n");

	close(sock);

	system("pause");
	return 0;
}


