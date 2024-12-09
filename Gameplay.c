#include "Hanoi.h"

//================= INISIALISASI GLOBAL ========================

int i,j,n;

SMALL_RECT Balok[3][7];


//==================== MENU ========================

void PlayGame()
{
	char name[50];
	int n = 0;
	char *options[5] =
		{
	        "EASY",
	        "MEDIUM",
	        "HARD",
	        "LEGEND",
	        "BACK TO MENU"
	    };
	    int key;
	    while (1)
		{
	        system("cls");  // Membersihkan layar
			gotoxy(30,10);printf("============================================================");
			gotoxy(30,11);printf("|                       PILIH LEVEL                        |");
	        DisplayOption(n,5, options);

	        key = getch();

	        if (key == 0 || key == 224) {
	            key = getch();  // Menangani input panah atas dan bawah

	            if (key == 72) {  // Panah atas
	                n = (n - 1 + 5) % 5;
	            } else if (key == 80) {  // Panah bawah
	                n = (n + 1) % 5;
	            }
	        } else if (key == 13) {  // Enter
	            break;
	        }
	    }
		if (HowToPlay(n))
		{
			return;
		}
		switch (n)
		{
            case 0 :
                system("cls");
                GetNama(name);
                Easy(name);
                system("cls");
                return;
            case 1 :
            	system("cls");
                GetNama(name);
                Medium(name);
                system("cls");
                return;
            case 2 :
            	system("cls");
                GetNama(name);
                Hard(name);
                system("cls");
                return;
            case 3 :
            	system("cls");
                GetNama(name);
                Legend(name);
                system("cls");
                return;
            case 4 :
                system("cls");
                return;
        }
}

void LeaderBoard()
{
	Player y[50];
	int i,j,n = 0;
	char choice;
	FILE *file = fopen(NAMA_FILE, "rb");

    if (file == NULL) {
        printf("File baru saja dibuat. Silakan input ulang.\n");
      	file = fopen(NAMA_FILE,"wb");
        return;
    }

    while (fread(&y[n], sizeof(Player), 1, file)) {
        n++;
    }
    fclose(file);
    
    tampilData(y,n);
    while(1)
    {
    	gotoxy(37,4);printf("=========== Sort Leaderboard ===========");
		gotoxy(46,5);printf("1. Urut berdasarkan waktu\n");
		gotoxy(46,6);printf("2. Urut berdasarkan langkah\n");
		gotoxy(46,7);printf("3. Back to Menu\n");
		gotoxy(37,8);printf("================ Sort by ================");
        gotoxy(50,9);choice = getch();
	    switch (choice)
	    {
	    	case '1' :
	    		urutkan(y, n, 1);
				break;
			case '2' :
				urutkan(y, n, 2);
				break;
			case '3' :
				system("cls");
				return;
			default:
                system("cls");
                printf("\nPilihan level tidak valid. Silakan coba lagi.\n");
                break;
			
		}
	}
    
}

