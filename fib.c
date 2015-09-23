#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

typedef struct {
    double r1c1;
    double r1c2;
    double r2c1;
    double r2c2;
} qm_t;

qm_t fib(int n);
qm_t sqmm(qm_t M1, qm_t M2);

int main(int argc, char * argv[]) {
    int n;
    if (!argv[1]) {
        printf("Usage: %s integer\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        n = atoi(argv[1]);
        assert(n);
    }
    printf("%.0f\n", fib(n-1).r1c1);
}

qm_t fib(int n) {
    qm_t Q={1,1,1,0}, Z={0,0,0,0};
    if (n==0) {
        return Z;
    } else if (n==1) {
        return Q;
    } else if ((n>1)&&(n%2==0)) {
        return sqmm(fib(n/2), fib(n/2));
    } else if ((n>1)&&(n%2!=0)) {
        return sqmm(sqmm(fib((n-1)/2), fib((n-1)/2)), Q);
    } else {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }
}

qm_t sqmm(qm_t M1, qm_t M2) {
    qm_t M;
    M.r1c1 = M1.r1c1*M2.r1c1+M1.r1c2*M2.r2c1;
    M.r1c2 = M1.r1c1*M2.r1c2+M1.r1c2*M2.r2c2;
    M.r2c1 = M1.r2c1*M2.r1c1+M1.r2c2*M2.r2c1;
    M.r2c2 = M1.r2c1*M2.r1c2+M1.r2c2*M2.r2c2;
    return M;
}
