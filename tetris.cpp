#include <iostream>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <limits>
#include <fcntl.h>

#define ROWS 26
#define COLUMNS 14
#define RED "\e[41m"
#define CLEAN "\e[0m"
#define GREEN "\e[42m"
#define BLUE "\e[44m"
#define WHITE "\e[47m"
#define FOREGROUND_BLACK "\e[1;30m"
#define FOREGROUND_BLUE "\e[0;34m"
#define FOREGROUND_RED "\e[0;31m"
int tetromin[4][4] = {
            {0, 0, 0, 0},
            {6, 6, 6, 6},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };

int tetrominoes[7][4][5][4] = {
    {
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {2, 2, 2, 2},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {2, 2, 2, 2},
            {0, 0, 0, 0}
        },
        {
            {0, 2, 0, 0},
            {0, 2, 0, 0},
            {0, 2, 0, 0},
            {0, 2, 0, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {3, 0, 0, 0},
            {3, 3, 3, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 3, 3, 0},
            {0, 3, 0, 0},
            {0, 3, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {3, 3, 3, 0},
            {0, 0, 3, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 3, 0, 0},
            {0, 3, 0, 0},
            {3, 3, 0, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 4, 0},
            {4, 4, 4, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 4, 0, 0},
            {0, 4, 0, 0},
            {0, 4, 4, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {4, 4, 4, 0},
            {4, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {4, 4, 0, 0},
            {0, 4, 0, 0},
            {0, 4, 0, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 6, 6, 0},
            {6, 6, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 6, 0, 0},
            {0, 6, 6, 0},
            {0, 0, 6, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 6, 6, 0},
            {6, 6, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {6, 0, 0, 0},
            {6, 6, 0, 0},
            {0, 6, 0, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 7, 0, 0},
            {7, 7, 7, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 7, 0, 0},
            {0, 7, 7, 0},
            {0, 7, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {7, 7, 7, 0},
            {0, 7, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 7, 0, 0},
            {7, 7, 0, 0},
            {0, 7, 0, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, 0, 0},
            {0, 8, 0, 0},
            {8, 8, 0, 0},
            {8, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {8, 8, 0, 0},
            {0, 8, 8, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 8, 0},
            {0, 8, 8, 0},
            {0, 8, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {8, 8, 0, 0},
            {0, 8, 8, 0},
            {0, 0, 0, 0}
        }
    }
};

static struct termios stored_settings;

int func_random(){
    srand(time(NULL));
    int num = rand() % 7;
    return num;
}

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

void copy(int pole[ROWS][COLUMNS],int pole2 [ROWS][COLUMNS]){
    for (int p = 0; p < ROWS; ++p){
        for (int o = 0; o < COLUMNS; ++o){
            pole [p][o] = pole2 [p][o];
        }
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

bool corrector(int pole2 [ROWS][COLUMNS], int k, int  h, int z,int a){
    int pole3 [ROWS][COLUMNS];
    copy(pole3, pole2);
    for (int i = 0; i < 4; ++i ){
        for (int j = 0; j < 4; ++j){
            pole3[i+k][j+5+h] += tetrominoes[a][z][i][j];
        }
    }
    for (int i = 0; i < ROWS; ++i ){
        for (int j = 0; j < COLUMNS; ++j){
            if (pole3[i][j] > 9) {
                return false;
            }
        }
    }
    return true;
}

void correct(int pole[ROWS][COLUMNS],int pole2 [ROWS][COLUMNS], int k, int  h, int &x, int z,int a){
    copy(pole,pole2);
    int pole3 [ROWS][COLUMNS];
    copy(pole3,pole2);
    for (int i = 0; i < 4; ++i ){
        for (int j = 0; j < 4; ++j){
            pole3[i+k][j+5+h] += tetrominoes[a][z][i][j];
        }
    }
    for (int i = 0; i < ROWS; ++i ){
        for (int j = 0; j < COLUMNS; ++j){
            if (pole3[i][j] > 9) {
                k--;
                for (int i = 0; i < 4; ++i ){
                    for (int j = 0; j < 4; ++j){
                        pole[i+k][j+5+h] += tetrominoes[a][z][i][j];
                    }
                }
                for (int i = 0; i < ROWS-1; ++i ){
                    for (int j = 0; j < COLUMNS; ++j){
                        if (pole[i][j] != 0){
                            pole[i][j] = 9;
                        }
                    }
                }
                x = 1;
                return;
            }
        }
    }
    copy(pole,pole3);
}



void turns(int pole2[ROWS][COLUMNS], int &h, int &z, char x, int &k, int a){
    switch (x) {
        case 'D':
              h--;
            if (!corrector(pole2,k,h,z,a))
                h++;
            break;
        case 'C':
                h++;
            if (!corrector(pole2,k,h,z,a))
                h--;
            break;
        case 'A':
            z++;
            if (z == 4)
                z = 0;
            if (!corrector(pole2,k,h,z,a)){
                z--;
                if (z == -1)
                    z = 3;
            }
            break;
        case 'B':
            if (k < ROWS-5){
            k++;
            }
            if (!corrector(pole2,k,h,z,a)){
                k--;
            }
            break;
    }
}



void set_keypress(int pole2[ROWS][COLUMNS], int &h, int &z, int &k, int a)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  char c;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  do {
    ch = c;
    c = getchar();
    } while (c != '\n' && c != EOF);

 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    turns(pole2,h,z,ch,k,a);
    ch = '0';
  }
 
}
void check (int pole[ROWS][COLUMNS], int &score){
     for (int i = 0; i < ROWS - 1; ++i ){
        int flag = 0;
        for (int j = 0; j < COLUMNS; ++j){
            if (pole[i][j] != 9){
                flag = 1;
            }
        }
        if (flag == 0){
            for (int x = i; x > 1; --x){
                for (int j = 1; j < COLUMNS - 1; ++j){
                pole [x][j] = 0;
                pole [x][j] += pole[x-1][j];
                }
            }
            score += 5000;
        }
     }
}
bool results (int pole2[ROWS][COLUMNS]){
    for (int j = 1; j < COLUMNS - 1; ++j){
        if(pole2[3][j] == 9){
            return true;
        }
    }
    return false;
 }



int main(){
    int k = 0,h = 0, x = 0, z = 0, a = 0, score = 0, flag = 0, p = 0;
    char symbol;
    int pole [ROWS][COLUMNS];
    int pole2 [ROWS][COLUMNS];
    fill(pole);
    fill(pole2);
    a = func_random();
    while(true){
        system("clear");
        if (flag == 0){
            p = func_random();
            flag = 1;
        }
        output(pole, score, p);
        if (x == 0){
            set_keypress(pole2,h,z,k,a);
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
                return 0;
            }
        }
        usleep(200000-score);
    }
}