bool HowToPlay(int A)
{
	system("cls");
	gotoxy(10, 4);	printf("Mohon baca dengan seksama sebelum mulai permainan!");
	gotoxy(10, 5);	printf("Level : ");
	
	char B[7];
	switch (A) {
		case 0 :
			printf("Easy");
			strcpy(B, "keempat");
			break;
		case 1 :
			printf("Medium");
			strcpy(B, "kelima");
			break;
		case 2 :
			printf("Hard");
			strcpy(B, "keenam");
			break;
		case 3:
			printf("Legend");
			strcpy(B, "ketujuh");
			break;
	}

	gotoxy(10, 6);	printf("1. 	Tujuan Permainan");
	gotoxy(10, 7);	printf("	Anda ditugaskan untuk memindahkan %s cakram yang tersusun secara berurut di tiang paling", B);
	gotoxy(10, 8);	printf("	kiri ke tiang paling kanan.");
	
	gotoxy(10, 10);	printf("2. 	Batas Langkah");
	gotoxy(10, 11);	printf("	Langkah minimal untuk menyelesaikan permainan adalah %d langkah. Anda memiliki batas maksimal " , (int) pow(2, A + 4) - 1);
	gotoxy(10, 12);	printf("	%d langkah untuk menyelesaikan permainan.", (int) pow(2, A + 4) + 2 * ( 3 - A) - 1);
	
	gotoxy(10, 14);	printf("3. 	Aturan Main");
	gotoxy(10, 15);	printf("	Hanya satu cakram yang dapat dipindahkan dalam satu langkah. Cakram tidak boleh ditumpuk di");
	gotoxy(10, 16);	printf("	atas cakram yang lebih kecil.");
	
	gotoxy(10, 18);	printf("4.	Status Menang dan Kalah");
	gotoxy(10, 19);	printf("	Anda dinyatakan menang apabila berhasil memindahkan %s cakram ke tiang paling kanan ", B);
	gotoxy(10, 20);	printf("	secara berurutan dengan langkah kurang dari sama dengan %d. Sebaliknya, anda akan dinyatakan", (int) pow(2, A + 4) + 2 * ( 3 - A) - 1);
	gotoxy(10, 21); printf("	kalah apabila langkah telah melebihi %d sebelum menyelesaikan permainan.", (int) pow(2, A + 4) + 2 * ( 3 - A) - 1);
	
	gotoxy(10, 23);	printf("5.	Sistem Skor");
	gotoxy(10, 24);	printf("	Skor ditentukan berdasarkan waktu. Pemain yang menyelesaikan permainan dengan waktu tercepat");
	gotoxy(10, 25); printf("	akan menjadi pemain teratas dalam papan skor.");
	
	gotoxy(48, 28); printf("Press enter to continue!");
	gotoxy(44, 29); printf("Press esc to go back to Menu!");
	gotoxy(119, 29);
	int x = getch();
	system("cls");
	while (1) {
		if (x == '\r') { //Jika character input player sama dengan Enter
			return false;
		}
		if (x == 27) { //Jika character input player sama dengan ESC
			return true;
		}
	}
}

void Credits()
{
	system("cls");
	gotoxy(54, 2);	printf("Credits game");
	gotoxy(52, 3);	printf("Perguruan tinggi");
	gotoxy(48, 4);	printf("Politeknik Negeri Bandung");
			
	gotoxy(57, 6);	printf("Member:");
	gotoxy(41, 7);	printf("Muhammad Nabil Syauqi Rasyiq 241524018");
	gotoxy(46, 8);	printf("Ivan Setiawan Ihsan 241524012");
	gotoxy(46, 9);	printf("Faris Ichsan Alyawa 241524010");	
	
	gotoxy(53, 11);	printf("Music Producer:");
	gotoxy(46, 12);	printf("Muhammad Nabil Syauqi Rasyiq");
	
	gotoxy(53, 14);	printf("Sound Director:");
	gotoxy(46, 15);	printf("Muhammad Nabil Syauqi Rasyiq");
	
	gotoxy(51, 17);	printf("Graphics Producer:");
	
	gotoxy(54, 19);	printf("Art Producer:");
	
	gotoxy(50, 20);	printf("Programming Producer:");
	
	gotoxy(53, 22);	printf("Game Designer:");
		
	gotoxy(55, 24);	printf("Reference:");
	gotoxy(51, 25);	printf("1. Ludo Imam Syafi");
	gotoxy(44, 26);	printf("2. Shivam Shekhar tower of hanoi");
	
	gotoxy(54, 28);	printf("Music Source:");
	gotoxy(49, 29);	printf("Zamrud Khatulistiwa.wav");
	
	gotoxy(49, 31); printf("Press enter to continue!");
	gotoxy(119, 39);
	while (1) {
		if (getch() == '\r') {
			break;
		}
	}
	system("cls");
}

