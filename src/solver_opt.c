/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"
#include <string.h>

/*
 * Add your optimized implementation here
 */


double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");
    double *BA = (double*)malloc(N * N * sizeof(double));

    register int i, j, k;
    register double sum;

    register double *BA1 = BA;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            register double *B1 = B + i * N;
            register double *A1 = A + j;
            sum = 0;
            for (k = 0; k <= j; k++) {
                sum += ((*B1) * (*A1));
                A1+=N;
                B1++;
            }
            (*BA1) = sum;
            BA1++;
        }
    }

    double *AtB = (double*)malloc(N * N * sizeof(double));

    register double *AtB1 = AtB;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            register double *A1 = A + i;
            register double *B1 = B + j;
            sum = 0;
            for (k = 0; k <= i; k++) {
                sum += (*A1) * (*B1);
                B1+=N;
                A1+=N;
            }
            (*AtB1) = sum;
            AtB1++;
        }
    }
    BA1 = BA;
    AtB1 = AtB;
    for (i = 0; i < (N*N); i++) {
            (*(BA1++)) += (*(AtB1++));
    }

    double *C = (double*)malloc(N * N * sizeof(double));

    register double *C1 = C;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum = 0;
            BA1 = BA + i * N;
            register double *B1 = B + j * N;
            for (k = 0; k < N; k++) {
                sum += (*BA1) * (*B1);
                BA1++;
                B1++;
            }
            (*C1) = sum;
            C1++;
        }
    }

    free(BA);
    free(AtB);

    return C;
}
