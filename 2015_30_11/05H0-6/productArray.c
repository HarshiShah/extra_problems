#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

/*TEST CASES
num1=123456  num2=1234  res=152344704
num1=321  num2=65    res=20865
*/
unsigned int* product(unsigned int* num1,int size1, unsigned  int* num2,int size2,int* resSize);

int main(){
	int size1, size2,i,resSize=0;
	unsigned int num1[10], num2[5],*res;
	printf("\nEnter size of first array(max 10):");
	scanf("%d", &size1);
	printf("\nEnter size of second array(max 5):");
	scanf("%d", &size2);
	printf("\nEnter first number");
	for (i = size1-1; i >= 0; i--){
		scanf("%d", &num1[i]);
	}
	printf("\nEnter second number");
	for (i = size2-1; i >=0; i--){
		scanf("%d", &num2[i]);
	}
	printf("\nProduct=");
    res = product(num1, size1,num2,size2,&resSize);
	while (resSize>=0)
	printf("%d",res[resSize--]);
	_getch();
	return 0;
}

unsigned int* product(unsigned int* num1, int size1, unsigned  int* num2, int size2,int* resSize){
	unsigned int prod[15],sum=0,res=0;
	int pv = 1,num,temp,carry,cnt=0,k=1,y=10;
	for (int i = 0; i <size1+size2; i++){
		temp = i;
		for (int j = 0; j <=i; j++){
			if (j<size1 && temp<size2)
			sum += num1[j] * num2[temp];
			temp--;
		}
	//	printf("\n-->sum=%d", sum);
		if ((res + (sum*pv))<2147483648)
		res += (sum*pv);
		else{
			prod[cnt++] = (res+(sum*pv))%pv;
			res = res+(sum*pv)/pv;
		}

		//printf("\n--res=%d", res);
		sum = 0;
		pv = pv * 10;
		}
	prod[cnt] = res;
	*resSize = cnt;
	return prod;
}