void Latihan()
{
	int Cakram, Move, Waktu, Asal, Tujuan;
	int Tiang[3][7];
	Cakram = GetCakram();
	if (Cakram == 0 || HowToPlay(Cakram - 4)) {
		return;
	}
	gotoxy(35,6);Waktu = threadWaktu(true);
	for(j=0;j<7;j++)
	{
		for(i=0;i<1;i++)
		{
			Tiang[i][j] = j;
		}
		for(i=1;i<3;i++)
		{
			Tiang[i][j] = 9;
		}
	}

	SetSmallRect(Cakram);
	SetAwal(Out(), Cakram);
	Move = 0;

	while(1)
	{
		bool Check = false;
 		gotoxy(35,5);printf("Total Move : %d  ", Move);
		while(1)
		{
			gotoxy(35,27);clearLine(100);
			gotoxy(35,27);printf("Pindah dari tiang ");
	        gotoxy(53,27);Asal=getch()-48;
	        if(Asal== -21)
			{
				threadWaktu(false);
				return;
			}
	        gotoxy(53,27);printf("%d", Asal);
	        gotoxy(55,27);printf("ke Tiang ");
	        gotoxy(64,27);Tujuan = getch()-48;
	        gotoxy(64,27);printf("%d",Tujuan);
	        gotoxy(35,28);printf("Jika Yakin Tekan Enter!");
	        gotoxy(35,28);clearLine(100);

	    	if(getch()==13)
	    	{
	    		gotoxy(35,28);clearLine(100);
	                if(Asal>3 || Asal<1 || Tujuan>3 || Tujuan<1)
	                {
	                	PlaySound("SalahInput.wav", NULL, SND_FILENAME | SND_ASYNC);
	                    gotoxy(35,28);printf("invalid input!!!");
	                    Sleep(300);
	                    gotoxy(35,28);clearLine(100);
	                    continue;
	                }
	                else
	                    break;
	        }
		}

		Pindah(Asal-1,Tujuan-1, Tiang, Cakram, Out(), &Check);
		if(Tiang[2][0]==0)
		{
			Waktu = threadWaktu(false);
			break;
		}
		if(Check)Move++;
	}
	system("cls");
}

short GetCakram()
{
		int n = 0;
		char *options[6] =
		{
	        "III Cakram",
	        "IV Cakram",
	        "V Cakram",
	        "VI Cakram",
	        "VII Cakram",
	        "Back to Menu"
	    };
	    int key;

	    while (1)
		{
	        system("cls");  // Membersihkan layar
	        gotoxy(30,10);printf("============================================================");
			gotoxy(30,11);printf("|                   PILIH JUMLAH CAKRAM                    |");
	        DisplayOption(n,6, options);

	        key = getch();

	        if (key == 0 || key == 224) {
	            key = getch();  // Menangani input panah atas dan bawah

	            if (key == 72) {  // Panah atas
	                n = (n - 1 + 6) % 6;
	            } else if (key == 80) {  // Panah bawah
	                n = (n + 1) % 6;
	            }
	        } else if (key == 13) {  // Enter
	            break;
	        }
	    }
	    switch (n)
		{
            case 0 :
                system("cls");
                return n+3;
            case 1 :
                system("cls");
                return n+3;
            case 2 :
                system("cls");
                return n+3;
            case 3 :
                system("cls");
                return n+3;
            case 4 :
                system("cls");
                return n+3;
            case 5 :
                system("cls");
                return 0;
        }
}
//===================== GAME PLAY ==========================

void Easy(char Nama[50])
{
	int Move, Waktu, Asal, Tujuan;
	int Tiang[3][7];
	gotoxy(35,6);Waktu = threadWaktu(true);
	for(j=0;j<7;j++)
	{
		for(i=0;i<1;i++)
		{
			Tiang[i][j] = j;	
		}
		for(i=1;i<3;i++)
		{
			Tiang[i][j] = 9;
		}
	}

	SetSmallRect(4);
	SetAwal(Out(), 4);
	Move = 21;
	
	while(1)
	{
		bool Check = false;
		gotoxy(35,5);printf("Remaining Move : %d  ", Move);
		while(1)
		{
			gotoxy(35,27);clearLine(100);
			gotoxy(35,27);printf("Pindah dari tiang ");
	        gotoxy(53,27);Asal=getch()-48;
	        if(Asal== -21)
			{
				threadWaktu(false);
				return;
			}
	        gotoxy(53,27);printf("%d", Asal);
	        gotoxy(55,27);printf("ke Tiang ");
	        gotoxy(64,27);Tujuan = getch()-48;
	        gotoxy(64,27);printf("%d",Tujuan);
	        gotoxy(35,28);printf("Jika Yakin Tekan Enter!");
	        gotoxy(35,28);clearLine(100);
	        
	    	if(getch()==13)
	    	{
	    		gotoxy(35,28);clearLine(100);
	                if(Asal>3 || Asal<1 || Tujuan>3 || Tujuan<1)
	                {
	                	Beep(626, 250);  // Bunyi pertama
    					Beep(1315, 250);
//	                	PlaySound("SalahInput.wav", NULL, SND_FILENAME | SND_ASYNC);
	                    gotoxy(35,28);printf("invalid input!!!");
	                    Sleep(300);
	                    gotoxy(35,28);clearLine(100);
	                    continue;
	                }
	                else
	                    break;
	        }
		}
		
		Pindah(Asal-1,Tujuan-1, Tiang, 4, Out(), &Check);
		if(Tiang[2][0]==0)
		{
			Waktu = threadWaktu(false);
			break;
		}
		if(Check)Move--;
		if(Move <= 0)
		{
			Waktu = threadWaktu(false);
			break;
		}
	}
	
	if(Move <= 0)
	{
		GameOver();
	}
	else
	{
		inputData(Nama, Waktu, Move);
		Win();
	}
}

