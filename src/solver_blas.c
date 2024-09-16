/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"

/*
 * Add your BLAS implementation here
 */
#include <string.h>
#include "cblas.h"

double* my_solver(int N, double *A, double *B) {
    double *C = malloc(N * N * sizeof(double));
    double *temp1 = malloc(N * N * sizeof(double));
    double *temp2 = malloc(N * N * sizeof(double));

    // double *B_copy = malloc(N * N * sizeof(double));
    memcpy(temp1, B, N * N * sizeof(double));
    memcpy(temp2, B, N * N * sizeof(double));

    // At * B
    cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1.0, A, N, temp1, N);
    // B * A
    cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, A, N, temp2, N);

    // compun suma
    cblas_daxpy(N * N, 1.0, temp2, 1, temp1, 1);

    // (..)*Bt
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1.0, temp1, N, B, N, 0.0, C, N);

    free(temp1);
    free(temp2);

    return C;
}
