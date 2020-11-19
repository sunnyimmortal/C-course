#include<stdio.h>
main() {
	int a[2][4] = {1,0,3,-1,2,1,0,2};
	int b[4][3] = {4,1,0,-1,1,3,2,0,1,1,3,4};
	int c[2][3] = {0};
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 4;k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
}