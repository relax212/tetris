#include "tetr.h"
#include "figures.h"

int func_random(){
    srand(time(NULL));
    int num = rand() % 7;
    return num;
}


void copy(int pole[ROWS][COLUMNS],int pole2 [ROWS][COLUMNS]){
    for (int p = 0; p < ROWS; ++p){
        for (int o = 0; o < COLUMNS; ++o){
            pole [p][o] = pole2 [p][o];
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




void check (int pole[ROWS][COLUMNS], int &score){
    int flag2 = 0;
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
            flag2++;
            //score += 5000;
        }
     }
    if (flag2 == 1)
        score += 40;
    if (flag2 == 2)
        score += 100;
    if (flag2 == 3)
        score += 300;
    if (flag2 == 4)
        score += 1000;
}
bool results (int pole2[ROWS][COLUMNS]){
    for (int j = 2; j < COLUMNS - 2; ++j){
        if(pole2[3][j] == 9){
            return true;
        }
    }
    return false;
 }

 void perevod(int pole[ROWS][COLUMNS], char pole4[ROWS-1][COLUMNS-2]){
    int x = 0;
    for (int i = 0; i < ROWS-1; i++) {
        for (int j = 1; j < COLUMNS-1; j++) {
            pole4[i][j] = pole[i][j];
            x++;
         }
    }
}
