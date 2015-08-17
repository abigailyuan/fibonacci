#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double (*fib(double (*M)[2], double n))[2];
double (*sqm(double (*A)[2], double (*B)[2]))[2];
double M[2][2]={{1,1},{1,0}};

int main(int argc, char *argv[]) {
    int i;
    double n, result;
    if (argc!=2) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<((int)strlen(argv[1])); i++) {
        if (isdigit(argv[1][i])==1) {
            n = n*10+(argv[1][i]-'0');
        }
    }
    if (n==0) {
        result = 0;
    } else {
        result = (fib(M, n))[1][0];
    }
    printf("Fibonacci: %.f\n", result);
    return 0;
}

double (*fib(double (*M)[2], double n))[2] {
    if (n==1) {
        return M;
    } else {
        return sqm(fib(M, n-1), M);
    }
}

double (*sqm(double (*A)[2], double (*B)[2]))[2] {
    double C[2][2];
    C[0][0] = (A[0][0]*B[0][0])+(A[0][1]*B[1][0]);
    C[0][1] = (A[0][0]*B[0][1])+(A[0][1]*B[1][1]);
    C[1][0] = (A[1][0]*B[0][0])+(A[1][1]*B[1][0]);
    C[1][1] = (A[1][0]*B[0][1])+(A[1][1]*B[1][1]);
    return C;
}