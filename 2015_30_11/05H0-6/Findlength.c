#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

/*TEST CASES
num=1234520000 len=4
num=210 len=0
*/
int compute(int* num);
int main(){
	int num[1000];
	printf("\nEnter numbers(Enter z to terminate input):");
	for (int i = 0;num[i]!='z'-'0'; i++)
		scanf_s("%d", &num[i]);
	int len = compute(num);
	printf("\nlen=%d", len);
	_getch();
	return 0;
}
int compute(int* num){
	int flag = 0, i = 1, res;
	static int ind;
	while (flag != 1){
		if (num[ind] < num[ind + 1]){
			i = i * 2;
			ind = i + ind;
		}
		else{
			if (num[ind]>num[ind - 1]){
				flag = 1;
				res = ind;
			}
			else if (num[ind] != 0 && num[ind + 1] == 0){
				res = ind - 1;
				flag = 1;
			}
			else{
				ind = ind -i;
				res= compute(num);
				flag = 1;
			}
		}
	}
	return res;
}

