#include <stdio.h>
#include <stdlib.h>

void multiply(double A[2][2], double B[2][2]);
void power(double F[2][2], int n);
double fib(int n);

int main(int argc, const char *argv[]) {
    int n;
    if (argc < 2) {
        printf("Insufficient arguments!\n");
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    printf("The %dth Fibonacci number is %.0f\n", n, fib(n));
    return 0;
}

void multiply(double A[2][2], double B[2][2]) {
    double x = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    double y = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    double z = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    double w = A[1][0]*B[0][1] + A[1][1]*B[1][1];
    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

void power(double F[2][2], int n) {
    double M[2][2] = {{1,1},{1,0}}, I[2][2] = {{1,0},{0,1}};
    if (n==1) {
        multiply(F, I);
    } else if (n%2==0) {
        power(F, n/2);
        multiply(F, F);
    } else {
        power(F, (n-1)/2);
        multiply(F, F);
        multiply(F, M);
    }
}

double fib(int n) {
    double F[2][2] = {{1,1},{1,0}};
    if (n==0) {
        return 0;
    } else if (n==1||n==2) {
        return 1;
    } else {
        power(F, n-1);
    }
    return F[0][0];
}
