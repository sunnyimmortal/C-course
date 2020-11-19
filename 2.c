#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* pfile;
	errno_t err;
	err = fopen_s(&pfile, "a.txt", "r");
	if (err != 0) {
		printf("there is an error");
		exit(0);
	}
	if (pfile == NULL) {
		printf("the indicator is NULL");
		exit(0);
	}
	char temp[200];
	int line = 0;
	char i;
	while (fgets(temp, 200, pfile) != NULL) {
		printf("%s", temp);
		line += 1;
		if (line % 20 == 0) {
			printf("\npress to continue");
			i = getchar();
		}
	}
	fclose(pfile);
}