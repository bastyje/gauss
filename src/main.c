#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

int checkCorrection(Matrix *A, Matrix *b);

int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return 13;
	if (b == NULL) return 14;

	res = checkCorrection(A,b);

	if(res == 1)
	{
		printf("Podana Macierz, nie jest macierza kwadratowa!\n");
		return 10;
	}
	if(res == 2)
	{
		printf("Podana Macierz A oraz Macierz b maja rozne ilosci rzedow!\n");
		return 11;
	}
	if(res == 3)
	{
		printf("Podana Macierz ma liczbe kolumn inna niz 1!\n");
		return 12;
	}


	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
    if (res == 1) {
        printf("Macierz A jest macierza osobliwa.\n");
        return 4;
    }

	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		if(res == 1)
		{
			printf("Macierz A jest macierza osobliwa.\n");
			return 4;
		}
		else if(res == 2)
		{
			printf("Macierz ma nieprawidlowe wymiary.\n");
			return 5;
		}

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}


/*
Zwraca 0, gdy jest prawidlowo
Zwraca 1, gdy macierz A nie jest macierza kwadratowa
Zwraca 2, gdy macierz A ma rozna ilosc wierszy niz macierz b
Zwraca 3, gdy macierz b ma inna liosc kolumn niz 1
*/
int checkCorrection(Matrix *A, Matrix *b)
{
	if(A->c!=A->r)	return 1;
	if(A->r != b->r) return 2;
	if(b->c != 1) return 3;

	return 0;
}
