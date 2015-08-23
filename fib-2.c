#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void convert_str2num(char *str, double *num);
double (*fib(double (*M)[2], double n))[2];
double (*sqm(double (*A)[2], double (*B)[2]))[2];
double M[2][2]={{1,1},{1,0}}, Z[2][2]={{0,0},{0,0}};

int main(int argc, char *argv[]) {
    double n=0;
    if (argc!=2) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    convert_str2num(argv[1], &n);
    printf("Fibonacci: %.f\n", (fib(M, n))[1][0]);
    return 0;
}

void convert_str2num(char *str, double *num) {
    int i;
    for(i=0; i<((int)strlen(str)); i++) {
        if (isdigit(str[i])==1) {
            *num = *num*10+(str[i]-'0');
        }
    }
}

double (*fib(double (*M)[2], double n))[2] {
    if (n==0) {
        return Z;
    } else if (n==1) {
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
