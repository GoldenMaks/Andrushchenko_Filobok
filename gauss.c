#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){    //eleminacja gausa - proces schodkowania 
	

	int r = mat->r;
	int c = mat->c;

	
	int k;
	int w;
	for(k = 0; k < c-1; k++)
	{
		wyborElementuGlownego(mat, b, k); //wybieramy element główny macierzy i zmieniamy wierzsy
		printf("\n");
		for(w = k+1; w < r; w++)
		{
			if(mat->data[k][k] != 0){
				double tmp = mat->data[w][k] / mat->data[k][k];
				int i;
				for(i = 0; i < c; i++)
				{
					mat->data[w][i] -= mat->data[k][i] * tmp;
				}
				b->data[w][0] -= tmp * b->data[k][0];
			} else {
				return 1; // macierz osobliwa
			}
			
		}
	}
	return 0; //eliminacja skończona
}



void wyborElementuGlownego(Matrix *mat, Matrix *b, int k){   //funkcja do wyboru elementu głównego

	int w = k+1;
	int max = k;
	while(w < mat->r) //sprawdzanie tego czy istnieje element w pierwszej kolumnie macierzy większy od pierwszego
	{
		if(abs(mat->data[w][k]) > abs(mat->data[max][k]))
		{
			max = w;
		}
		w++;
	}
	
	
	int i = k;	
	while(i < mat->c) //zamiana wierszy
	{
		double tmp = mat->data[max][i];
		mat->data[max][i] = mat->data[k][i];
		mat->data[k][i] = tmp;
		i++;
	}
		
	double tmp = b->data[max][0];
	b->data[max][0] = b->data[k][0];
	b->data[k][0] = tmp;	
}