void Medium(char Nama[50])
{
    int Move, Waktu, Asal, Tujuan;
	int Tiang[3][7];
	gotoxy(41,6);Waktu = threadWaktu(true);
	for(j=0;j<7;j++)
	{
		for(i=0;i<1;i++)
		{
			Tiang[i][j] = j;
		}
		for(i=1;i<3;i++)
		{
			Tiang[i][j] = 9;
		}
	}

	SetSmallRect(5);
	gotoxy(35,6);printf("Time");
	SetAwal(Out(), 5);
	Move = 31;

	while(1)
	{
		bool Check = false;
		gotoxy(35,5);printf("Remaining Move : %d  ", Move);
		while(1)
		{
			gotoxy(35,27);clearLine(100);
			gotoxy(35,27);printf("Pindah dari tiang ");
	        gotoxy(53,27);Asal=getch()-48;
	        if(Asal== -21)
			{
				threadWaktu(false);
				return;
			}
	        gotoxy(53,27);printf("%d", Asal);
	        gotoxy(55,27);printf("ke Tiang ");
	        gotoxy(64,27);Tujuan = getch()-48;
	        gotoxy(64,27);printf("%d",Tujuan);
	        gotoxy(35,28);printf("Jika Yakin Tekan Enter!");
	        gotoxy(35,28);clearLine(100);

	    	if(getch()==13)
	    	{
	    		gotoxy(35,28);clearLine(100);
	                if(Asal>3 || Asal<1 || Tujuan>3 || Tujuan<1)
	                {
	                	PlaySound("SalahInput.wav", NULL, SND_FILENAME | SND_ASYNC);
	                    gotoxy(35,28);printf("invalid input!!!");
	                    Sleep(300);
	                    gotoxy(35,28);clearLine(100);
	                    continue;
	                }
	                else
	                    break;
	        }
		}

		Pindah(Asal-1,Tujuan-1, Tiang, 5, Out(), &Check);
		if(Tiang[2][0]==0)
		{
			Waktu = threadWaktu(false);
			break;
		}
		if(Check)Move--;
		if(Move <= 0)
		{
			Waktu = threadWaktu(false);
			break;
		}
	}

	if(Move <= 0)
	{
		GameOver();
	}
	else
	{
		inputData(Nama, Waktu, Move);
		Win();
	}
}

void Hard(char Nama[50])
{
	int Move, Waktu, Asal, Tujuan;
	int Tiang[3][7];
	gotoxy(41,6);Waktu = threadWaktu(true);
	for(j=0;j<7;j++)
	{
		for(i=0;i<1;i++)
		{
			Tiang[i][j] = j;
		}
		for(i=1;i<3;i++)
		{
			Tiang[i][j] = 9;
		}
	}

	SetSmallRect(6);
	gotoxy(35,6);printf("Time");
	SetAwal(Out(), 6);
	Move = 65;

	while(1)
	{
		bool Check = false;
		gotoxy(35,5);printf("Remaining Move : %d  ", Move);
		while(1)
		{
			gotoxy(35,27);clearLine(100);
			gotoxy(35,27);printf("Pindah dari tiang ");
	        gotoxy(53,27);Asal=getch()-48;
	        if(Asal== -21)
			{
				threadWaktu(false);
				return;
			}
	        gotoxy(53,27);printf("%d", Asal);
	        gotoxy(55,27);printf("ke Tiang ");
	        gotoxy(64,27);Tujuan = getch()-48;
	        gotoxy(64,27);printf("%d",Tujuan);
	        gotoxy(35,28);printf("Jika Yakin Tekan Enter!");
	        gotoxy(35,28);clearLine(100);

	    	if(getch()==13)
	    	{
	    		gotoxy(35,28);clearLine(100);
	                if(Asal>3 || Asal<1 || Tujuan>3 || Tujuan<1)
	                {
	                	PlaySound("SalahInput.wav", NULL, SND_FILENAME | SND_ASYNC);
	                    gotoxy(35,28);printf("invalid input!!!");
	                    Sleep(300);
	                    gotoxy(35,28);clearLine(100);
	                    continue;
	                }
	                else
	                    break;
	        }
		}

		Pindah(Asal-1,Tujuan-1, Tiang, 6, Out(), &Check);
		if(Tiang[2][0]==0)
		{
			Waktu = threadWaktu(false);
			break;
		}
		if(Check)Move--;
		if(Move <= 0)
		{
			Waktu = threadWaktu(false);
			break;
		}
	}

	if(Move <= 0)
	{
		GameOver();
	}
	else
	{
		inputData(Nama, Waktu, Move);
		Win();
	}
}

