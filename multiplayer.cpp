#include "tetr.h"


int buffer[22][14]= { 0 };
extern int pole[ROWS][COLUMNS];
int status, valread, client_fd;
struct sockaddr_in serv_addr;

bool Game_mode(){
    int x = 0;
    std::cout << "Choose game mode:\n" << "1 - multiplayer\n2 - singleplayer\n";
    std::cin >> x;
    if (x == 1)
        return true;
    return false;
}
void q1(){
	send(client_fd, pole, 1024, 0);
	read(client_fd, buffer, 1024);
}

// int connect(int accept[1], int status, int valread, int client_fd, struct sockaddr_in serv_addr)
int connect(){

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
	send(client_fd, pole, 1024, 0);
	read(client_fd, buffer, 1024);
	std::thread t1(qqqq);
	std::thread t2(q1);
	t2.join();
	t1.join();


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