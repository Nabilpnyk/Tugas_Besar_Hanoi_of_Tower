#include "Hanoi.h"

//================= Saving File ===================
void inputData(char nama[], int detik, int langkah, int Pilihan){
	Player x;
	Player y[50];
	int i, target = 0 ,n = 0;
	
	strcpy(x.Nama,nama);
	if(detik % 60 == 0){
		x.Menit = detik / 60;
		x.Detik = 0;
	}
	else if(detik > 60){
		x.Menit = detik / 60;
		x.Detik = detik - (x.Menit * 60 );  
	}else{
		x.Menit = 0;
		x.Detik = detik;
	}
	x.SisaLangkah = langkah;
	x.Level = Pilihan;
	x.Score = Scoring(langkah, detik, Pilihan);
	
	FILE *file = fopen(NAMA_FILE,"rb");
	if (file == NULL)
	{
      file = fopen(NAMA_FILE,"wb");
      fwrite(&x,sizeof(Player),1,file);
      printf("Data leaderboard berhasil disimpanj\n");
      sleep(1);
      fclose(file);
	  return;
    }
    
    while (fread(&y[n], sizeof(Player), 1, file))
	{
        n++;
    }
    fclose(file);

    for(i = 0; i < n; i++){
    	if(y[i].Level == x.Level && strcmp(y[i].Nama, x.Nama) == 0){
    		target += 1;
    		break;
		}
	}
	if(target == 1){
    	y[i].Menit = x.Menit;
    	y[i].Detik = x.Detik;
    	y[i].SisaLangkah = x.SisaLangkah;
    	y[i].Score = x.Score;
	}else{
    	y[n] = x;
    	n++;
	}

	file = fopen(NAMA_FILE,"wb");
    for(i = 0; i < n; i++){
    	fwrite(&y[i],sizeof(Player),1,file);
	}
    fclose(file);

    printf("Data leaderboard berhasil disimpan!\n");
    sleep(1);
    system("cls");
}

void tampilData(Player y[50], int n)
{
	int i;
	gotoxy(14,11);printf("======================================== Leaderboard ========================================");
	gotoxy(14,12);printf("=============================================================================================");
	gotoxy(14,13);printf("| No | Nama %-44s | Waktu | Langkah | Score | Level  |\n", " ");
	gotoxy(14,14);printf("=============================================================================================");
	for (i = 0; i < n; i++)
	{
		switch(y[i].Level){
			case 0:
				gotoxy(14,15+(i*2));printf("| %-2d |%-50s | %02d:%02d |   %2d    | %.3f |  Easy  |", i + 1, y[i].Nama,y[i].Menit, y[i].Detik, y[i].SisaLangkah,y[i].Score);
	    		gotoxy(14,16+(i*2));printf("=============================================================================================");
	    		break;
	    	case 1:
	    		gotoxy(14,15+(i*2));printf("| %-2d |%-50s | %02d:%02d |   %2d    | %.3f | Medium |", i + 1, y[i].Nama,y[i].Menit, y[i].Detik, y[i].SisaLangkah,y[i].Score);
	    		gotoxy(14,16+(i*2));printf("=============================================================================================");
	    		break;
	    	case 2:
	    		gotoxy(14,15+(i*2));printf("| %-2d |%-50s | %02d:%02d |   %2d    | %.3f |  Hard  |", i + 1, y[i].Nama,y[i].Menit, y[i].Detik, y[i].SisaLangkah,y[i].Score);
	    		gotoxy(14,16+(i*2));printf("=============================================================================");
	    		break;
	    	case 3:
	    		gotoxy(14,15+(i*2));printf("| %-2d |%-50s | %02d:%02d |   %2d    | %.3f | Legend |", i + 1, y[i].Nama,y[i].Menit, y[i].Detik, y[i].SisaLangkah,y[i].Score);
	    		gotoxy(14,16+(i*2));printf("=============================================================================");
	    		break;	
		}
	}
}

void urutkanData(Player a[], int n, int Pilihan)
{
    int i, j;
    Player temp;

	switch(Pilihan){

	case 1:
	    for (i = 0; i < n - 1; i++) {
	        for (j = 0; j < n - i - 1; j++) {
	            int totalWaktu1 = a[j].Menit * 60 + a[j].Detik;
	            int totalWaktu2 = a[j + 1].Menit * 60 + a[j + 1].Detik;

	            if (totalWaktu1 > totalWaktu2) {
	                temp = a[j];
	                a[j] = a[j + 1];
	                a[j + 1] = temp;
	            }
	        }
	    }
	    break;
	case 2:
		for (i = 0; i < n - 1; i++) {
	        for (j = 0; j < n - i - 1; j++) {

	            if ( a[j].SisaLangkah < a[j+1].SisaLangkah) {
	                temp = a[j];
	                a[j] = a[j + 1];
	                a[j + 1] = temp;
	            }
	        }
	    }
	    break;
	case 3:
		for (i = 0; i < n - 1; i++) {
	        for (j = 0; j < n - i - 1; j++) {

	            if ( a[j].Score > a[j+1].Score) {
	                temp = a[j];
	                a[j] = a[j + 1];
	                a[j + 1] = temp;
	            }
	        }
	    }
	    break;
	}
	tampilData(a,n);
}
