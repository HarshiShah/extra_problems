#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>

int* compute1(int* arr1, int len1, int* arr2, int len2, int* arr3, int len3,int sum,int* cnt1);
int* compute2(int* arr1, int len1, int* arr2, int len2, int* arr3, int len3,int sum,int* cnt1);
void sort(int* arr, int start, int end);
void swap(int* a, int* b);
/*TEST CASES
 arr1={1,2,3} arr2={1,2,3} arr3={1,2,3}
sum=9
number of sets=1

arr1={0,0,0,0,0} arr2={0,0,0} arr3={0,0,0}
sum=0
number of sets=45

arr1={0,0,0,0,0} arr2={0,0,0} arr3={0,0,0}
sum=1
number of sets=0

arr1={1,0,3,1,2} arr2={1,0,2} arr3={2,1,0}
sum=1
number of sets=8 //Includes repeating sets

arr1={-1,1,2,3} arr2={1,2,-2,3} arr3={1,2,-3,3}
sum=5
number of sets=7 //Include negative numbers

arr1={-1,-1,-2} arr2={-1,-2,-3} arr3={-1,-3,-2}
sum=-7
number of sets=4

*/

int main(){
	int arr1[100],arr2[100],arr3[100], *res,sum, len1,len2,len3,cnt=0;
	printf("\nEnter array length1");
	scanf_s("%d", &len1);
	printf("\nEnter array1 elements:");
	for (int i = 0; i < len1; i++)
		scanf_s("%d", &arr1[i]);
	printf("\nEnter array length2");
	scanf_s("%d", &len2);
	printf("\nEnter array2 elements:");
	for (int i = 0; i < len2; i++)
		scanf_s("%d", &arr2[i]);
	printf("\nEnter array length3");
	scanf_s("%d", &len3);
	printf("\nEnter array3 elements:");
	for (int i = 0; i < len3; i++)
		scanf_s("%d", &arr3[i]);
	printf("\nEnter required sum:");
	scanf("%d", &sum);
	res = compute1(arr1, len1, arr2, len2, arr3, len3,sum,&cnt);
	printf("\nNumber of sets=%d", cnt/3);
	_getch();
	return 0;
}

//the following function generates the sets without sorting
int* compute1(int* arr1, int len1, int* arr2, int len2, int* arr3, int len3,int sum, int* cnt1){
	int res[300],cnt=0;
	for (int i = 0; i < len1; i++){
		for (int j = 0; j < len2; j++){
			for (int k = 0; k < len3; k++){
			if ((arr1[i]+arr2[j]+arr3[k])== sum){
					res[cnt++] = arr1[i];
					res[cnt++] = arr2[j];
					res[cnt++] = arr3[k];
				}
					
			}
		}
	}
	for (int i = 0; i < cnt; i = i + 3)
		printf("\n<a,b,c>=<%d,%d,%d>", res[i], res[i + 1], res[i + 2]);
	*cnt1 = cnt;
	return res;
}

//the following method sorts all the three arrays and generates the sets 
int* compute2(int* arr1, int len1, int* arr2, int len2, int* arr3, int len3, int sum, int* cnt1){
	int i, cnt = 0,temp1,temp2,res[300],j=0;
	sort(arr1, 0, len1);
	sort(arr2, 0, len2);
	sort(arr3, 0, len3);
	for (i = 0; i < len1; i++){
		temp1 = 0;
		temp2 = len3-1;
		while ((temp1<len2)&& (temp2>=0)){
			j++;
			if ((arr1[i] + arr2[temp1] + arr3[temp2]) == sum){
				res[cnt++] = arr1[i];
				res[cnt++] = arr2[temp1];
				res[cnt++] = arr3[temp2];
				temp1++;
				temp2--;
			}
			else if((arr1[i] + arr2[temp1] + arr3[temp2])<sum)
			temp1++;
			else 
			temp2--;
			
		}
      }
	for (i = 0; i < cnt; i = i + 3)
		printf("\n<a,b,c>=<%d,%d,%d>", res[i], res[i + 1], res[i + 2]);
	*cnt1 = cnt;
	return res;
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

//the following method sorts the input array
void sort(int* arr, int start, int end){
	if (end > start + 1){
		int piv = arr[start], left = start + 1, right = end;
		while (left < right){
			if (arr[left] <= piv)
				left++;
			else
				swap(&arr[left], &arr[--right]);
		}
		swap(&arr[--left], &arr[start]);
		sort(arr, start, left);
		sort(arr, right, end);
	}
}