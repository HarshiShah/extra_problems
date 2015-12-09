#define _CRT_SECURE_NO_WARNINGS  
#include <stdlib.h> 
#include<stdio.h> 
#include<conio.h> 
/*
struct testCases{
int arr[10];
int len_arr;
int result;
} tests[9] = {
{
{ 1, 2, -3, 4, 5 },
5,
9
},
{
{ 6, 7, 8, 9, 10 },
5,
40
},
{
{ -5, -3, -2, -6, -1, -7 },
6,
-1

},
{
{ -1, 4, -2, 6, -3, 8 },
6,
8
},
{
{ 0 },
0,
0
},
{
{ 5, 4, -1, 4, 5, -3, 6, 3 },
8,
9
},
{
{ -1, 0, 0, -2, -3, 0 },
6,
0
},
{
{ 5, 5, 5, 5, 5 },
5,
25
},
{
{ 1, 2, 3, 4, 5, -2, -3, -4, -20, 10 },
10,
15
},
};
*/
int seqSum(int* arr1, int length);

int main(void){
	int arr[100], len;
	printf("\nEnter length");
	scanf("%d", &len);
	if (len > 0){
		printf("\nEnter array elements\n");
		for (int i = 0; i < len; i++)
			scanf("%d", &arr[i]);
		int res = seqSum(arr, 7);
		printf("\nSum=%d", res);
	}
	else
		printf("\nInvalid input");
	_getch();
	return 0;
}

int seqSum(int* arr1, int length){
	int final_sum = 0, neg_count = 0, temp_sum = 0, flag = 0, neg_max = arr1[0];
	for (int var = 0; var < length; var++){
		if (arr1[var]<0){
			neg_count++;
			temp_sum = 0;
		}
		else if ((temp_sum + arr1[var])>temp_sum){
			temp_sum = temp_sum + arr1[var];
			flag = 1;
		}
		if (temp_sum>final_sum)
			final_sum = temp_sum;
		if (flag == 0 && neg_max<arr1[var])
			neg_max = arr1[var];
	}
	if (neg_count == length)
		final_sum = neg_max;

	return final_sum;
}
