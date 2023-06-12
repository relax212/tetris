#include "tetr.h"


void output2(int pole[ROWS][COLUMNS], int enemy_score){
	int flag = 0;
	std::cout << "\n\n";
    for (int i = 3; i < ROWS; ++i){
        for (int j = 0; j < COLUMNS; ++j){
            if (pole[i][j] == 0 ){
                std::cout << FOREGROUND_RED RED "■ " << CLEAN;
            }else{
                std::cout << GREEN "■ " << CLEAN;
            }
        }
		if (flag == 0){
			std::cout << "enemy score " << enemy_score;
			flag++;
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


/*int connect2(int pole[ROWS][COLUMNS],int client_fd, int status){
		struct sockaddr_in serv_addr;
		int buffer2[22][14]= { 0 };
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

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
	send(client_fd, pole, 1232, 0);
	read(client_fd, buffer2, 1232);

	return 10;
	// closing the connected socket
	// close(client_fd);
}

int forward(char hello[ROWS-1][COLUMNS-2]){
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