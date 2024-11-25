#include "Hanoi.h"

int i,j,n,a,b;
//================= INISIALISASI ========================
SMALL_RECT Balok[3][7];

COORD O = {0,0};

CHAR_INFO F1[3], F2[5], F3[7], F4[9], F5[11], F6[13], F7[15], Ft[20],E1[3], E2[5], E3[7], E4[9], E5[11], E6[13], E7[15];

COORD Size[8];

CHAR_INFO *CC[15]={F1, F2, F3, F4, F5, F6, F7, Ft, E1, E2, E3, E4, E5, E6, E7};

SMALL_RECT Tf1 = {27, 10, 27, 20}, Tf2 = {47, 10, 47, 20}, Tf3 = {67, 10, 67, 20};

HANDLE Out()
{
	return (GetStdHandle(STD_OUTPUT_HANDLE));
}

//==================== MENU ========================

void PlayGame()
{
	
}

void LeaderBoard()
{
	
}

void Level()
{

}

void Latihan()
{
	int n,i,j,F,T;
	printf("Masukan Banyaknya Cakram :");
	scanf("%d", &n);
	int Tiang[4][7];
	for(j=0;j<7;j++)
	{
		for(i=0;i<2;i++)
		{
			Tiang[i][j] = j;	
		}
		for(i=2;i<4;i++)
		{
			Tiang[i][j] = 9;
		}
	}
	SetSmallRect(n);
	SetAwal(Out(), n);
	while (1)
	{
		printf("DARI : ");
		scanf("%d", &F);
		printf("PINDAH KE : ");
		scanf("%d", &T);
		Pindah(F,T, Tiang, n);
		Hapus(Out(), n);
		SetBatang(Tiang ,Out(), n);
	}
}


//===================== GAME PLAY ==========================

void SetBatang(int TA[4][7], HANDLE Out, int n)
{

	for (i=0;i<3;i++)
	{
		for (j=0;j<n;j++)
		{
			switch(TA[i+1][j])
			{
				case 0:
				Balok[i][0].Top = (19-n) + j;
				Balok[i][0].Bottom = (20-n) + j;
				WriteConsoleOutput(Out,CC[0],Size[0],O,&Balok[i][0]);
				break;
				
				case 1:
				Balok[i][1].Top = (19-n) + j;
				Balok[i][1].Bottom = (20-n) + j;
				WriteConsoleOutput(Out,CC[1],Size[1],O,&Balok[i][1]);
				break;
				
				case 2:
				Balok[i][2].Top = (19-n) + j;
				Balok[i][2].Bottom = (20-n) + j;
				WriteConsoleOutput(Out,CC[2],Size[2],O,&Balok[i][2]);
				break;
				
				case 3:
				Balok[i][3].Top = (19-n) + j;
				Balok[i][3].Bottom = (20-n) + j;
				WriteConsoleOutput(Out,CC[3],Size[3],O,&Balok[i][3]);
				break;
				
				case 4:
				Balok[i][4].Top = (19-n) + j;
				Balok[i][4].Bottom = (20-n) + j;
				WriteConsoleOutput(Out,CC[4],Size[4],O,&Balok[i][4]);
				break;
				
				case 5:
				Balok[i][5].Top = (19-n) + j;
				Balok[i][5].Bottom = (20-n) + j;
				WriteConsoleOutput(Out,CC[5],Size[5],O,&Balok[i][5]);
				break;
				
				case 6:
				Balok[i][6].Top = (19-n) + j;
				Balok[i][6].Bottom = (20-n) + j;
				WriteConsoleOutput(Out,CC[6],Size[6],O,&Balok[i][6]);
				break;
			}
		}
	}
}

