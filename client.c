#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "core/main.h"


int main(int argc, char *argv[]){

	system("clear");
	check_args_c(argc);
	banner_client();

	char const *host = argv[1];		// Argument host.
	int const port = atoi(argv[2]); // Argument port.

	int sock_fd = socket(AF_INET, SOCK_STREAM, 0); // To create socket.

	struct sockaddr_in saddres;

	saddres.sin_family = AF_INET;
	saddres.sin_port = htons(port);
	inet_pton(AF_INET, host, &saddres.sin_addr);

	int conn = connect(sock_fd, (struct sockaddr *)&saddres, sizeof(saddres)); // To connnect the server.
	if (conn < 0){
		error("[!]");
	};

	// Handling messages.
	while (1){
		char buffer[1024] = {0};
		char message[1024];

		yellow();
		printf("[-] client :> ");
		reset();

		fgets(message,1023,stdin); // Getting user input.

		send(sock_fd, message, strlen(message), 0); // Send your message to server.

		int valread = read(sock_fd, buffer, 1024); // Reading server response.

		blue();
		printf("[+] server :> %s",buffer); // Print message in console.
		reset();
	};


	return 0;

}
