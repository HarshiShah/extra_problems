#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*
struct{
	char inp[100];
	char inp2[100];
	int res;
} tests[10] = {
	{
		{ "abc" },
		{ "abc" },
		1
	},
	{
		{ "aBc" },
		{ "abc" },
		0
	},
	{
		{ "XCVB" },
		{ "XCVB" },
		1
	},
	{
		{ "cdJef" },
		{ "hiKjk" },
		1
	},
	{
		{ "abJcd" },
		{ "hiKjk" },
		1
	},
	{
		{ "abcd" },
		{ "abc" },
		0
	},
	{
		{ "abcd" },
		{ "abcde" },
		0
	},
	{
		{ "hGjIlK" },
		{ "aBcDeF" },
	1
	},
	{
		{ "a" },
		{ "c" },
		1
	},
	{
		{ "b" },
		{ "B" },
		0
	}
};
*/

int check(char* str1, char* str2);

int main(void){
	char inp1[100], inp2[100];
	int res;
	printf("\nEnter string1:");
	scanf("%s", inp1);
	printf("\nEnter string2:");
	scanf("%s", inp2);
	res = check(inp1,inp2);
	if (res == 1)
		printf("\nThe strings are isomorphic");
	else
		printf("\nThe strings are not isomorphic");
	_getch();
	return 0;
}

int check(char* str1, char* str2){
	int i,low1=0, low2=0, cap1=0, cap2=0,flag=1,cnt1=0,cnt2=0;
	for (i = 0; str1[i] != '\0'; i++){
		if ((str1[i] >= 'a' && str1[i] <= 'z') && (str2[i] >= 'a' && str2[i] <= 'z')){
			low1 = (str1[i]-'0') - low1;
			low2 = (str2[i]-'0') - low2;
			if (cnt1!=0&&low1 != low2){
				flag = 0;
				break;
			}
			low1 = str1[i] - '0';
			low2 = str2[i] - '0';
			cnt1++;
			}
		else if ((str1[i] >= 'A' && str1[i] <= 'Z') && (str2[i] >= 'A' && str2[i] <= 'Z')){
			cap1 = (str1[i] - '0') - cap1;
			cap2 = (str2[i] - '0') - cap2;
			if (cnt2!=0&&cap1 != cap2){
				flag = 0;
				break;
			}
			cap1 = str1[i] - '0';
			cap2 = str2[i] - '0';
			cnt2++;
		
		}
		else{
			flag = 0;
			break;
		}
	}
	if (str2[i] != '\0')
		return 0;
	return flag;
}