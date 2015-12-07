#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>

int* rotate(int* arr, int length,int rot,int mode);
int search(int* arr, int left,int right,int element,int order);
/*TEST CASES
arr={1,2,3,4,5}
mode=0	rot=3	element=2
res=5

arr={1,2,3,4,5}
mode=1	rot=3	element=2
res=4

arr={1,1,2,2,3,3}
mode=1	rot=4	element=2
res=6  //returns any possible value in case of duplicates

arr={10,7,6,4,3,2,1}
mode=0	rot=3	element=6
res=6

arr={10,7,6,4,3,2,1}
mode=1	rot=3	element=6
res=7

arr={2,4,6,8,10}
mode=0	rot=125	element=6
res=3

arr={10,7,6,4,3,2,1}
mode=0	rot=142	element=8
Element not found
*/
int main(){
	int arr[100],*res, rot, element, length,mode,order=0;
	printf("\nEnter array length");
	scanf_s("%d", &length);
	if (length > 0){
		printf("\nEnter array elements:");
		for (int i = 0; i < length; i++)
		scanf_s("%d", &arr[i]);
		printf("\nEnter number of rotations:");
		scanf("%d", &rot);
		printf("\nEnter mode of rotation:(1 for anti-clockwise and 0 for clockwise");
		scanf("%d", &mode);
		if (mode == 0 || mode == 1){
			if (arr[0] > arr[1])
				order = 1;
			res = rotate(arr, length, rot,mode);
			printf("\nThe rotated array is\n");
			for (int i = 0; i < length; i++)
				printf(" %d", res[i]);
			printf("\nEnter the number to be searched:");
			scanf("%d", &element);
			int pos = search(arr,0, length-1, element,order);
			if (pos == -1)
				printf("\n\nElement not found");
			else
			printf("\nThe position of required element in the rotated array is %d", pos+1);
		
		}
	}
	_getch();
	return 0;

}

int* rotate(int* arr, int length, int rot,int mode){
	int temp[100],j=0,k;
	if (mode == 1)
		rot = length - rot;
	if (rot > length)
		rot = rot%length;
	if (rot>0){
		k = length-1;
		for (int i = 0; i <rot; i++)
			temp[i] = arr[k--];
		k = length -1;
		for (int i = length-rot-1; i >=0; i--)
			arr[k--] = arr[i];
		k = rot;
		for (int i = 0; i <rot; i++)
			arr[i] = temp[--k];
		}
	return arr;
}


int search(int* arr,int left, int right, int element,int order){
	if (left>right)
		return -1;
	int mid = (left + right) / 2;
	if (element==arr[mid])
		return mid;
	if (element == arr[left])
		return left;
	if (element == arr[right])
		return right;
	if (order == 0){
		if (arr[left] < arr[mid]){
			if (element > arr[left] && element < arr[mid])
				return search(arr, left + 1, mid - 1, element,order);
			else if ((arr[mid]>arr[right]) && ((element < arr[right]) || (element > arr[mid])))
				return search(arr, mid + 1, right - 1, element,order);

		}
		if (arr[mid]<arr[right]){
			if (element < arr[right] && element > arr[mid])
				return search(arr, mid + 1, right - 1, element,order);
			else if ((arr[left]>arr[mid]) && ((element > arr[left]) || (element < arr[mid])))
				return search(arr, left + 1, mid - 1, element,order);
		}
	}
	if (order == 1){
		if (arr[left] > arr[mid]){
			if (element < arr[left] && element > arr[mid])
				return search(arr, left + 1, mid - 1, element,order);
			else if ((arr[mid]<arr[right]) && ((element > arr[right]) ||( element < arr[mid])))
				return search(arr, mid + 1, right - 1, element,order);

		}
		if (arr[mid]>arr[right]){
			if (element > arr[right] && element < arr[mid])
				return search(arr, mid + 1, right - 1, element,order);
			else if ((arr[left]<arr[mid]) && ((element < arr[left]) || (element > arr[mid])))
				return search(arr, left + 1, mid - 1, element,order);
		}
	}
	return-1;
}


