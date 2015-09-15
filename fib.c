#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double r1c1;
    double r1c2;
    double r2c1;
    double r2c2;
} Qm_t;

Qm_t fib_qm(int n);
Qm_t sqmm(Qm_t M1, Qm_t M2); // square matrix multiplication

int main(int argc, char * argv[]) {
    int n;
    if (!argv[1]) {
        printf("Usage: %s integer\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        n = atoi(argv[1]);
    }
    printf("%.0f\n", fib_qm(n).r1c2);
}

Qm_t fib_qm(int n) {
    Qm_t Q={1, 1, 1, 0}, Z={0, 0, 0, 0};
    if (n==0) {
        return Z;
    } else if (n==1) {
        return Q;
    } else if ((n>1)&&(n%2==0)) {
        return sqmm(fib_qm(n/2), fib_qm(n/2));
    } else {
        return sqmm(sqmm(fib_qm((n-1)/2), fib_qm((n-1)/2)), Q);
    }
}

Qm_t sqmm(Qm_t M1, Qm_t M2) {
    Qm_t M;
    M.r1c1 = M1.r1c1*M2.r1c1+M1.r1c2*M2.r2c1;
    M.r1c2 = M1.r1c1*M2.r1c2+M1.r1c2*M2.r2c2;
    M.r2c1 = M1.r2c1*M2.r1c1+M1.r2c2*M2.r2c1;
    M.r2c2 = M1.r2c1*M2.r1c2+M1.r2c2*M2.r2c2;
    return M;
}