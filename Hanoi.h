#ifndef Hanoi_H
#define Hanoi_H
#include <stdio.h>
#include <windows.h>


HANDLE Out();

///////////////////////////////////////////////////////////////////////////////
//Player
//char* GetNama(Player *P);
//
//int GetScore(Player *P);
//
//void Nama(Player *P);

//Menu
void PlayGame();

void LeaderBoard();

void Level();

//Score
void ReadText(FILE *fp);


//Gameplay
void SetMudah();

void SetSedang();

void SetSulit();

void SetLegend();

void Latihan();

void Pindah(int F, int T, int TA[4][7], int m);

//Visual

extern COORD O;

extern CHAR_INFO F1[3], F2[5], F3[7], F4[9], F5[11], F6[13], F7[15], Ft[20],E1[3], E2[5], E3[7], E4[9], E5[11], E6[13], E7[15];

extern COORD Size[8];

extern CHAR_INFO *CC[15];

extern SMALL_RECT Tf1, Tf2 , Tf3;

void Hapus(HANDLE Out, int m);

void clearLine(int y);

void gotoxy(int x, int y);

void music();

void SizeRect();

void SetAwal(HANDLE Out, int n);

void SetSmallRect(int n);

void SetChar();

void SetBatang(int TA[4][7], HANDLE Out, int n);





#endif



