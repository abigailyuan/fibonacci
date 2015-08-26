#include <stdio.h>
#include <stdlib.h>

#define N 2

double (*FIBO(double (M[])[N], double n))[N];
double (*SQMM(double (A[])[N], double (B[])[N]))[N];
double M[N][N]={{1,1},{1,0}}, ZERO[N][N]={{0,0},{0,0}};

int main(int argc, const char * argv[]) {
    if (argc!=2) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    printf("Fibonacci: %.f\n", (FIBO(M, atoi(argv[1])))[1][0]);
    return 0;
}

double (*FIBO(double (M[])[N], double n))[N] {
    if (n==0) {
        return ZERO;
    } else if (n==1) {
        return M;
    } else {
        return SQMM(FIBO(M, n-1), M);
    }
}

double (*SQMM(double (A[])[N], double (B[])[N]))[N] {
    double F[N][N];
    F[0][0] = (A[0][0]*B[0][0])+(A[0][1]*B[1][0]);
    F[0][1] = (A[0][0]*B[0][1])+(A[0][1]*B[1][1]);
    F[1][0] = (A[1][0]*B[0][0])+(A[1][1]*B[1][0]);
    F[1][1] = (A[1][0]*B[0][1])+(A[1][1]*B[1][1]);
    return F;
}
