#ifndef veriable_H_INCLUDED
#define veriable_H_INCLUDED

//int bg;
int menu, level, instruction;
int b1, b2, b3, b4, b5;
bool game_on = false;
//jerry
//int jerry;
//int jeX = 300, jeY =200;
int index = 0;
bool stand = true;
int count = 0;

//coin
int coin[50];
int C_x[2], C_y[2];

//fire
int fire;
int shoot = 0;
bool musicOn = true;

//score
char Sc[100];

int mposx, mposy;
//back ground veriable
int bg[2];
int bg_x[] = { 0,1500 }, bg_y[] = { 0,0 };
//jerry veriable
//int j_x[] = { 40,40,40,40,40,40,40,40,40 }, j_y[] = { 150,150,150,150,150,150,150,150,150 };
int je[9];
int js;
int indexjs = 0;
#endif // !veriable_H_INCLUDED