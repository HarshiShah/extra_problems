#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void generate(int mul, int* res);
int main(){
	int mul, res[100];
	printf("\nEnter multiplicand:");
	scanf("%d", &mul);
	generate(mul, res);
	for (int i = 0; res[i] != -1; i++)
		printf("\n%d", res[i]);
	_getch();
	return 0;

}

void generate(int mul, int* res){
	int cnt1 = 0;
	for (int i = 100000; i < (1000000 / mul); i++){
		int freq[10] = { 0 }, freq2[10] = { 0 }, j, carry = 0, cnt = 0, arr[6], temp;
		temp = i;
		while (cnt < 6){
			j = temp % 10;
			freq[j]++;
			arr[cnt++] = j;
			temp = temp / 10;
		}
		cnt = 0;
		while (cnt<6){
			temp = arr[cnt] * mul;
			j = (temp + carry) % 10;
			freq2[j]++;
			carry = (temp + carry) / 10;
			cnt++;
		}
		for (j = 0; j < 10; j++){
			if (freq[j] != freq2[j])
				break;
		}
		if (j == 10)
			res[cnt1++] = i;
	}
	res[cnt1] = -1;
}