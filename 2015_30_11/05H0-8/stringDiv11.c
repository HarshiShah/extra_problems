#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
/*TEST CASES
num=111		count=3		res=0
num=111		count=4		res=1
num=1111	count=3		res=1
num=1111	count=8		res=1
num=222		count=3		res=0
num=605		count=16	res=1
num=6050	count=7		res=1
*/
int validate(char* num, int count);
int check(int* num);
int validate2(char* num, int count);
int main(){
	char num[1000];
	int count;
	printf("\nEnter number");
	scanf("%s", num);
	printf("\nEnter number of occurences");
	scanf("%d", &count);
	int res = validate(num, count);
	if (res == 1)
		printf("\nDivisible by 11");
	else
		printf("\nNot divisible by 11");
	_getch();
	return 0;
}

//The following function generates Q and sends it to check()
int validate(char* num, int count){
	int length = 0,j = 0, number[10000], i,flag=0;
	for (i = 0; num[i] != '\0'; i++)
		length++;
	for (i = 0; i <length*count; i++){
		if (num[j] == '\0')
			j = 0;
		number[i] = num[j++] - '0';
	}
	number[i] = -1;
	return check(&number);
}

//the following function computes the differences between sum of odd and even places and checks divisibility 
int check(int* num){
	int flag = 0, even = 0, odd = 0,i,number[10000];
	unsigned int diff;
	for (i = 0; num[i]!=-1; i++){
		if (flag == 0){
			even += num[i];
			flag = 1;
		}
		else{
			odd += num[i];
			flag = 0;
		}
	}
    diff = even - odd;
    if (diff<0)
		diff = diff*-1;
	if (diff == 0)
		return 1;
	else if (diff > 10){
		i = 0;
		//the following code converts the difference to a string and uses recursion
		while (diff != 0){
			number[i++] = diff - ((diff/10)*10);
			diff = diff/10;
		}
		number[i] = -1;
		return check(number);
	}
	else
		return 0;
}

//the following method checks divisibility by directly computing the difference in odd and even places in Q without generating it
int validate2(char* num, int count){
	int even = 0,temp, odd = 0,flag=0,diff,i;
	for (i = 0; num[i] != '\0'; i++){
		if (flag == 0){
			odd +=( num[i] - '0');
			flag = 1;
		}
		else{
			even += (num[i] - '0');
			flag = 0;
		}
	}
	temp = odd;
	//the following computes even and odd sum in Q based on number of digits
	if ((i % 2) == 0){
		odd = odd*count;
		even = even*count;
	}
	else{
		odd = odd*((count + 1) / 2)+(even*(count/2));
		even = even*((count+1) / 2)+(temp*(count/2));
	}
	diff = odd - even;
	printf("%d %d %d", odd, even, diff);
	//the following code checks if the difference is divisible by 11 without using recursion
	if (diff < 1)
		diff = diff*-1;
	flag = 0;
	odd = 0;
	even = 0;
	while (diff!=0){
		if (flag == 0){
			odd += diff%10;
			flag = 1;
		}
		else{
			even += diff%10;
			flag = 0;
		}
		diff = diff / 10;
		if (diff==0 &&(odd-even>9||even-odd>9))
			diff = odd - even;
        if (diff < 1)
			diff = diff*-1;
	}
	if ((odd-even) == 0)
		return 1;
	else
	    return 0;
}