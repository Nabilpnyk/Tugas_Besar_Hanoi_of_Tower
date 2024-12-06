#include "Hanoi.h"

volatile BOOL stopThread = FALSE;  // Flag untuk menghentikan thread
DWORD ThreadD;
HANDLE ThreadH;

//============================ THREAD =================================
void HitungWaktu(short *waktu) {
    int hour = 0, minute = 0, second = 0;  // Menginisialisasi waktu mulai di 00:00:00
//    PlaySound("ZAMRUD KHATULISTIWA.wav", NULL, SND_FILENAME | SND_ASYNC);
//	sndPlaySound("ZAMRUD KHATULISTIWA.wav", SND_FILENAME | SND_ASYNC | SND_LOOP );
    stopThread = FALSE;
    while (!stopThread) {
        // Thread melakukan pekerjaan sampai flag stopThread diset menjadi TRUE
	        // Menampilkan waktu dalam format jam:menit:detik
//	        gotoxy(41,6);CetakWaktu(&hour, &minute, &second);
	        gotoxy(35,6);printf("Time : %02d:%02d:%02d ", hour, minute, second);
	        // Menunggu selama 1 detik
	        Sleep(1000);  // Sleep membutuhkan waktu dalam milidetik, jadi 1000 ms = 1 detik
	        
	        // Menghitung detik
	        second++;
	        if (second == 60) {
	            second = 0;
	            minute++;
	            if (minute == 60) {
	                minute = 0;
	                hour++;
	                if (hour == 24) {
	                    hour = 0;  // Reset jam ke 00 setelah 23:59:59
	                }
	            }
			}
	}
	*waktu = hour * 3600 + minute * 60 + second - 1;
}

//Mulai Game
short threadWaktu(bool kondisi)
{	
	short waktu;
    if (kondisi) {
	    ThreadH = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HitungWaktu, &waktu, 0, &ThreadD);
	    if (ThreadH == NULL) {
	        printf("Gagal membuat thread.\n");
	        return;
		}
		return;
	} else {
		stopThread = TRUE;
		sndPlaySound(NULL, 0);
	}
	
    // Tunggu thread untuk benar-benar selesai
    WaitForSingleObject(ThreadH, INFINITE);
    // Menutup handle setelah thread selesai
    CloseHandle(ThreadH);
	
    return waktu;
}
