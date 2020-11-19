#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* pfile;
	errno_t err;
	if (err = fopen_s(&pfile, "a.txt", "r")) {
		printf("can not open file");
		exit(0);
	}
	if (pfile == NULL) {
		exit(0);
	}
	char ch;
	int num = 0, line = 1;
	while ((ch = fgetc(pfile)) != EOF) {
		num += 1;
		if (ch == '\n') {
			line += 1;
			num -= 1;
		}
	}
	printf("the number of chars in this text is : %d\n", num);
	printf("the number of lines in this text is : %d\n", line);
	fclose(pfile);
}