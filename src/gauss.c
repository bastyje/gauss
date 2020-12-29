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
    int tempRow = -1, i;
    temp = A->data[r][c];
    for (i = r; i < A->r; i++) {
        if (A->data[i][c] > temp) {
            temp = A->data[i][c];
            tempRow = i;
        }
    }
    if (tempRow != -1) {
        double *tempVer;
        tempVer = A->data[tempRow];
        A->data[tempRow] = A->data[r];
        A->data[r] = tempVer;    
        tempVer = b->data[tempRow];
        b->data[tempRow] = b->data[r];
        b->data[r] = tempVer;    
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
        mainElem(A, b, c, c);
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
