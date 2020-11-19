#include<stdio.h>
add(char* a, char* b) {
	char temp;
	errno_t err1, err2;
	char* f1 = NULL;
	char* f2 = NULL;
	err1 = fopen_s(&f1,a, "a");
	err2 = fopen_s(&f2, b, "r+");
	if (err1 == 0&&err2 == 0&&f1!=NULL&&f2!=NULL) {
		fputc('\n',f1);
		while ((temp = fgetc(f2)) != EOF)
		{
			fputc(temp, f1);
		}
		printf("done");

	}
	else
	{
		printf("file do not exit or cannot open file");
	}
}
copy(char* a, char* b) {
	char temp;
	errno_t err1, err2;
	char* f1 = NULL;
	char* f2 = NULL;
	err1 = fopen_s(&f1, a, "w");
	err2 = fopen_s(&f2, b, "r+");
	if (err1 == 0 && err2 == 0 && f1 != NULL && f2 != NULL) {
		while ((temp = fgetc(f2)) != EOF)
		{
			fputc(temp, f1);
		}
		printf("done");

	}
	else
	{
		printf("file do not exit or cannot open file");
	}
}
int main(int argc, char* argv[]) {
	if (argv[1][1] == 'h'&&argv[1][2]=='\0'&& argc == 2) {
		printf("filetools -h for help\nfiletools -a file1 file2 to add file2 after file1\nfiletools -c file1 file2 to copy file2 to file1\n");
		exit(0);
	}else if(argv[1][1] == 'a' && argv[1][2] == '\0' && argc == 4) {
		add(argv[2], argv[3]);
	}else if(argv[1][1] == 'c' && argv[1][2] == '\0' && argc == 4)
	{
		copy(argv[2], argv[3]);
	}
	else {
		printf("wrong ! use filetools -h to check the way to use");
		exit(0);
	}
	return 0;
}

