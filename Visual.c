#include "Hanoi.h"

int i,j,n;
//================= INISIALISASI GLOBAL ========================
SMALL_RECT Balok[3][7];

COORD O = {0,0};

CHAR_INFO F1[3], F2[5], F3[7], F4[9], F5[11], F6[13], F7[15], Ft[20],E1[3], E2[5], E3[7], E4[9], E5[11], E6[13], E7[15], FB[57];

COORD Size[9];

CHAR_INFO *CC[16]={F1, F2, F3, F4, F5, F6, F7, Ft, E1, E2, E3, E4, E5, E6, E7, FB};

SMALL_RECT Tf1 = {39, 15, 39, 25}, Tf2 = {59, 15, 59, 25}, Tf3 = {79, 15, 79, 25}, Tb = {31, 24, 88, 24};

HANDLE Out()
{
	return (GetStdHandle(STD_OUTPUT_HANDLE));
}

void gotoxy(int x, int y) 
{
  COORD Point;
  Point.X = x;
  Point.Y = y;
  SetConsoleCursorPosition(Out(), Point);
}

//=============== VISUAL ===================
void SizeRect()
{
    Size[0] = (COORD){3, 1};
    Size[1] = (COORD){5, 1};
    Size[2] = (COORD){7, 1};
    Size[3] = (COORD){9, 1};
    Size[4] = (COORD){11, 1};
    Size[5] = (COORD){13, 1};
    Size[6] = (COORD){15, 1};
	Size[7] = (COORD){1, 10};
	Size[8] = (COORD){57, 1};
}

void SetAwal(HANDLE Out, int n)
{
	WriteConsoleOutput(Out,Ft,Size[7],O,&Tf1);
	WriteConsoleOutput(Out,Ft,Size[7],O,&Tf2);
	WriteConsoleOutput(Out,Ft,Size[7],O,&Tf3);
	WriteConsoleOutput(Out,FB,Size[8],O,&Tb);
	for (j=0; j<n; j++)
	{
		WriteConsoleOutput(Out,CC[j],Size[j],O, &Balok[0][j]);
	}	

}

void SetSmallRect(int n)
{
	int i,j;
	for (i = 0; i<3;i++)
	{
		for(j=0;j<n;j++)
		{
			Balok[i][j].Top = (24-n) + j;
			Balok[i][j].Left = (38+(20*i)) - j;
			Balok[i][j].Bottom= (25-n) + j;
			Balok[i][j].Right = (40+(20*i)) + j;
		}
	}

}

void SetChar()
{
	for(i=0; i<10; i++)
	{
		Ft[i].Char.AsciiChar = 219; 
		Ft[i].Attributes = FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
	}
	
	for(i=0; i<3; i++)
	{
		F1[i].Char.AsciiChar = 219; 
		F1[i].Attributes = 7;
	}
	
	for(i=0; i<5; i++)
	{
		F2[i].Char.AsciiChar = 219; 
		F2[i].Attributes = 8;
	}
	
	for(i=0; i<7; i++)
	{
		F3[i].Char.AsciiChar = 219; 
		F3[i].Attributes = 9;
	}
	
	for(i=0; i<9; i++)
	{
		F4[i].Char.AsciiChar = 219; 
		F4[i].Attributes = 10;
	}
	
	for(i=0; i<11; i++)
	{
		F5[i].Char.AsciiChar = 219; 
		F5[i].Attributes = 11;
	}
	
	for(i=0; i<13; i++)
	{
		F6[i].Char.AsciiChar = 219; 
		F6[i].Attributes = 12;
	}
	
	for(i=0; i<15; i++)
	{
		F7[i].Char.AsciiChar = 219; 
		F7[i].Attributes = 13;
	}
	
 	for(i=0;i<3;i++)
    {
        E1[i].Char.AsciiChar=' ';
        E1[i].Attributes=7;
    }
    E1[1].Char.AsciiChar= 219;
    E1[1].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    
    for(i=0;i<5;i++)
    {
        E2[i].Char.AsciiChar=' ';
        E2[i].Attributes=7;
    }
    E2[2].Char.AsciiChar= 219;
    E2[2].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    
    for(i=0;i<7;i++)
    {
        E3[i].Char.AsciiChar=' ';
        E3[i].Attributes=7;
    }
    E3[3].Char.AsciiChar= 219;
    E3[3].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    
	for(i=0;i<9;i++)
    {
        E4[i].Char.AsciiChar=' ';
        E4[i].Attributes=7;
    }
    E4[4].Char.AsciiChar= 219;
    E4[4].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    
    for(i=0;i<11;i++)
    {
        E5[i].Char.AsciiChar=' ';
        E5[i].Attributes=7;
    }
    E5[5].Char.AsciiChar= 219;
    E5[5].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    
    for(i=0;i<13;i++)
    {
        E6[i].Char.AsciiChar=' ';
        E6[i].Attributes=7;
    }
    E6[6].Char.AsciiChar= 219;
    E6[6].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    
    for(i=0;i<15;i++)
    {
    	E7[i].Char.AsciiChar= ' ';
    	E7[i].Attributes=7;
	}
	E7[7].Char.AsciiChar= 219;
    E7[7].Attributes= FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    for(i=0;i<57;i++)
    {
    	FB[i].Char.AsciiChar= 219;
    	FB[i].Attributes= FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
	}
}

