#include "tetr.h"


void output2(int pole[22][14]){
    for (int i = 3; i < 22; ++i){
        for (int j = 0; j < 14; ++j){
                std::cout << pole[i][j] << CLEAN;
            }
		std::cout << "\n";
        }
}

bool Game_mode(){
    int x = 0;
    std::cout << "Choose game mode:\n" << "1 - multiplayer\n2 - singleplayer\n";
    std::cin >> x;
    if (x == 1)
        return true;
    return false;
}

// int connect(int accept[1], int status, int valread, int client_fd, struct sockaddr_in serv_addr)
int connect(int pole[ROWS][COLUMNS]){
	int buffer[22][14]= { 0 };
	int status, valread, client_fd;
	struct sockaddr_in serv_addr;
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary
	// form
	if (inet_pton(AF_INET, "10.212.69.103", &serv_addr.sin_addr)
		<= 0) {
		printf(
			"\nInvalid address/ Address not supported \n");
		return -1;
	}

	if ((status
		= connect(client_fd, (struct sockaddr*)&serv_addr,
				sizeof(serv_addr)))
		< 0) {
		printf("\nConnection Failed \n");
		return -1;
	}
	while (true){
	send(client_fd, pole, 1024, 0);
	read(client_fd, buffer, 1024);
	output2(buffer);
	sleep(1);
	}

	// closing the connected socket
	// close(client_fd);
	return 0;
}

/*int forward(char hello[ROWS-1][COLUMNS-2]){
    int status, valread, client_fd;
	struct sockaddr_in serv_addr;
	char buffer[ROWS-1][COLUMNS-2]= { 0 };
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary
	// form
	if (inet_pton(AF_INET, "10.212.69.103", &serv_addr.sin_addr)
		<= 0) {
		printf(
			"\nInvalid address/ Address not supported \n");
		return -1;
	}

	if ((status
		= connect(client_fd, (struct sockaddr*)&serv_addr,
				sizeof(serv_addr)))
		< 0) {
		printf("\nConnection Failed \n");
		return -1;
	}
	send(client_fd, hello, 210, 0);
	printf("Hello message sent\n");
	valread = read(client_fd, buffer, 210);
	printf("%s\n", buffer);

	// closing the connected socket
	// close(client_fd);
	return 0;
}
*/