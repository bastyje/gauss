#include "gauss.h"
#include <math.h>

/*
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *A, Matrix *b)
{
    int r, c, i;
    double ratio;

    for (c = 0; c < A->c - 1; c++) {
        for (r = c + 1; r < A->r; r++) {
            ratio = A->data[r][c] / A->data[c][c];
            if (A->data[c][c] == 0) return 1; 
            for (i = c; i < A->c; i++) {
                A->data[r][i] -= ratio * A->data[c][i];
            }
            *(b->data[r]) = ratio * *(b->data[r - 1]);
        }
    }
    return 0;
}