void clearLine(int y)
{
	for(i=0;i<y;i++)
    printf(" ");
}

void GameOver()
{
	system("cls");
	gotoxy(35,6);printf("   %c%c%c%c%c%c%c%c       %c%c%c%c        %c%c%c    %c%c%c     %c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,7);printf(" %c%c%c%c    %c%c      %c%c  %c%c      %c%c %c%c  %c%c %c%c    %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,8);printf("%c%c%c             %c%c    %c%c    %c%c   %c%c%c%c   %c%c   %c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,9);printf("%c%c%c     %c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c    %c%c    %c%c   %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,10);printf(" %c%c%c%c    %c%c    %c%c      %c%c   %c%c          %c%c   %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,11);printf("   %c%c%c%c%c%c%c%c    %c%c      %c%c   %c%c          %c%c   %c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,12);printf("\n");
	gotoxy(35,13);printf("     %c%c%c%c%c%c%c     %c%c     %c%c   %c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,14);printf("    %c%c%c   %c%c%c    %c%c     %c%c   %c%c          %c%c     %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,15);printf("   %c%c       %c%c    %c%c   %c%c    %c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,16);printf("   %c%c       %c%c    %c%c   %c%c    %c%c          %c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,17);printf("    %c%c%c   %c%c%c      %c%c %c%c     %c%c          %c%c %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,18);printf("     %c%c%c%c%c%c%c       %c%c%c%c%c     %c%c%c%c%c%c%c%c%c   %c%c   %c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	PlaySound("GameOver.wav", NULL, SND_FILENAME | SND_SYNC);

	Sleep(500);
}

void Win()
{
	PlaySound("Win.wav", NULL, SND_FILENAME | SND_ASYNC);
	system("cls");
	gotoxy(35,6);printf("%c%c    %c%c     %c%c%c%c    %c%c    %c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,7);printf(" %c%c  %c%c     %c%c  %c%c   %c%c    %c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,8);printf("  %c%c%c%c     %c%c    %c%c  %c%c    %c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,9);printf("   %c%c      %c%c    %c%c  %c%c    %c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,10);printf("   %c%c       %c%c  %c%c    %c%c  %c%c   %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,11);printf("   %c%c        %c%c%c%c      %c%c%c%c    %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,12);printf("                               %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219);
	gotoxy(35,13);printf("%c%c          %c%c  %c%c  %c%c%c    %c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,14);printf("%c%c          %c%c  %c%c  %c%c%c%c   %c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,15);printf("%c%c    %c%c    %c%c  %c%c  %c%c %c%c  %c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,16);printf("%c%c   %c%c%c%c   %c%c  %c%c  %c%c  %c%c %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,17);printf(" %c%c %c%c  %c%c %c%c   %c%c  %c%c   %c%c%c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(35,18);printf("  %c%c%c    %c%c%c    %c%c  %c%c    %c%c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	
	Sleep(5000);
}

void GetNama(char Nama[50])
{
    gotoxy(30,11);printf("============================================================");
	gotoxy(30,12);printf("|                   Masukkan Nama Player                   |");
	gotoxy(30,13);printf("============================================================");
	gotoxy(30,14);printf("|                                                          |");
    gotoxy(30,15);printf("============================================================");
    gotoxy(32,14);fgets(Nama, 50, stdin);
    Nama[strcspn(Nama, "\n")] = '\0';
    system("cls");
}

void DisplayOption(int n,int M, char *options[M])
{
	gotoxy(30,13);printf("============================================================");
	for(i=0;i<M+2;i++)
	{
		gotoxy(30,14+i);printf("|                                                          |");
	}
	gotoxy(30,16+M);printf("============================================================");
    for (i = 0; i < M; i++) {
        if (i == n) {
            gotoxy(50,15+i);printf("\033[1;37;46m%-20s\033[0m ", options[i]); // Menyoroti opsi yang dipilih
        } else {
            gotoxy(50,15+i);printf("%s", options[i]);
        }
    }
}

int GetAksi()
{
	int Aksi;
	while(1)
	{
		Aksi = getch() - 48;
		if(Aksi > 3 || Aksi < 1)
		{
			if(Aksi== -21)
			{
				return 0;
			}
			else
			{
			gotoxy(35,28);printf("Invalid input!");
			Beep(350,300);
			gotoxy(35,28);clearLine(100);
			continue;		
			}
		}else
		{
			break;
		}	
	}
	return Aksi;
}
