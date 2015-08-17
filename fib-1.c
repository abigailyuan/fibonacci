#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double fib(double n);

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
        result = fib(n);
    }
    printf("Fibonacci: %.f\n", result);
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