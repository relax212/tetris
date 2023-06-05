#pragma once
#ifndef tetr_h
#define tetr_h

#include <iostream>
#include <unistd.h>
#include <termios.h>
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

void output(int pole[ROWS][COLUMNS],int,int);
void fill (int pole[ROWS][COLUMNS]);
void set_keypress(int pole2[ROWS][COLUMNS],int&,int&,int&,int);
int func_random();
void copy(int pole[ROWS][COLUMNS],int pole2[ROWS][COLUMNS]);
bool corrector(int pole2[ROWS][COLUMNS],int,int,int,int);
void correct(int pole[ROWS][COLUMNS],int pole2[ROWS][COLUMNS],int,int,int&,int,int);
void turns(int pole2[ROWS][COLUMNS],int&,int&,char,int&,int);
void check(int pole[ROWS][COLUMNS],int&);
bool results(int pole2[ROWS][COLUMNS]);
#endif