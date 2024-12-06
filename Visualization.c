#include "Hanoi.c"

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