void SetMudah()
{
	int n,i,j,F,T;
	SetSmallRect(4);
	SetAwal(Out(), 4);
	int Tiang[4][7];
	for(j=0;j<7;j++)
	{
		for(i=0;i<2;i++)
		{
			Tiang[i][j] = j;	
		}
		for(i=2;i<4;i++)
		{
			Tiang[i][j] = 9;
		}
	}
	while (1)
	{
		printf("DARI : ");
		scanf("%d", &F);
		printf("PINDAH KE : ");
		scanf("%d", &T);
		Pindah(F,T, Tiang, 4);
		Hapus(Out(), 4);
		SetBatang(Tiang ,Out(), 4);
	}
}

void SetSedang()
{
	int n,i,j,F,T;
	SetSmallRect(5);
	SetAwal(Out(), 5);
	int Tiang[4][7];
	for(j=0;j<7;j++)
	{
		for(i=0;i<2;i++)
		{
			Tiang[i][j] = j;	
		}
		for(i=2;i<4;i++)
		{
			Tiang[i][j] = 9;
		}
	}
	while (1)
	{
		printf("DARI : ");
		scanf("%d", &F);
		printf("PINDAH KE : ");
		scanf("%d", &T);
		Pindah(F,T, Tiang, 5);
		Hapus(Out(), 5);
		SetBatang(Tiang ,Out(), 5);
	}
}

void SetSulit()
{
	int n,i,j,F,T;
	SetSmallRect(6);
	SetAwal(Out(), 6);
	int Tiang[4][7];
	for(j=0;j<7;j++)
	{
		for(i=0;i<2;i++)
		{
			Tiang[i][j] = j;	
		}
		for(i=2;i<4;i++)
		{
			Tiang[i][j] = 9;
		}
	}
	while (1)
	{
		printf("DARI : ");
		scanf("%d", &F);
		printf("PINDAH KE : ");
		scanf("%d", &T);
		Pindah(F,T, Tiang, 6);
		Hapus(Out(), 6);
		SetBatang(Tiang ,Out(), 6);
	}
}

void SetLegend()
{
	int n,i,j,F,T;
	SetSmallRect(7);
	SetAwal(Out(), 7);
	int Tiang[4][7];
	for(j=0;j<7;j++)
	{
		for(i=0;i<2;i++)
		{
			Tiang[i][j] = j;	
		}
		for(i=2;i<4;i++)
		{
			Tiang[i][j] = 9;
		}
	}
	while (1)
	{
		printf("DARI : ");
		scanf("%d", &F);
		printf("PINDAH KE : ");
		scanf("%d", &T);
		Pindah(F,T, Tiang, 7);
		Hapus(Out(), 7);
		SetBatang(Tiang ,Out(), 7);
	}
}

void Pindah(int F, int T, int TA[4][7], int n)
{
	for(i=0; i<n ;i++)
	{
		if(TA[F][i] != 9)
		{
			a = i;
			break;
		}
	}
	for(i=0; i<n ;i++)
	{
		if(TA[T][i] != 9)
		{
			b = i;
			break;
		}
		else b = n;
	
	if (b == 7)
	{
		TA[T][b-1] = TA[F][a];
		TA[F][a] = 9;
	}
	else
	{
		if (TA[F][a] < TA[T][b] || TA[T][b] == 9)
		{
			TA[T][b-1] = TA[F][a];
			TA[F][a] = 9;
		}
	}

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
}

void SetAwal(HANDLE Out, int n)
{
	WriteConsoleOutput(Out,Ft,Size[7],O,&Tf1);
	WriteConsoleOutput(Out,Ft,Size[7],O,&Tf2);
	WriteConsoleOutput(Out,Ft,Size[7],O,&Tf3);
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
			Balok[i][j].Top = (19-n) + j;
			Balok[i][j].Left = (26+(20*i)) - j;
			Balok[i][j].Bottom= (20-n) + j;
			Balok[i][j].Right = (28+(20*i)) + j;
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
        E2[i].Attributes=7;j
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
    E7[7].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
   
}

void Hapus(HANDLE Out, int n)
{
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<n;j++)
		{
			WriteConsoleOutput(Out,CC[j+8],Size[j],O, &Balok[i][j]);
		}
	}
//	printf("Setting Balok");
}




