#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
     */

int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	if (mat->r != mat->c || mat->r != b->r || b->c != 1) {
        	return 2; 
 	}
	
	int r = mat->r;
	int c = mat->c;
	int w, k;
	for(w = r -1; w >= 0; w--)
	{
		double s = 0;
		for(k = w + 1; k < c; k++)
			s += mat->data[w][k] * x->data[k][0];

		if(mat->data[w][w] != 0)
		{
			x->data[w][0] = (b->data[w][0] - s) / mat->data[w][w];
		} else {
			return 1;
		}
	}
	return 0;
}

