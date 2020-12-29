#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *A, Matrix *b);

void mainElem(Matrix *A, Matrix *b, int r, int c);

double determinant(Matrix *A, int n);
#endif
