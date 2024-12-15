#ifndef Hanoi_H
#define Hanoi_H
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#define NAMA_FILE "LeaderBoard.dat"

typedef struct{
	char Nama[50];
	int Menit;
	int Detik;
	int SisaLangkah;
	int Level;
	float Score;
}Player;

HANDLE Out();

void gotoxy(int x, int y);

//Menu

void PlayGame();

void LeaderBoard();

bool HowToPlay(int A);

void Credits();

void Latihan();

short GetCakram();

//Gameplay

void Permainan(char Nama[50], int Cakram, int Langkah, int Pilihan);

void Pindah(int F, int T, int Cakram, int Tiang[3][Cakram], HANDLE Out, bool *cek);

//Visual

extern COORD O;

extern CHAR_INFO F1[3], F2[5], F3[7], F4[9], F5[11], F6[13], F7[15], Ft[20],E1[3], E2[5], E3[7], E4[9], E5[11], E6[13], E7[15], FB[57];

extern COORD Size[9];

extern CHAR_INFO *CC[16];

extern SMALL_RECT Tf1, Tf2 , Tf3, Tb;

void SizeRect();

void SetAwal(HANDLE Out, int n);

void SetSmallRect(int n);

void SetChar();

void clearLine(int y);

void GameOver();

void Win();

void GetNama(char Nama[50]);

void DisplayOption(int n,int M, char *options[M]);

int GetAksi();


//saving file

void inputData(char nama[], int detik, int langkah, int Pilihan);

void tampilData(Player y[50], int n);

void urutkanData(Player a[], int n, int Pilihan);

//Score

float Scoring(int Langkah, int Kecepatan, int Pilihan);

//Thread
void HitungWaktu();

short threadWaktu(bool kondisi);

HANDLE Mutex;

void MUTEX(bool mutexb);

#endif


