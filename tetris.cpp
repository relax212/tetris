
#include "tetr.h"
    

int main(){
    int k = 0,h = 0, x = 0, z = 0, a = 0, flag = 0, p = 0, o = 0, flag2 = 0;
    int score[1]= {0};
    int enemy_score[1]={0};
    int game_over[1]= {0};
    int game_over_enemy[1]= {1};
    char symbol;
    int buffer[ROWS][COLUMNS];
	int status, valread, client_fd;
    int pole [ROWS][COLUMNS];
    int pole2 [ROWS][COLUMNS];
    bool game_mode = Game_mode();
    fill(pole);
    fill(pole2);
    if (game_mode == true){
        struct sockaddr_in serv_addr;
	    client_fd = socket(AF_INET, SOCK_STREAM, 0);
	    serv_addr.sin_family = AF_INET;
	    serv_addr.sin_port = htons(PORT);
        inet_pton(AF_INET, "10.212.69.103", &serv_addr.sin_addr);
        status = connect (client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	    send(client_fd, pole, 1232, 0);
	    read(client_fd, buffer, 1232);
	    send(client_fd, score, 4, 0);
        read(client_fd, enemy_score, 4);
        send(client_fd, game_over, 4, 0);
        read(client_fd, game_over_enemy, 4);
        }
    a = func_random();
    set_keypress2();
    while(true){
        if (game_mode == true){
            game_over_enemy[0] = 0;
            send(client_fd, pole, 1232, 0);
	        read(client_fd, buffer, 1232);
            send(client_fd, score, 4, 0);
            read(client_fd, enemy_score, 4);
            send(client_fd, game_over, 4, 0);
            read(client_fd, game_over_enemy, 4);
        }
        system("clear");
        if (flag2 == 0){
            if (flag == 0){
                p = func_random();
                flag = 1;
            }
        }
        output(pole, score[0], p);
        if (game_mode == true)
            output2(buffer, enemy_score[0]);
        if (x == 0){
            take_butt(pole2,h,z,k,a);
            correct(pole,pole2,k,h,x,z,a);
            k += 1;
        }else{
            x = k = z = h = 0;
            check(pole, score[0]);
            a = p;
            flag = 0;
            copy(pole2,pole);
            if (results(pole2)){
                //game_over[0] = 1;
                flag2 = 1;
                if (game_over_enemy[0] == 1){
                    system("clear");
                    if (score >= enemy_score)
                        std::cout << "You win\n" << "score = " << score[0] << "\n" << "enemy score = " << enemy_score[0] << "\n";
                    else 
                        std::cout << "You lose\n" << "score = " << score[0] << "\n" << "enemy score = " << enemy_score[0] << "\n";
                    reset_keypress();
                    close(client_fd);
                    return 0;
                }
            }
        }
        usleep(200000-score[0]);
    }
}