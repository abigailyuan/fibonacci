#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void convert_str2num(char *str, double *num);
double fib(double n);

int main(int argc, char *argv[]) {
    double n=0;
    if (argc!=2) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    convert_str2num(argv[1], &n);
    printf("Fibonacci: %.f\n", fib(n));
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

double fib(double n) {
    if (n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    } else {
        return(fib(n-1)+fib(n-2));
    }
}