void Legend(char Nama[50])
{	
	int Move, Waktu, Asal, Tujuan;
	int Tiang[3][7];
	gotoxy(41,6);Waktu = threadWaktu(true);
	for(j=0;j<7;j++)
	{
		for(i=0;i<1;i++)
		{
			Tiang[i][j] = j;
		}
		for(i=1;i<3;i++)
		{
			Tiang[i][j] = 9;
		}
	}

	SetSmallRect(7);
	gotoxy(35,6);printf("Time");
	SetAwal(Out(),7);
	Move = 127;

	while(1)
	{
		bool Check = false;
		gotoxy(35,5);printf("Remaining Move : %d  ", Move);
		while(127)
		{
			gotoxy(35,27);clearLine(100);
			gotoxy(35,27);printf("Pindah dari tiang ");
	        gotoxy(53,27);Asal=getch()-48;
	        if(Asal== -21)
			{
				threadWaktu(false);
				return;
			}
	        gotoxy(53,27);printf("%d", Asal);
	        gotoxy(55,27);printf("ke Tiang ");
	        gotoxy(64,27);Tujuan = getch()-48;
	        gotoxy(64,27);printf("%d",Tujuan);
	        gotoxy(35,28);printf("Jika Yakin Tekan Enter!");
	        gotoxy(35,28);clearLine(100);

	    	if(getch()==13)
	    	{
	    		gotoxy(35,28);clearLine(100);
	                if(Asal>3 || Asal<1 || Tujuan>3 || Tujuan<1)
	                {
	                	PlaySound("SalahInput.wav", NULL, SND_FILENAME | SND_ASYNC);
	                    gotoxy(35,28);printf("invalid input!!!");
	                    Sleep(300);
	                    gotoxy(35,28);clearLine(100);
	                    continue;
	                }
	                else
	                    break;
	        }
		}

		Pindah(Asal-1,Tujuan-1, Tiang, 7, Out(), &Check);
		if(Tiang[2][0]==0)
		{
			Waktu = threadWaktu(false);
			break;
		}
		if(Check)Move--;
		if(Move <= 0)
		{
			Waktu = threadWaktu(false);
			break;
		}
	}

	if(Move <= 0)
	{
		GameOver();
	}
	else
	{
		inputData(Nama, Waktu, Move);
		Win();
	}
}

void Pindah(int F, int T, int TA[3][7], int n, HANDLE Out, bool *cek)
{
	int a,b;
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
	}
	
	if (b == n)
	{
		PlaySound("BerhasilPindah.wav", NULL, SND_FILENAME | SND_ASYNC);
		TA[T][b-1] = TA[F][a];
		TA[F][a] = 9;
		*cek = true;
	}
	else
	{
		if (TA[F][a] < TA[T][b] || (TA[T][b] == 9) && (TA[F][b] != 9))
		{
			PlaySound("BerhasilPindah.wav", NULL, SND_FILENAME | SND_ASYNC);
			TA[T][b-1] = TA[F][a];
			TA[F][a] = 9;
			*cek = true;
		}
		else
		{
			PlaySound("Berhasil.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
	}
		if (b == 0){
			b++;
		}
		
		Balok[T][TA[T][b-1]].Top = (24-n) + b-1;
		Balok[T][TA[T][b-1]].Bottom = (25-n) + b-1;
		WriteConsoleOutput(Out,CC[TA[T][b-1]+8],Size[TA[T][b-1]],O,&Balok[F][TA[T][b-1]]);
		WriteConsoleOutput(Out,CC[TA[T][b-1]],Size[TA[T][b-1]],O,&Balok[T][TA[T][b-1]]);
}
