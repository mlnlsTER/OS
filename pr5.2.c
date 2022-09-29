#include <stdio.h>
#include <stdlib.h>

int main(){
	system("chcp 1251");
	system("cls");
	double arr[] = {4, 8, -1, -3, 0, 10, 2};
	double res1 = 0, res2 = 0;
	double count = 0;
	int i, neg;
	// 1
	for (i = 0; i < 7; i++){
		count += arr[i];
	}
	count = count/7;
	printf("Среднее зн: %lf\n", count);
	for (i = 0; i < 7; i++){
		if (arr[i] > count) res1++;
	}
	printf("Res 1: %.0lf\n", res1);
	// 2
	for (i = 0; i < 7; i++){
		if (arr[i] < 0) {
			neg = i;
			break;
		}
	}
    for (i = neg + 1; i < 7; i++) res2 += abs(arr[i]);
	printf("Res 2: %.0lf\n", res2);
	system("pause");
}
