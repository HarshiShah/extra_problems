#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define range_len 3

/*
The program finds the element in the array whose sum along with the element to its left and right is the highest.
Incase of two elements with the same sum,the element with lower index value is chosen.
*/

int check_Win(int* arr, int length, int range);
int check_Win2(int* arr, int length, int range);


int main(){
	int arr[1000], i, len, res = -1;
	printf("\nEnter array length");
	scanf("%d", &len);
	printf("\nEnter array elements");
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	if (len >= range_len)
		res = check_Win2(arr, len, range_len);
	if (res >= 0)
		printf("\nWinner element is %d at position %d in the array", arr[res], res + 1);
	else
		printf("\nNo winner element");
	_getch();
	return 0;
}

//The following function works for any sum range.Elements to the left are added first incase of even ranges. 
int check_Win(int* arr, int length, int range){
	int sum = 0, max[2], cnt;
	for (int i = range / 2; i <= (length - range / 2 - (range % 2)); i++){
		sum = arr[i];
		cnt = 1;
		for (int j = 1; j <= range / 2; j++){
			if ((i - j) >= 0){
				sum += arr[i - j];
				cnt++;
			}
			if ((i + j)<length && cnt<range){
				sum += arr[i + j];
				cnt++;
			}
		}
		if (i == range / 2){
			max[0] = sum;
			max[1] = i;
		}
		else if (sum>max[0]){
			max[0] = sum;
			max[1] = i;
		}
	}
	return max[1];
}

//The following function if for a sum range of 3 elements
int check_Win2(int* arr, int length, int range){
	printf("\nHello");
	int sum = 0, max[2];
	max[0] = arr[0] + arr[1] + arr[2];
	max[1] = 1;
	for (int i = 2; i < length - 2; i++){
		sum = arr[i] + arr[i - 1] + arr[i + 1];
		if (sum>max[0]){
			max[0] = sum;
			max[1] = i;
		}
	}
	return max[1];
}
