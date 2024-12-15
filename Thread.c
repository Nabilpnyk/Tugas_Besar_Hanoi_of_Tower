#include "Hanoi.h"

//============================ THREAD =================================

volatile BOOL stopThread = FALSE;  // Flag untuk menghentikan thread
DWORD ThreadD;
HANDLE ThreadH;    

void HitungWaktu(short *waktu) {
    int hour = 0, minute = 0, second = 0;  // Menginisialisasi waktu mulai di 00:00:00
    stopThread = FALSE;
    DWORD Tunggu;
    while (!stopThread) {
        // Thread melakukan pekerjaan sampai flag stopThread diset menjadi TRUE
	        // Menampilkan waktu dalam format jam:menit:detik
	        Tunggu = WaitForSingleObject(Mutex, INFINITE);
	        if (Tunggu == WAIT_OBJECT_0)
	        {
		        gotoxy(35,7);printf("Time : %02d:%02d:%02d ", hour, minute, second);
				ReleaseMutex(Mutex);
			}
		        // Menunggu selama 1 detik
		        Sleep(1000);  // Sleep membutuhkan waktu dalam milidetik, jadi 1000 ms = 1 detik
		        gotoxy(35,7);clearLine(100);
		        second++;
		        if (second == 60)
				{
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

void MUTEX(bool mutexb)
{
	if (mutexb)
	{
		Mutex = CreateMutex(NULL, FALSE, NULL);
	}
	else
	{
		CloseHandle(Mutex);
	}
}
