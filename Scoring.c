#include "Hanoi.h"

float Scoring(int Langkah, int Kecepatan, int choice){
	const float bobotLangkah = 0.5;
	const float bobotKecepatan = 0.5;
	float scoreLangkah;
	float scoreKecepatan;
	float totalScore;
	
	switch (choice){
		case 0:
			scoreLangkah = (Langkah/6 * 0.1);
			scoreKecepatan = (45/Kecepatan * 0.1);
			break;
		case 1:
			scoreLangkah = (Langkah/4 * 0.1);
			scoreKecepatan = (93/Kecepatan * 0.1);
			break;
		case 2:
			scoreLangkah = (Langkah/2 * 0.1);
			scoreKecepatan = (189/Kecepatan * 0.1);
			break;
		case 3:	
			scoreLangkah = (Langkah/1 * 0.1);
			scoreKecepatan = (381/Kecepatan * 0.1);
			break;
	}
	totalScore = (bobotLangkah * scoreLangkah) + (bobotKecepatan * scoreKecepatan);
	
	return totalScore;
}
