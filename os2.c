#include <stdio.h>
#include "f.c"
#include "g.c"

int main(){
	double x;
	printf("x=");
	scanf("%lf", &x);
	printf("f(x)=%lf\ng(x)=%lf\n", f(x), g(x));
}
