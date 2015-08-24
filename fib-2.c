#include <stdio.h>
#include <stdlib.h>

#define N 2

double (*fib(double (*M)[N], double n))[N];
double (*sqm(double (*A)[N], double (*B)[N]))[N];
double M[N][N]={{1,1},{1,0}}, Z[N][N]={{0,0},{0,0}};

int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    printf("Fibonacci: %.f\n", (fib(M, atoi(argv[1])))[1][0]);
    return 0;
}

double (*fib(double (M[])[N], double n))[N] {
    if (n==0) {
        return Z;
    } else if (n==1) {
        return M;
    } else {
        return sqm(fib(M, n-1), M);
    }
}

double (*sqm(double (A[])[N], double (B[])[N]))[N] {
    double C[N][N];
    C[0][0] = (A[0][0]*B[0][0])+(A[0][1]*B[1][0]);
    C[0][1] = (A[0][0]*B[0][1])+(A[0][1]*B[1][1]);
    C[1][0] = (A[1][0]*B[0][0])+(A[1][1]*B[1][0]);
    C[1][1] = (A[1][0]*B[0][1])+(A[1][1]*B[1][1]);
    return C;
}
