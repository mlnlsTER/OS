#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int atoi(const char *string);
long int atol(const char *string);
double atof(const char *string);

void discriminant(double a, double b, double c){
	double x1, x2, s, d = pow(b, 2) - 4 * a * c;
	s = sqrt(d);
	if(d < 0) {
		printf("Нет корней\n");
	} else if (d = 0) {
		printf("x1 = x2 = %.2lf\n", x1 = -b / (2*a));
	} else {
	x1 = (-b + s)/(2 * a);
	x2 = (-b - s)/(2 * a);
	printf("x1 = %.2lf\nx2 = %.2lf\n", x1, x2);}
}

int main(int argc, char *argv[]){
	int i;
	char abc[] = "abc";
        for(i = 1; i < argc; i++) printf("Аргумент %c: %s\n", abc[i-1], argv[i]);
        double a = atof(argv[1]);
        double b = atof(argv[2]);
        double c = atof(argv[3]);
        discriminant(a, b, c);
        //exit(0);
}
