#include "gauss.h"

/*
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *A, Matrix *b)
{
    int *matR = A->r;
    int *matC = A->c;
    int r, c, i;
    double ratio;

    for (c = 0; c < matC - 1; c++) {
        for (r = c + 1; r < matR; r++) {
            if (A->data[r - 1][c] == 0) {
                return 1;
            }
            ratio = A->data[r][c] / A->data[r - 1][c];
            for (i = c; i < matC; i++) {
                A->data[r][i] -= ratio * A->data[r - 1][i];
            }
            b->*data[r] = ratio * b->*data[r - 1];
        }
    }
    return 0;
}

