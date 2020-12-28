#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	/*
	* Tutaj należy umieścić właściwą implemntację.
	*/
	int i, j;
	for (i = x->r - 1; i >= 0; i--)
	{
		x->data[i][0] = b->data[i][0];
		for (j = x->r - 1; j > i; j--)
		{
			x->data[i][0] = x->data[i][0] - mat->data[i][j] * x->data[j][0];
		}

		x->data[i][0] = x->data[i][0] / mat->data[i][i];
	}

	/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

	/*
	for (i = 0; i < x->r; i++)
	{
		x->data[i][0] = b->data[i][0];
	}
	*/

	return 0;
}
