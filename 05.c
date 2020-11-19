#include<stdio.h>
typedef int (*func)(void* f, void* l);
void* max(void* data[], int num, func funcp)
{
	int i;
	void* temp = data[0];
	for (i = 1;i < num;i++)
	{
		if (funcp(temp, data[i]) < 0)
		{
			temp = data[i];
		}
	}
	return temp;
}
int funcp_int(void* f, void* l)
{
	int A = *((int*)f);int B = *((int*)l);
	return (A > B) ? 1 : -1;
}
int funcp_double(void* f, void* l)
{
	double A = *((double*)f);double B = *((double*)l);
	return (A > B) ? 1 : -1;
}
int funcp_char(void* f, void* l)
{
	char A = *((char*)f);char B = *((char*)l);
	return (A > B) ? 1 : -1;
}
int funcp_string(void* f, void* l)
{
	char* A = *((char**)f);char* B = *((char**)l);
	char a1 = A[strlen(A) - 1];char b1 = B[strlen(B) - 1];
	return (a1 > b1) ? 1 : -1;
}
int main()
{
	int a1[] = { 12,43,1212,34,89,564,783,2432 };
	int* aa1[] = { &a1[0],&a1[1],&a1[2],&a1[3],&a1[4],&a1[5],&a1[6],&a1[7] };
	int* int_max = max(aa1, 8, funcp_int);
	printf("%d\n", *(int_max));

	double a2[] = { 12.34,45.23,234.5657,123.895 };
	double* aa2[] = { &a2[0],&a2[1],&a2[2],&a2[3],&a2[4] };
	double* double_max = max(aa2, 5, funcp_double);
	printf("%f\n", *(double_max));

	char a3[] = { 'A','u','b','e','s','p','Q' };
	char* aa3[] = { &a3[0],&a3[1],&a3[2],&a3[3],&a3[4],&a3[5],&a3[6] };
	char* char_max = max(aa3, 7, funcp_char);
	printf("%c\n", *(char_max));

	char* a4[] = { "hello","beijing","Paris","China" };
	char** aa4[] = { &a4[0],&a4[1],&a4[2],&a4[3] };
	char** string_max = max(aa4, 4, funcp_string);
	printf("%s\n", *(string_max));

	return 0;
}

