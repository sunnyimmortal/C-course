#include<stdio.h>

int main() {
	int m = 0;
	int n = 0;
	printf("enter row number:");
	scanf_s("%d", &m);
	printf("enter column number:");
	scanf_s("%d", &n);
	int** a;
	a = (int**)malloc(sizeof(int*) * m);
	for (int i = 0;i < m;i++) {
		a[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			a[i][j] = (i + 1) * (j + 1);
		}
	}
	for (int j = 0;j < n;j++) {
		for (int i = 0;i < m;i++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}