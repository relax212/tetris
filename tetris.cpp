
#include "tetr.h"




int main(){
    int k = 0,h = 0, x = 0, z = 0, a = 0, score = 0, flag = 0, p = 0;
    char symbol;
    int pole [ROWS][COLUMNS];
    int pole2 [ROWS][COLUMNS];
    fill(pole);
    fill(pole2);
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
                return 0;
            }
        }
        usleep(200000-score);
    }
}