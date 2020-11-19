#include<stdio.h>
#define SIZE_OF_STACK 256
static int stack[SIZE_OF_STACK];
int top = 0;
int status = 1;
int sign = 1;
int line = 0;
char temp[200];


int registers[4];
int status_of_register[4] = {0};

int strncmp(char*a,char*b,int m) {
	for (int j = 0;j < m;j++) {
		if (a[j] >= 'a' && a[j] <= 'z') {
			a[j] -= ('a' - 'A');
		}
	}
	int i = 0;
	for (;i < m&&a[i] == b[i];i++);
	if (i == m) {
		return  0;
	}
	else {
		return 1;
	}
}

void PUSH(int n) {
	if (top >= SIZE_OF_STACK) {
		printf("error ! stack overflow\n");
	}
	else
	{
		stack[top++] = n;
		printf("将%d压入栈\n", n);
	}
}

int POP() {
	if (top <= 0) {
		printf("error! empty\n");
		return NULL;						
	}
	else
	{
		top -= 1;
		printf("%d出栈\n", stack[top]);
		return stack[top];
	}
}

void LOAD(int n) {
	if (status_of_register[n] == 0) {
		printf("there is no data in the %d register\n", n);
	}
	else
	{
		PUSH(registers[n]);
		printf("%d号寄存器压入栈\n", n);
	}
}

void STORE(int n) {
	registers[n] = POP();
	status_of_register[n] = 1;
	printf("%d被存储进%d号寄存器\n", registers[n], n);
}

void PRINT() {
	if (top == 0) {
		printf("empty!\n");
	}
	else
	{
		printf("栈顶元素为：%d\n", stack[--top]);
	}
}

void STOP() {
	sign = 0;
	printf("stop\n");
}

void ADD() {
	int a = POP();
	int b = POP();
	int c;
	if (b == NULL) {
		printf("empty\n");
	}
	else {
		c = a + b;
		PUSH(c);
		printf("%d+%d = %d被压入栈\n", a, b, c);
	}
	
}

void SUB() {
	int a = POP();
	int b = POP();
	int c;
	if (b == NULL) {
		printf("empty\n");
	}
	else {
		c = b - a;
		PUSH(c);
		printf("%d-%d = %d被压入栈\n", b, a, c);
	}
}

void MUL() {
	int a = POP();
	int b = POP();
	int c;
	if (b == NULL) {
		printf("empty\n");
	}
	else {
		c = a * b;
		PUSH(c);
		printf("%d*%d = %d被压入栈\n", a, b, c);
	}
}

void DIV() {
	int a = POP();
	int b = POP();
	int c;
	if (b == NULL) {
		printf("empty\n");
	}
	else {
		c = b / a;
		PUSH(c);
		printf("%d/%d = %d被压入栈\n", b, a, c);
	}
}


FILE* open_command(char *a) {
	FILE* pfile;
	errno_t err;
	if (err = fopen_s(&pfile, a, "r")) {
		printf("cannot open command file\n");
		exit(0);
	}
	if (pfile == NULL) {
		printf("encouter a problem\n");
		exit(0);
	}
	return pfile;
}


int execute_for_CL(char* a) {
	int len = strlen(a);
	int data = 0;
	int i = 0;
	int k = 0;
	int j = 0;
	int m = 0;
	for (;a[i] == ' ';i++);
	if (a[i] == '\n') {
		return 0;
	}

	else if (!strncmp(a + i, "PUSH ", 5)) {

		m = 5;
		for (;a[i + m] == ' '; i++);
		for (;a[i + m + j] == '0' || a[i + m + j] == '1' || a[i + m + j] == '2' || a[i + m + j] == '3' || a[i + m + j] == '4' || a[i + m + j] == '5' || a[i + m + j] == '6' || a[i + m + j] == '7' || a[i + m + j] == '8' || a[i + m + j] == '9';j++) {
			data = data * 10 + a[i + m + j] - '0';
		}
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';k++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			PUSH(data);
			return 1;
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "POP", 3)) {
		m = 3;
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			POP(data);
			return 1;
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "LOAD ", 5)) {
		m = 5;
		for (;a[i + m] == ' '; i++);
		for (;a[i + m + j] == '0' || a[i + m + j] == '1' || a[i + m + j] == '2' || a[i + m + j] == '3';j++) {
			data = data * 10 + a[i + m + j] - '0';
		}
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			if (data == 1 || data == 2 || data == 3 || data == 0) {
				LOAD(data);
				return 1;
			}

			else
			{
				printf("error register\n");
			}
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "STORE ", 6)) {
		m = 6;
		for (;a[i + m] == ' '; i++);
		for (;a[i + m + j] == '0' || a[i + m + j] == '1' || a[i + m + j] == '2' || a[i + m + j] == '3' || a[i + m + j] == '4' || a[i + m + j] == '5' || a[i + m + j] == '6' || a[i + m + j] == '7' || a[i + m + j] == '8' || a[i + m + j] == '9';j++) {
			data = data * 10 + a[i + m + j] - '0';
		}
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			if (data == 0 || data == 1 || data == 2 || data == 3) {
				STORE(data);
				return 1;
			}

			else
			{
				printf("wrong register\n");
			}
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "ADD", 3)) {
		m = 3;
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			ADD(data);
			return 1;
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "SUB", 3)) {
		m = 3;
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			SUB(data);
			return 1;
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "MUL", 3)) {
		m = 3;
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			MUL(data);
			return 1;
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "DIV", 3)) {
		m = 3;
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			DIV(data);
			return 1;
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "PRINT", 5)) {
		m = 5;
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			PRINT(data);
			return 1;
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else if (!strncmp(a + i, "STOP", 4)) {
		m = 4;
		for (;i + m + j + k < len && a[i + m + j + k] == ' ';i++);
		if (i + m + j + k == len||a[i+m+j+k] == '\n') {
			STOP();
			return 1;
		}
		else
		{
			printf("wrong grammar\n");return 0;
		}
	}
	else {
		printf("wrong grammar\n");return 0;
	}
}


void execute(FILE*pfile) {
	while (fgets(temp, 200, pfile)) {
		line++;
		if (execute_for_CL(temp)) {
			continue;
		}
		else {
			printf("There is an error in line %d\n", line);
		}
	}
}

int main(int argc,char*argv[]) {
	FILE* pfile;
	if (argc != 1) {
		if (argc != 2) {
			printf("wrong argument!use middle-work -h to check how to use!\n");
		}
		else
		{
			if (!strcmp(argv[1], "-h")) {
				printf("use middle-work to start the vm\nuse middle-work command.txt to read and execute the command.txt\n");
				return 0;
			}
			else{
				pfile = open_command(argv[1]);
				execute(pfile);
			}
		}
		return 0;

	}

	char a[50];
	while (sign)
	{
		printf("VM $ ");
		gets(a);
		execute_for_CL(a);
	}
	return 0;
}
