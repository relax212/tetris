
#include "tetr.h"

//int status, valread, client_fd;
//struct sockaddr_in serv_addr;


int main(){
    int k = 0,h = 0, x = 0, z = 0, a = 0, score = 0, flag = 0, p = 0;
    char symbol;
    int pole [ROWS][COLUMNS];
    int o = 0;
    int pole2 [ROWS][COLUMNS];
    bool game_mode = Game_mode();
    fill(pole);
    fill(pole2);
    if (game_mode == true){
        while(o == 0){
        int accept[1] = {0};
        std::cout << "Waiting for connection\n";
        connect(pole);
        //send(client_fd, hello, 1024, 0);
        //read(client_fd, buffer, 1024);
            
        if (accept[0] == 1)
            o++;
            sleep(1);
        }
    }
    a = func_random();
    set_keypress2();
    while(true){
        system("clear");
        if (flag == 0){
            p = func_random();
            flag = 1;
        }
        output(pole, score, p);
        if (x == 0){
            take_butt(pole2,h,z,k,a);
            correct(pole,pole2,k,h,x,z,a);
            k += 1;
        }else{
            x = k = z = h = 0;
            check(pole, score);
            a = p;
            flag = 0;
            copy(pole2,pole);
            if (results(pole2)){
                system("clear");
                std::cout << "Game over\n" << "score = " << score << "\n";
                reset_keypress();
            }
        }
        usleep(200000-score);
    }
}