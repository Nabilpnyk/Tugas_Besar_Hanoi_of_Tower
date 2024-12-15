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
			gotoxy(30,11);printf("============================================================");
			gotoxy(30,12);printf("|                       PILIH LEVEL                        |");
	        DisplayOption(n,5, options);

	        key = getch();

	        if (key == 0 || key == 224) {
	            key = getch();  // Menangani input panah atas dan bawah

	            if (key == 72) {  // Panah atas
	                n = (n - 1 + 5) % 5;
	                Beep(1200,150);
	            } else if (key == 80) {  // Panah bawah
	                n = (n + 1) % 5;
	                Beep(1200,150);
	            }
	        } else if (key == 13) {  // Enter
				Beep(600,150);
	            break;
	        }
	    }
		switch (n)
		{
            case 0 :
                system("cls");
                if (HowToPlay(n))
				{
					return;
				}
                GetNama(name);
				Permainan(name, 4, 21, n);
                system("cls");
                return;
            case 1 :
            	system("cls");
                if (HowToPlay(n))
				{
					return;
				}
                GetNama(name);
				Permainan(name, 5, 35, n);
                system("cls");
                return;
            case 2 :
            	system("cls");
                if (HowToPlay(n))
				{
					return;
				}
				GetNama(name);
				Permainan(name, 6, 65, n);
                system("cls");
                return;
            case 3 :
            	system("cls");
                if (HowToPlay(n))
				{
					return;
				}
				GetNama(name);
				Permainan(name, 7, 127, n);
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
		gotoxy(46,7);printf("3. Urut berdasarkan score\n");
		gotoxy(46,8);printf("4. Back to Menu\n");
		gotoxy(37,9);printf("================ Sort by ================");
        gotoxy(50,10);choice = getch();
	    switch (choice)
	    {
	    	case '1' :
	    		urutkanData(y, n, 1);
	    		Beep(600,300);
				break;
			case '2' :
				urutkanData(y, n, 2);
				Beep(600,300);
				break;
			case '3' :
				urutkanData(y, n, 3);
				Beep(600,300);
				break;
			case '4':
				system("cls");
				return;
			default:
                gotoxy(50,10);printf("Invalid Input!");
                Beep(1372,300);
                gotoxy(50,10);clearLine(15);
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
	int x;
	while (1) {
		x = getch();
		if (x == '\r') { //Jika character input player sama dengan Enter
			system("cls");
			return false;
		}
		if (x == 27) { //Jika character input player sama dengan ESC
			system("cls");
			return true;
		}
	}
}

void Credits()
{
	system("cls");
	gotoxy(54, 7);	printf("Credits game");
	gotoxy(52, 8);	printf("Perguruan tinggi");
	gotoxy(48, 9);	printf("Politeknik Negeri Bandung")	;
	
	gotoxy(53, 11);	printf("Game Designer:");
	gotoxy(41, 12);	printf("Muhammad Nabil Syauqi Rasyiq 241524018");
	gotoxy(46, 13);	printf("Ivan Setiawan Ihsan 241524012");
	gotoxy(46, 14);	printf("Faris Ichsan Alyawa 241524010");
		
	gotoxy(52, 16);	printf("Game Reference:");
	gotoxy(51, 17);	printf("1. Ludo Imam Syafi");
	gotoxy(44, 18);	printf("2. Shivam Shekhar tower of hanoi");
	
	gotoxy(50, 20);	printf("Backsound Reference:");
	gotoxy(50, 21);	printf("https://pixabay.com/");

	
	gotoxy(49, 29); printf("Press enter to continue!");
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
	MUTEX(true);
    
	int Cakram, Move, Waktu, Asal, Tujuan;
	Cakram = GetCakram();
	if (Cakram == 0) {
		return;
	}
    if (HowToPlay(Cakram - 4)) 
	{
		return;
	}
	int Tiang[3][Cakram];
	gotoxy(35,6);Waktu = threadWaktu(true);
	for(j=0;j<Cakram;j++)
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
		
		gotoxy(35,6);clearLine(100);
	 	gotoxy(35,6);printf("Total Move : %d  ", Move);

		while(1)
		{

				gotoxy(35,27);clearLine(100);
				gotoxy(35,27);printf("Pindah dari tiang ");

	        gotoxy(53,27);Asal=GetAksi();
	        if(Tujuan == 0)
	        {
				Waktu = threadWaktu(false);
				return;
			}
			
		        gotoxy(53,27);printf("%d", Asal);
		        gotoxy(55,27);printf("ke Tiang ");

	        gotoxy(64,27);Tujuan=GetAksi();
	        if(Tujuan == 0)
	        {
				Waktu = threadWaktu(false);
				return;
			}

		        gotoxy(64,27);printf("%d",Tujuan);
		        gotoxy(35,28);printf("Jika Yakin Tekan Enter!");

	    	if(getch()==13)
	    	{
	    		gotoxy(35,28);clearLine(100);
	            break;
	        }
	        else
	        {
	            gotoxy(35,28);clearLine(100);
	     	    continue;
	        }
		}

		Pindah(Asal-1,Tujuan-1, Cakram, Tiang, Out(), &Check);
		
		if(Tiang[2][0]==0)
		{
			Waktu = threadWaktu(false);
			Win();
			break;
		}
		if(Check)Move++;
	}
	
	system("cls");
	MUTEX(false);
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
	        gotoxy(30,11);printf("============================================================");
			gotoxy(30,12);printf("|                   PILIH JUMLAH CAKRAM                    |");
	        DisplayOption(n,6, options);

	        key = getch();

	        if (key == 0 || key == 224) {
	            key = getch();  // Menangani input panah atas dan bawah

	            if (key == 72) {  // Panah atas
	                n = (n - 1 + 6) % 6;
	                Beep(1200,100);
	            } else if (key == 80) {  // Panah bawah
	                n = (n + 1) % 6;
	                Beep(1200,100);
	            }
	        } else if (key == 13) {  // Enter
	        	Beep(600,100);
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

void Permainan(char Nama[50], int Cakram, int Langkah, int Pilihan)
{
	MUTEX(true);
	int Move, Waktu, Asal, Tujuan;
	int Tiang[3][Cakram];
	gotoxy(35,7);Waktu = threadWaktu(true);
	for(j=0;j<Cakram;j++)
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
	Move = Langkah;

	while(1)
	{
		bool Check = false;
		gotoxy(35,6);printf("Remaining Move : %d  ", Move);
		while(1)
		{
			gotoxy(35,27);clearLine(100);
			gotoxy(35,27);printf("Pindah dari tiang ");
	        gotoxy(53,27);Asal= GetAksi();
	        if(Asal == 0)
	        {
				Waktu = threadWaktu(false);
				return;
			}
	        gotoxy(53,27);printf("%d", Asal);
	        gotoxy(55,27);printf("ke Tiang ");
	        gotoxy(64,27);Tujuan = GetAksi();
	        if(Tujuan == 0)
	        {
				Waktu = threadWaktu(false);
				return;
			}
	        gotoxy(64,27);printf("%d",Tujuan);
	        gotoxy(35,28);printf("Jika Yakin Tekan Enter!");

	    	if(getch()==13)
	    	{
	    		gotoxy(35,28);clearLine(100);
	            break;
	        }
	        else
	        {
	            gotoxy(35,28);clearLine(100);
	     	    continue;
	        }
		}

		Pindah(Asal-1,Tujuan-1,Cakram, Tiang,  Out(), &Check);
		if(Tiang[2][0]==0)
		{
			Waktu = threadWaktu(false);
			break;
		}
		if(Check)Move--;
		if(Move <= 0)
		{
			Waktu = threadWaktu(false);
			MUTEX(false);
			break;
		}
	}

	if(Move <= 0)
	{
		GameOver();
	}
	else
	{
		inputData(Nama, Waktu, Move, Pilihan);
		Win();

	}
}

void Pindah(int F, int T, int Cakram, int Tiang[3][Cakram], HANDLE Out, bool *cek)
{
	int a,b;
	if (F != T)
	{
		for(i=0; i<Cakram ;i++)
		{
			if(Tiang[F][i] != 9)
			{
				a = i;
				break;
			}
			else a = Cakram - 1;
		}
		for(i=0; i<Cakram ;i++)
		{
			if(Tiang[T][i] != 9)
			{
				b = i;
				break;
			}
			else b = Cakram;
		}

		if (b == Cakram)
		{
			PlaySound("BerhasilPindah.wav", NULL, SND_FILENAME | SND_ASYNC);
			Tiang[T][b-1] = Tiang[F][a];
			Tiang[F][a] = 9;
			*cek = true;
		}
		else
		{
			if (Tiang[F][a] < Tiang[T][b])
			{
				PlaySound("BerhasilPindah.wav", NULL, SND_FILENAME | SND_ASYNC);
				Tiang[T][b-1] = Tiang[F][a];
				Tiang[F][a] = 9;
				*cek = true;
			}
			else
			{
				PlaySound("Berhasil.wav", NULL, SND_FILENAME | SND_ASYNC);
			}
		}

			Balok[T][Tiang[T][b-1]].Top = (24-Cakram) + b-1;
			Balok[T][Tiang[T][b-1]].Bottom = (25-Cakram) + b-1;
			DWORD Tunggu = WaitForSingleObject(Mutex, INFINITE);
			if (Tunggu == WAIT_OBJECT_0)
			{
				WriteConsoleOutput(Out,CC[Tiang[T][b-1]+8],Size[Tiang[T][b-1]],O,&Balok[F][Tiang[T][b-1]]);
				WriteConsoleOutput(Out,CC[Tiang[T][b-1]],Size[Tiang[T][b-1]],O,&Balok[T][Tiang[T][b-1]]);
				ReleaseMutex(Mutex);
			}
	}
}

/*
Function Scoring(int Langkah, int Kecepatan, int choice){
BEGIN
	SET bobotLangkah, bobotKecepatan as float with constant value
	bobotLangkah, bobotKecepatan <- 0.5
	SET scoreLangkah, scoreKecepatan, totalScore as float
	
	DEPEND ON (choice){
		choice = 0:
			scoreLangkah <- Langkah / 6
			scoreKecepatan <- 45 / Kecepatan
			BREAK from selection case
		choice = 1:
			scoreLangkah <- Langkah / 4
			scoreKecepatan <- 93 / Kecepatan
			BREAK from selection case
		choice = 2:
			scoreLangkah <- Langkah / 2
			scoreKecepatan <- (189/Kecepatan
			BREAK from selection case
		choice = 3:	
			scoreLangkah <- Langkah / 1
			scoreKecepatan <- 381 / Kecepatan
			BREAK from selection case
	END DEPEND ON
	totalScore <- (bobotLangkah * scoreLangkah) + (bobotKecepatan * scoreKecepatan)
	
	RETURN totalScore;
END

*/
