#include "tetr.h"
extern int tetrominoes[7][4][5][4];

static struct termios stored_settings;

void output(int pole[ROWS][COLUMNS],int score, int a){
    int flag = 0;
    int x = 0, y = 0;
    for (int i = 3; i < ROWS; ++i){
        for (int j = 0; j < COLUMNS; ++j){
            if (pole[i][j] == 0 ){
                std::cout << FOREGROUND_RED RED "■ " << CLEAN;
            }else if (pole[i][j] == 8){
                std::cout << FOREGROUND_BLUE BLUE "■ " << CLEAN;
            }else if(pole [i][j] == 3){
                std::cout << GREEN "■ " << CLEAN;
            }else{
                std::cout << GREEN "■ " << CLEAN;
            }
        }
        if (flag > 1 && x < 4 ){
            std::cout << " ";
            for (int p= 0; p < 4; ++p){
                if(tetrominoes[a][0][x][p] != 0)
                    std::cout << FOREGROUND_RED "■ " << CLEAN;
                if (tetrominoes[a][0][x][p] == 0){
                    std::cout << "  ";
                }
            }
        x++;
        }
        if (flag == 0){
            std::cout << "score = "<< score;
        }
        if (flag == 1){
            std::cout << "next figure:";
        }
        flag++;
        std::cout << '\n';
    }
}
void fill(int pole[ROWS][COLUMNS]){
    for(int i=0; i<ROWS;++i){
        for(int j = 0;j<COLUMNS;++j){
            if((i == ROWS - 1)){
                pole[i][j] = 9;
            }else if((j == 0 || j == COLUMNS - 1)){
                pole[i][j] = 9;
            }else {
                pole[i][j] = 0;
            }
        }
    }
}
void set_keypress2 (){
        tcgetattr(0, &stored_settings);
  struct termios newt = stored_settings;
  int oldf;
  newt.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
}
void take_butt(int pole2[ROWS][COLUMNS], int &h, int &z, int &k, int a)
{
 char ch,x,p;
std::cin.clear();
p = getchar();
x = getchar();
ch = getchar();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
if ( x == '['){
    turns(pole2,h,z,ch,k,a);
}

}
void reset_keypress () 
{
    tcsetattr(0, TCSANOW, & stored_settings);
}