#include "Hanoi.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	SizeRect();
	SetChar();
	system("mode 120,40");
	system("CLS");
	int n = 0;
	for(;;)
	{
		char *options[5] =
		{
	        "Play Game",
	        "LeaderBoard",
	        "Latihan",
	        "Credits",
	        "Quit"
	    };
	    int key;
	    while (1)
		{
	        system("cls");  // Membersihkan layar
			gotoxy(30,11);printf("============================================================");
			gotoxy(30,12);printf("|                        MAIN MENU                         |");
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
                PlayGame();
                break;
            case 1 :
                system("cls");
                LeaderBoard();
                break;
            case 2 :
                system("cls");
                Latihan();
                break;
            case 3 :
                system("cls");
                Credits();
                break;
            case 4 :
                system("cls");
                return 0;
        }
	}
}
