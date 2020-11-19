#include<stdio.h>
int main()
{
	FILE* pfile;
	int i = 0;
	char str[20][100];
	FILE* pfile3;
	pfile3 = fopen("123.txt", "a+");
	int n1 = 0;
	do
	{
		char str1[100];
		fgets(str1, 100, pfile3);
		n1 = n1 + 1;
	} while (feof(pfile3) != 1);
	fclose(pfile3);
	pfile = fopen("123.txt", "a+");
	if (pfile == NULL)
		exit(0);
	for (i; i <= 9; i++)
	{
		fgets(str[i], 100, pfile);
	}
	FILE* pfile1;
	pfile1 = fopen("1234.txt", "a+");
	int n = 0;
	do
	{
		n++;
		fgets(str[9+n], 100, pfile1);
	} while (feof(pfile1) != 1);
	fclose(pfile1);
	int m = 9 + n ;
	do
	{
		m++;
		fgets(str[m], 100, pfile);
	} while (feof(pfile) != 1);
	fclose(pfile);
	FILE *pfile2;
	pfile2 = fopen("123.txt", "w+");
	int x = 0;
	do
	{
		fprintf(pfile2, "%s", str[x]);
		x++;
	} while (x<=9+n);
	fprintf(pfile2, "\n");
	do
	{
		fprintf(pfile2, "%s", str[x]);
		x++;
	} while (x <= n1+n-1);
	fclose(pfile2);
	return 0;
}