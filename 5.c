#include<stdio.h>
int main() {
	FILE* afile;
	errno_t err;
	if (err = fopen_s(&afile, "3.csv", "r")) {
		printf("can't open");
		exit(0);
	}
	if (afile == NULL) {
		exit(0);
	}
	struct student
	{
		char name[20];
		char num[20];
		char score[20];
	};
	struct student mem[10];
	char ch;
	int i = 0,j=0,k=0;
	while ((ch = getc(afile)) != EOF) {
		if (ch == ',')
		{
			j++;
			k = 0;
		}
		switch (j){
			case 0:
			{
				mem[i].name[k] = ch;
				k++;
				mem[i].name[k] = '\0';
				break;
			}
			case 1:
			{
				mem[i].num[k] = ch;
				k++;
				mem[i].num[k] = '\0';
				break;
			}
			case 2:
			{
				mem[i].score[k] = ch;
				k++;
				mem[i].score[k] = '\0';
				break;
			}
		}
		if (ch == '\n') {
			i++;
			j = 0;
			k = 0;
		}

	}
	for (int i = 0;i < 10;i++) {
		for (int j = 0;mem[i].name[j] != '\0';j++) {
			printf("%c",mem[i].name[j]);
		}
		for (int j = 0;mem[i].num[j] != '\0';j++) {
			printf("%c", mem[i].num[j]);
		}
		for (int j = 0;mem[i].score[j] != '\0';j++) {
			printf("%c", mem[i].score[j]);
		}
	}
	return 0;
}