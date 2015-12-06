#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void print(char* in, int n);
int main(void)	{
		FILE *in;
		if ((in = fopen("input.txt", "r")) == NULL) {
			printf("\nError opening the file");
			exit(0);
		}
		print(in, 1);
		fclose(in);
		_getch();
		return 0;
	}


void print(char* in, int n){
	int len = 1;
	long int pos;
	char s[100];
	char ch;

	while ((ch = fgetc(in)) != EOF){
		if (ch == '\n')
			len++;
	}
	if (n > len || n<0)
		printf("\nInvalid input");
	len = len - n;
	int i = 0;
	fseek(in, 0, SEEK_SET);
	while (i < len){
		ch = fgetc(in);
		if (ch == '\n')
			i++;
	}
	while (fgets(s, sizeof(s), in) != NULL) {
		fprintf(stdout, "%s", s);
	}
}