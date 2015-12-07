#include <stdio.h>
#include <conio.h>

unsigned int result(unsigned int x, unsigned int y, unsigned int z);
unsigned int result1(unsigned int x, unsigned int y, unsigned int z);

int main(){
	unsigned int x, y, a;
	printf("\nEnter value of x,y and a");
	scanf_s("%lu %lu %lu", &x,&y,&a);
	unsigned int ans = result(x, y, a);
	printf("%lu", ans);
	_getch();
	return 0;
}

unsigned int result(unsigned int x, unsigned int y, unsigned int z){
	unsigned int pow = 0, mod, tempMod, res=1;
	tempMod = (x*x) % z;
	while(y != 0){
		pow++;
		mod = y % 2;
		y = y / 2;
		if (pow > 2){
			if (tempMod == 1)
				break;
			else
				tempMod = ((tempMod%z)*(tempMod%z) % z);
		}
		if (mod == 1){
			if(pow==1)
				res = x%z;
     		else
	     		res = (res*tempMod) % z;
			}
	     }
	return res;
}

unsigned int result1(unsigned int x, unsigned int y, unsigned int z){
	unsigned int result=1;
	for (int i = 0; i < y; i++)
		result = result*x;
	return (result%z);
}