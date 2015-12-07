#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

/*TEST CASES
base2-1011001        base8-131
base2-1101101        base8-155
base2-1111111111     base-1777
base2-1001001001001  base8-11111
base2-100000         base8-40
*/
unsigned int res(int* arr, int size);
int main(){
	int num[100],i,size;
	printf("\nEnter size");
	scanf("%d", &size);
	printf("\nEnter number in binary");
	for (i = 0; i < size; i++){
		scanf("%1d", &num[i]);
	}
	unsigned int num8 = res(num, size);
	printf("\n\nNumber in base 2:");
	for (i = 0; i < size; i++)
		printf("%d", num[i]);
	printf("\n\nNumber in base 8 is: %d", num8);
	_getch();
	return 0;
}

//the following function groups 3 binary digits to form a base 8 number
unsigned int res(int* arr, int size){
	int j, temp = 1, i = size - 1;
	unsigned int num = 0;
	while (i >= 0){
		if (i == 1){
			j = arr[1] + arr[0] * 2;
			num += (j*temp);
			i = -1;
		}
		else if (i == 0){
			num += (arr[0] * temp);
			i = -1;
		}
		else{
			j = arr[i] + arr[i - 1] * 2 + arr[i - 2] * 4;
			num += (j*temp);
			temp = temp * 10;
			i = i - 3;
		}
	}
	return num;
}