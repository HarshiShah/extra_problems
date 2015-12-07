#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void inWords(char* day,char* res1);
int ones(int num, char* res, int cnt);
int tens(int num, char* res, int cnt);
int muls(int num, char* res, int cnt);
int months(int num, char*res, int cnt);
int validCheck(int date, int month, int year);

int main(void){
	char res[81], day[81];
	printf("\nEnter date in dd/mm/yyyy format:");
	scanf(" %s",day);
	inWords(day,res);
	printf("\n%s",res);
	_getch();
	return 0;
}

void inWords(char* day,char* res){
	int date, month, year, flag ;
	date = (day[0] - '0') * 10 + (day[1] - '0');
	month = (day[3] - '0') * 10 + (day[4] - '0');
	year = (day[6] - '0') * 1000 + (day[7] - '0') * 100 + (day[8] - '0') * 10 + (day[9] - '0');
	int cnt = 0, i;
	flag = validCheck(date, month, year);
	if (flag == -1){
		i = -1;
		while(i++<8)
			res[i] = "INVALID"[i];
	}
	else{
		//date conversion
		switch (date / 10){
		case 0:cnt = ones(date, res, cnt);
			break;
		case 1:cnt = tens(date, res, cnt);
			break;
		default:cnt = muls(date, res, cnt);
		};
		//month conversion
		cnt = months(month, res, cnt);
		//year conversion;
		int thou = year / 1000;
		year = year - (thou * 1000);
		int hun = year / 100;
		year = year - (hun * 100);

		if (thou > 1){
			cnt = ones(thou, res, cnt);
			i = -1;
			while (i++ < 8)
				res[cnt++] = "Thousand "[i];
			if (hun != 0){
				cnt = ones(hun, res, cnt);
				i = -1;
				while (i++ < 11)
					res[cnt++] = "Hundred and "[i];
			}
		}
		else if (thou == 1){
			int dig = thou * 10 + hun;
			cnt = tens(dig, res, cnt);
		}
		switch (year / 10){
		case 0:cnt = ones(year, res, cnt);
			break;
		case 1:cnt = tens(year, res, cnt);
			break;
		default:cnt = muls(year, res, cnt);
		};
		res[cnt] = '\0';
	}
}

int ones(int num, char* res, int cnt){
	int i = -1;
	switch (num){
	case 1:while (i++<3)
		res[cnt++] = "One "[i];
		break;
	case 2:while (i++<3)
		res[cnt++] = "Two "[i];
		break;
	case 3:while (i++<5)
		res[cnt++] = "Three "[i];
		break;
	case 4:while (i++<4)
		res[cnt++] = "Four "[i];
		break;
	case 5:while (i++<4)
		res[cnt++] = "Five "[i];
		break;
	case 6:while (i++<3)
		res[cnt++] = "Six "[i];
		break;
	case 7:while (i++<5)
		res[cnt++] = "Seven "[i];
		break;
	case 8:while (i++<5)
		res[cnt++] = "Eight "[i];
		break;
	case 9:while (i++<4)
		res[cnt++] = "Nine "[i];
		break;
	default:break;
	};
	return cnt;
}

int tens(int num, char* res, int cnt){
	int i = -1;
	switch (num){
	case 10:while (i++<3)
		res[cnt++] = "Ten "[i];
		break;
	case 11:while (i++<6)
		res[cnt++] = "Eleven "[i];
		break;
	case 12:while (i++<6)
		res[cnt++] = "Twelve "[i];
		break;
	case 13:while (i++<8)
		res[cnt++] = "Thirteen "[i];
		break;
	case 14:while (i++<8)
		res[cnt++] = "Fourteen "[i];
		break;
	case 15:while (i++<7)
		res[cnt++] = "Fifteen "[i];
		break;
	case 16:while (i++<7)
		res[cnt++] = "Sixteen "[i];
		break;
	case 17:while (i++<9)
		res[cnt++] = "Seventeen "[i];
		break;
	case 18:while (i++<8)
		res[cnt++] = "Eighteen "[i];
		break;
	case 19:while (i++<8)
		res[cnt++] = "Nineteen "[i];
		break;
	default:break;
	}
	return cnt;
}

int muls(int num, char* res, int cnt){
	int tens = num / 10;
	int units = num % 10;
	int i = -1;
	switch (tens){
	case 2:while (i++<6)
		res[cnt++] = "Twenty "[i];
		break;
	case 3:while (i++<6)
		res[cnt++] = "Thirty "[i];
		break;
	case 4:while (i++<5)
		res[cnt++] = "Forty "[i];
		break;
	case 5:while (i++<5)
		res[cnt++] = "Fifty "[i];
		break;
	case 6:while (i++<5)
		res[cnt++] = "Sixty "[i];
		break;
	case 7:while (i++<7)
		res[cnt++] = "Seventy "[i];
		break;
	case 8:while (i++<6)
		res[cnt++] = "Eighty "[i];
		break;
	case 9:while (i++<6)
		res[cnt++] = "Ninety "[i];
		break;
	default:break;
	}
	cnt = ones(units, res, cnt);
	return cnt;
}

int months(int num, char* res, int cnt){
	int i = -1;
	switch (num){
	case 1:while (i++<7)
		res[cnt++] = "January "[i];
		break;
	case 2:while (i++<8)
		res[cnt++] = "February "[i];
		break;
	case 3:while (i++<5)
		res[cnt++] = "March "[i];
		break;
	case 4:while (i++<5)
		res[cnt++] = "April "[i];
		break;
	case 5:while (i++<3)
		res[cnt++] = "May "[i];
		break;
	case 6:while (i++<4)
		res[cnt++] = "June "[i];
		break;
	case 7:while (i++<4)
		res[cnt++] = "July "[i];
		break;
	case 8:while (i++<6)
		res[cnt++] = "August "[i];
		break;
	case 9:while (i++<9)
		res[cnt++] = "September "[i];
		break;
	case 10:while (i++<7)
		res[cnt++] = "October "[i];
		break;
	case 11:while (i++<8)
		res[cnt++] = "November "[i];
		break;
	case 12:while (i++<8)
		res[cnt++] = "December "[i];
		break;
	default:break;
	}
	return cnt;
}

int validCheck(int date, int month, int year){
	if (year<0 || month > 12 || date > 31 || month < 1 || date<1)
		return -1;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && date>30)
		return -1;
	else if (month == 2 && (year % 400 == 0 || ((year % 100 != 0) && (year % 4) == 0)) && date > 29)
		return -1;
	else if (month == 2 && (year % 400 != 0 && ((year % 100 == 0) || (year % 4) != 0)) && date >= 29)
		return -1;
	else
		return 1;
}
