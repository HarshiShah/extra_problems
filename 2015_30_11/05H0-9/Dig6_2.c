#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void generate(int* res);
int main(){
	int res[100],i;
	generate(res);
	for (i = 0; res[i] != -1; i++)
		printf("\n-->%d", res[i]);
	_getch();
	return 0;

}

void generate(int* res){
	int i, cnt1 = 0;
	for (i = 100000; i < 500000; i++){
		int arr[6], j, temp1, hash[10] = { 0 }, hash1[10] = { 0 }, flag = 0, cnt = 0;
		temp1 = i;
		while (cnt <6){
			j = temp1 % 10;
			hash[j]++;
			arr[cnt++] = j;
			temp1 = temp1 / 10;
		}
		cnt = 0;
		while (cnt < 6){
			if (flag == 0){
				hash1[(arr[cnt] % 5) * 2]++;
				if (arr[cnt] < 5)
					flag = 0;
				else
					flag = 1;
				cnt++;
			}
			else{
				hash1[((arr[cnt] % 5) * 2)+1]++;
				if (arr[cnt] < 5)
					flag = 0;
				else
					flag = 1;
				cnt++;
			}
		}
		for (j = 0; j < 10; j++){
			if (hash[j] != hash1[j]){
				break;
			}
		}
		if (j == 10){
			res[cnt1++] = i;
		}
	}
	res[cnt1] = -1;
}