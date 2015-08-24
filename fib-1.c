#include <stdio.h>
#include <stdlib.h>

double fib(double n);

int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    printf("Fibonacci: %.f\n", fib(atoi(argv[1])));
    return 0;
}

double fib(double n) {
    if (n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    } else {
        return(fib(n-1)+fib(n-2));
    }
}
