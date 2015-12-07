#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>

/*TEST CASES
arr={2,4,6,8,10}
num=20
res=1

arr={6,4,8,2,10}
num=20
res=2

arr={1,1,1,1,1}
num=7
res=2

arr={2,3,5,8,10}
num=4
res=1

arr={2,0,5,8,10}
Only positive time values allowed

arr={2,2,2,2,2,2,2,2,2,2}
num=11
res=1

*/
int findShop(int* arr, int size, int num);
int main(){
	int arr[1000], size, num, res;
	printf("\nEnter number of shops:");
	scanf("%d", &size);
	for (int i = 0; i < size; i++){
		printf("\nEnter shop %d time(positive):",i + 1);
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < size; i++){
		if (arr[i] <= 0){
			printf("\nOnly positive time values allowed");
			_getch();
			return 0;
		}
	}
	printf("\nEnter customer number:");
	scanf("%d", &num);
	res = findShop(arr, size, num);
	printf("\nThe customer enters shop %d", res);
	_getch();
	return 0;
}

int findShop(int* arr, int size, int num){
	int curr, sec=0, i,a,lcm=1;
	if (num <= size)
		return num;
	else
		curr = size;
	while (curr != num){
		sec++;		
		for (i = 0; i < size; i++){
				if ((sec%arr[i]) == 0)
					curr++;
				if (curr == num)
					break;
			
		}
	}
	return i + 1;
}

