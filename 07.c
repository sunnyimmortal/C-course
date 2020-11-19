#include<stdio.h>
#define File "env.ini"

struct elements {
	char key[50];
	char val[50];
	struct elements* pnext;
};

struct section
{
	char sec[50];
	struct elements* pnext;
};

struct section* a[50];
int k = 0;

FILE* open_file() {
	FILE* pfile;
	errno_t err;
	if (err = fopen_s(&pfile, File, "a+")) {
		printf("can not open file");
		exit(0);
	}
	if (pfile == NULL) {
		printf("encouter a problem");
		exit(0);
	}
	return pfile;
}

FILE* open_file_for_save() {
	FILE* pfile;
	errno_t err;
	if (err = fopen_s(&pfile, File, "w")) {
		printf("can not open file");
		exit(0);
	}
	if (pfile == NULL) {
		printf("encouter a problem");
		exit(0);
	}
	return pfile;
}

struct section* get_sec(char* b) {
	int j = 0;
	struct section* sec = (struct section*)malloc(sizeof(struct section));
	strcpy(sec->sec, b + 1);
	for (;sec->sec[j] != ']';j++);
	sec->sec[j] = '\0';
	sec->pnext = NULL;
	return sec;
}

struct elements* get_ele(int flag, char* b) {
	struct elements* ele = (struct elements*)malloc(sizeof(struct elements));
	strcpy(ele->key, b, flag);
	ele->key[flag] = '\0';
	strcpy(ele->val, b + flag + 1);
	return ele;
}

struct elements* search(char* b, char* c) {
	int i = 0;
	struct elements* p;
	for (;strcmp(a[i]->sec, b)!=0 && i < k;i++);
	if (i >= k) {
		printf("not found!!");
		return NULL;
	}
	else {
		p = a[i]->pnext;
		for (;strcmp(p->key, c)!=0 && p != NULL;p = p->pnext);
		return p;
	}
}

int add_section(char* b) {
	struct section* sec = (struct section*)malloc(sizeof(struct section));
	int i = 0;
	for (;strcmp(a[i]->sec, b)!=0 && i < k;i++);
	if (i < k) {
		return -1;
	}
	strcpy(sec->sec,b);
	sec->pnext = NULL;
	a[k++] = sec;
	return 1;
}

int add_ele_key(char* b, char* c, char* d) {
	struct elements*p = (struct elements*)malloc(sizeof(struct elements));
	
	strcpy(p->key, c);
	strcpy(p->val, d);
	int l = strlen(d);
	p->val[l] = '\n';
	p->val[l + 1] = '\0';
	p->pnext = NULL;
	int i = 0;
	struct elements* m;
	for (;strcmp(a[i]->sec, b)!=0 && i < k;i++);
	if (i >= k) {
		printf("not found!!");
		return -1;
	}
	else {
		m = a[i]->pnext;
		for (;m->pnext != NULL;m = m->pnext);
		m->pnext = p;
	}
	return 1;

}

int change_ele_key(char* b, char* c, char* d) {
	struct elements* p;
	if (search(b, c) != NULL) {
		p = search(b, c);
	}
	else
	{
		return -1;
	}
	strcpy(p->key, d);
	return 1;
}

int change_ele_val(char* b, char* c, char* d) {
	struct elements* p;
	char am[50];
	strcpy(am, d);
	int len = sizeof(d);
	am[len] = '\n';
	am[len+1] = '\0';
	if (search(b, c) != NULL) {
		p = search(b, c);
	}
	else
	{
		return -1;
	}
	strcpy(p->val,am);
	return 1;
}

void sear() {
	struct elements* p;
	char a[50];
	char b[50];
	printf("please enter the section:");
	scanf("%s", a);
	printf("please enter the key:");
	scanf("%s", b);
	p = search(a, b);
	if (p != NULL) {
		printf("%s", p->val);
	}
	else
	{
		printf("not found");
	}
}
void add_e() {
	struct elements* p = (struct elements*)malloc(sizeof(struct elements));
	char a[50];
	char b[50];
	char c[50];
	printf("please enter the section:");
	scanf("%s", a);
	printf("please enter the key:");
	scanf("%s", b);
	printf("please enter the value:");
	scanf("%s", c);
	if (add_ele_key(a, b, c)) {
		printf("success!\n");
	}
	else {
		printf("wrong\n");
	}
}


void change_e_v() {
	char a[50];
	char b[50];
	char c[50];
	printf("please enter the section:");
	scanf("%s", a);
	printf("please enter the key:");
	scanf("%s", b);
	printf("please enter the value:");
	scanf("%s", c);
	if (change_ele_val(a, b, c)) {
		printf("success!\n");
	}
	else {
		printf("wrong\n");
	}
}

void change_e_k() {
	char a[50];
	char b[50];
	char c[50];
	printf("please enter the section:");
	scanf("%s", a);
	printf("please enter the key:");
	scanf("%s", b);
	printf("please enter the value:");
	scanf("%s", c);
	if (change_ele_key(a, b, c)) {
		printf("success!\n");
	}
	else {
		printf("wrong\n");
	}
}

int main() {
	FILE* pfile;
	errno_t err;
	char temp[200];
	struct section* ptemp = NULL;
	struct elements* ptemp_2 = NULL;
	int flag;
	int num = 0;

	if (err = fopen_s(&pfile, File, "r")) {
		printf("can not open file");
		exit(0);
	}
	if (pfile == NULL) {
		printf("encouter a problem");
		exit(0);
	}


	while (fgets(temp, 200, pfile)) {
		if (temp[0] == '\n') {
			continue;
		}
		if (temp[0] == '[') {
			ptemp = get_sec(temp);
			a[k++] = ptemp;
			num = 0;
			continue;
		}
		else {
			for (flag = 0;temp[flag] != '=' && flag < 200;flag++);
			if (num == 0) {
				ptemp->pnext = get_ele(flag, temp);
				ptemp_2 = ptemp->pnext;
				num++;
			}
			else
			{
				ptemp_2->pnext = get_ele(flag, temp);
				ptemp_2 = ptemp_2->pnext;
				ptemp_2->pnext = NULL;
			}
		}
	}

	fclose(pfile);





	char c;
	int l = 0;

	printf("1 for search\n2 for add elements\n3 for change element value\n4 for change element key\nq for quit\n");
	while ((c = getchar())) {
		switch (c) {
		case '1':sear();break;
		case '2':add_e();break;
		case '3':change_e_v();break;
		case '4':change_e_k();break;
		case 'q':l = 1;break;
		}
		if (l == 1) {
			break;
		}
		printf("1 for search\n2 for add elements\n3 for change element value\n4 for change element key\nq for quit\n");
	}

	struct elements* p;
	int j = 0;
	pfile = open_file_for_save();
	for (;j < k;j++) {
		p = a[j]->pnext;
		fputc('\n', pfile);
		fputc('[', pfile);
		fputs(a[j]->sec, pfile);
		fputc(']', pfile);
		fputc('\n', pfile);
		for (;p != NULL;p = p->pnext) {
			fputs(p->key, pfile);
			fputc('=', pfile);
			fputs(p->val, pfile);
		}
	}
	fclose(pfile);

	return 0;
}
