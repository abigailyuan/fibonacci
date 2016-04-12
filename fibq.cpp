/* Fibonacci Q-Matrix */
/* {f(n), f(n-1), f(n-1), f(n-2)} ={1, 1, 1,0}^(n-1) */
/* we need F[0][0] in this function */
#include <iostream>
using namespace std;

void multiply(double A[2][2], double B[2][2]);
void recursion(double F[2][2], int n);
double fibonacci(int n);

int main(int argc, const char *argv[]) {
    int n;
    if (argc < 2) {
        cout << "Insufficient arguments!" << endl;
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    cout.precision(0);
    cout << fixed << fibonacci(n) << endl;
    return 0;
}
/* a matrix multiplication */
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

void recursion(double F[2][2], int n) {
    double M[2][2] = {{1,1},{1,0}}, I[2][2] = {{1,0},{0,1}};//I is identity matrix
    if (n == 1) {
        multiply(F, I);
        /* when n is a multiply of 2, rec for n/2 and then merge */
    } else if (n%2 == 0) {
        recursion(F, n/2);
        multiply(F, F);
    } else {
        recursion(F, (n-1)/2);
        multiply(F, F);
        multiply(F, M);
    }
}

double fibonacci(int n) {
    double F[2][2] = {{1,1},{1,0}};
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        recursion(F, n-1);
        return F[0][0];
    }
}
