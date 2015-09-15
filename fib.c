#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    double r1c1;
    double r1c2;
    double r2c1;
    double r2c2;
} Qm_t;

int str_isdigit(char *str);
Qm_t fib_qm(int n);
Qm_t sqmm(Qm_t M1, Qm_t M2); // square matrix multiplication

int main(int argc, char * argv[]) {
    int n;
    if (!argv[1]) {
        printf("Usage: %s integer\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (!str_isdigit(argv[1])) {
        printf("Usage: %s integer\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        n = atoi(argv[1]);
    }
    printf("%.0f\n", fib_qm(n).r1c2);
}

int str_isdigit(char *str) {
    int i, flag=1;
    for (i=0; i<strlen(str); i++) {
        if (!isdigit(str[i])) {
            flag = 0;
        } else {
            continue;
        }
    }
    return flag;
}

Qm_t fib_qm(int n) {
    Qm_t Q={1, 1, 1, 0}, Z={0, 0, 0, 0};
    if (n==0) {
        return Z;
    } else if (n==1) {
        return Q;
    } else if ((n>1)&&(n%2==0)) {  // even n
        return sqmm(fib_qm(n/2), fib_qm(n/2));
    } else if ((n>1)&&(n%2!=0)) {  // odd n
        return sqmm(sqmm(fib_qm((n-1)/2), fib_qm((n-1)/2)), Q);
    } else {
        printf("Error\n");
        exit(EXIT_FAILURE);
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
