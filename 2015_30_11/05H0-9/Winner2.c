#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

int check_Win(int* arr, int length, int k, int* res);
void cost_fun(int* costArr, int* freq, int k);

int main(){
	int arr[1000], i, len, res[10], cost, k;
	printf("\nEnter array length");
	scanf("%d", &len);
	printf("\nEnter array elements");
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	printf("\nEnter value of frequency");
	scanf("%d", &k);
	if (k <= len){
		cost = check_Win(arr, len, k, res);
		printf("\nWinner element\n");
		for (int i = 0; res[i] != -1; i++)
			printf("\n%d", res[i]);
		printf("\nCost=%d", cost);
	}
	else
		printf("\nInvalid Frequency");
	_getch();
	return 0;
}


int check_Win(int* arr, int length, int k, int* res){
	int freq[10] = { 0 }, i, cnt = 0, minCost = 0;
	printf("The winner element is");
	for (i = 0; i < length; i++){
		freq[arr[i]]++;
		if (freq[arr[i]] == k)
			res[cnt++] = arr[i];
	}
	if (cnt == 0){
		int costArr[10] = { 0 }, minIndex, flag = 0;
		cost_fun(costArr, freq, k);
		printf("\nCost Array is\n");
		for (int i = 0; i<10; i++)
			printf("\n%d", costArr[i]);
		for (i = 0; i < 10; i++){
			if ((costArr[i]>0) && (flag == 0)){
				minCost = costArr[i];
				minIndex = i;
				flag = 1;
			}
			else if (costArr[i]>0 && minCost>costArr[i]){
				minCost = costArr[i];
				minIndex = i;
			}
		}
		res[cnt++] = minIndex;
		for (i = 1; i < 10; i++){
			if (i != minIndex && minCost == costArr[i])
				res[cnt++] = i;
		}
	}
	res[cnt] = -1;
	return minCost;
}

void cost_fun(int* costArr, int* freq, int k){
	int temp1, temp2, j, cnt, flag1, flag2;
	for (int i = 0; i<10; i++)
		printf("\n%d", freq[i]);

	for (int i = 0; i < 10; i++){
		cnt = freq[i];
		j = 1;
		flag1 = 0;
		flag2 = 0;
		if (cnt != 0){
			while (j<10 && cnt<k){
				if ((i - j >= 0) && flag1 == 0){
					temp1 = freq[i - j];
					flag1 = 1;
				}
				if ((i + j <= 9) && flag2 == 0){
					temp2 = freq[i + j];
					flag2 = 1;
				}
				if ((i - j) >= 0 && (temp1>0)){
					costArr[i] += j;
					temp1--;
					cnt++;
				}
				else if ((i + j) <= 9 && (temp2>0)){
					costArr[i] += j;
					temp2--;
					cnt++;
				}
				else{
					j++;
					flag1 = 0;
					flag2 = 0;
				}
			}
		}
	}

}
