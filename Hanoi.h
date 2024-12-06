#ifndef Hanoi_H
#define Hanoi_H
#include <stdio.h>
#include <windows.h>

//=========================================== GamePlay.c ===============================================
HANDLE Out();

//Menu
void PlayGame();

void LeaderBoard();

//Score
void ReadText(FILE *fp);


//Gameplay
void Easy();

void Medium();

void Hard();

void Legend();

void Latihan();

void Pindah(int F, int T, int TA[4][7], int m);

//================================================ Visual.c ===================================================================

extern COORD O;

extern CHAR_INFO F1[3], F2[5], F3[7], F4[9], F5[11], F6[13], F7[15], Ft[20],E1[3], E2[5], E3[7], E4[9], E5[11], E6[13], E7[15];

extern COORD Size[8];

extern CHAR_INFO *CC[15];

extern SMALL_RECT Tf1, Tf2 , Tf3;

void clearLine(int y);

void gotoxy(int x, int y);

void music();

void SizeRect();

void SetAwal(HANDLE Out, int n);

void SetSmallRect(int n);

void SetChar();


//============================================ File Manipulation.c ====================================================



#endif



