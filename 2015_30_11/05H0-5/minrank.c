#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void sort(int* arr,int start,int end);
void swap(int* a, int* b);
//Logic 1 uses the following two functions.minRank is found by computing number of required permutations using factorial.Works for repeating digits. 
//int minRank1(unsigned int num);
//int fact(int num);
//Logic 2 uses the following two functions.All possible permutations are generated and minRank is found.Works even for repeating digits in a number
int minRank2(unsigned int num);
int compute(int* arr, int left, int right, int* arr1);

int main(){
	unsigned int num;
	int rank;
	printf("\nEnter number");
	scanf_s("%lu", &num);
	rank = minRank2(num);
	printf("\n\nThe minRank is %d", rank);
	_getch();
	return 0;
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

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
/*
//Logic 1
int minRank1(unsigned int num){
	int arr[10], num1[10], i = 0, count = 0, res = 0, pow = 1;
	unsigned int temp = num;
	while (temp > 0){
		pow = pow * 10;
		temp = temp / 10;
		count++;
	}
	pow = pow / 10;
	while (pow > 0){
		num1[i] = num / pow;
		num = num - num1[i] * pow;
		arr[i] = num1[i];
		i++;
		pow = pow / 10;
	}
	sort(arr, 0, count);
	int hash[10] = { 0 }, hashSum = 0, j = 0;
	i = 0;
	while (i != count){
		hash[arr[i]]++;
		if (hash[arr[i]] == 1)
			hashSum++;
		i++;
	}
	i = 0;
	while (i != count){
		if ((arr[j] == -1) || (arr[j] == arr[j + 1])){
			j++;
		}
		else if (num1[i] == arr[j]){
			i++;
			arr[j] = -1;
			j = 0;
		}
		else{
			if (hash[arr[j]] == 1)
				res += (fact(count - 1 - i) / fact(count - hashSum + 1));
			else
				res += (fact(count - 1 - i) / fact(count - hashSum));
			j++;
		}
	}
	return res;
}

int fact(int num){
	if (num == 1 || num == 0)
		return 1;
	else
		return (num*fact(num - 1));
}
*/
//Logic 2
int minRank2(unsigned int num){
	int arr[10], i = 0,count=0,res=0,dup=0;
	unsigned int arr1[1000] = { 0 };
	unsigned int num1 = num;
	while (num1 != 0){
		arr[i++] = num1 % 10;
		num1 = num1 / 10;
	}
	count = compute(arr,0,i - 1,arr1);
	printf("\ncount=%d", count);
	sort(arr1,0,count);
	for (i = 0; i < count; i++){
		printf("%d", arr1[i]);
		if (num == arr1[i]){
			res = i - dup;
			break;
		}
		if (arr1[i] == arr1[i + 1])
			dup++;
	}
	return res;
}


int compute(int* arr, int left, int right,int* arr1){
	static int num;
	if (left == right){
		int pow = 1,j;
		for (j = 0; j <= right; j++)
			pow = pow * 10;
		j = 0;
		pow = pow / 10;
		while (pow > 0){
			arr1[num] += (arr[j++] % 10)*pow;
			pow = pow / 10;
		}
		num++;
      	}
	else{
		for (int i = left; i <= right; i++){
			swap(&arr[left], &arr[i]);
			compute(arr, left + 1, right,arr1);
			swap(&arr[left], &arr[i]);
		}
	}
	return num;
}