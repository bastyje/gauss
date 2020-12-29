#include "gauss.h"
#include <math.h>
#include <stdio.h>

/*
 * Zwraca wartość wyznacznika macierzy trójkątnej
 */

double determinant(Matrix *A, int n)
{
    int i;
    double det = A->data[0][0];
    for (i = 0; i < n; i++) {
        det *= A->data[i][i];
    }
    return det;
}

void mainElem(Matrix *A, Matrix *b, int r, int c)
{
    double temp;
    int tempRow, i, j;
    temp = A->data[r][c];
    for (i = r; i < A->r; i++) {
        if (temp < A->data[r][c]) {
            temp = A->data[i][c];
            tempRow = i;
        }
        else {
            tempRow = -1;
        }
    }
    if (tempRow != -1) {
        for (j = c; j < A->c; j++) {
            A->data[tempRow][c] = A->data[r][c];
            A->data[r][c] = temp;
        }
        *(b->data[tempRow]) = *(b->data[r]);
        *(b->data[r]) = temp;
    }
}

/*
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *A, Matrix *b)
{
    int i, r, c;
    double ratio;

    for (c = 0; c < A->c - 1; c++) {
        mainElem(A, b, c + 1, c);
        for (r = c + 1; r < A->r; r++) {
            ratio = A->data[r][c] / A->data[c][c];
            for (i = c; i < A->c; i++) {
                A->data[r][i] -= ratio * A->data[c][i];
            }
            *(b->data[r]) -= ratio * *(b->data[c]);
        }
    }
    if (determinant(A, A->r) == 0) return 1;
    return 0;
}
