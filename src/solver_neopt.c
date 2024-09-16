/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"
#include <string.h>

/*
 * Add your unoptimized implementation here
 */

double* ba(int N, double *A, double* B) {

	double *Res = (double*)malloc(N * N * sizeof(double));
	memset(Res, 0, N * N * sizeof(double));

	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= j; k++) {
				// daca am elemente de 0 , sar peste ele
                Res[i * N + j] += B[i * N + k] * A[k * N + j];
            }
        }
    }
	return Res;
}

double* atb(int N, double *A, double* B) {
// calculez transpusa apoi fac inmultirea

    double *At = (double*)malloc(N * N * sizeof(double));
	memset(At, 0, N * N * sizeof(double));
	for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
        	At[j*N + i] = A[i*N + j];
        }
    }
	double *Res = (double*)malloc(N * N * sizeof(double));
	memset(Res, 0, N * N * sizeof(double));

	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= i; k++) {
				// daca am elemente de 0 , sar peste ele
                Res[i * N + j] += At[i * N + k] * B[k * N + j];
            }
        }
    }
    free(At);
	return Res;
}

double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");
	double* AtB = atb(N, A, B);
	double* BA = ba(N, A, B);

    double *sum = (double*)malloc(N * N * sizeof(double));
	for (int i = 0; i < N*N; i++)
		sum[i] = AtB[i]+BA[i];

    double *Bt = (double*)malloc(N * N * sizeof(double));
	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        	Bt[j*N + i] = B[i*N + j];
        }
    }

    double *C = (double*)malloc(N * N * sizeof(double));
	memset(C, 0, N * N * sizeof(double));

	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i * N + j] += sum[i * N + k] * Bt[k * N + j];
            }
        }
    }
	free(Bt);
	free(sum);
	free(AtB);
	free(BA);
	return C;
}
