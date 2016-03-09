#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiply(double F[2][2], double M[2][2]);
void power(double F[2][2], int n);
double fib(int n);

int main(int argc, const char *argv[]) {
	int n;
	clock_t start;
	if (argc < 2) {
		printf("Insufficient arguments!\n");
		exit(EXIT_FAILURE);
	}
	n = atoi(argv[1]);
	start = clock();
	printf("The %dth Fibonacci number is %.0f\n", n, fib(n));
	printf("Took %d cycles\n", (int)(clock()-start));
	return 0;
}

void multiply(double F[2][2], double M[2][2]) {
	double x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	double y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	double z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	double w = F[1][0]*M[0][1] + F[1][1]*M[1][1];
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
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
