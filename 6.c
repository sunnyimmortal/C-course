#include<stdio.h>
int main() {
	char a[30],b[30],c[30];
	int p;
	int i;
	int j;
	printf("please enter one string:");
	scanf_s("%s",&a,30);
	printf("please enter the position£º");
	scanf_s("%d", &p);
	p = p - 1;
	for (i = 0;a[i] != '\0';i++);
	if (p > i || p < 0) {
		printf("wrong position");
		exit(0);
	}
	printf("please enter another string:");
	scanf_s("%s",&b,30);
	for (j = 0;b[j] != '\0';j++) {
		if (b[j] >= 'a' && b[j] <= 'z') {
			b[j] -= ('a' - 'A');
		}
	}
	for (int k = j-1;k >= 0;k--) {
		c[(j-1)-k] = b[k];
	}
	c[j] = '\0';
	for (int m = i;m > p;m--) {
		a[m + j] = a[m];
	}
	for (int k = 0;k < j;k++) {
		a[p + k] = c[k];
	}
	for (int k = 0;a[k] != '\0';k++) {
		printf("%c", a[k]);
	}
	return 0;
}