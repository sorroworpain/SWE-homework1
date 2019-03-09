#include "pch.h"
#include <iostream>

#include"main.h"
using namespace std;






void Equ_generator(void) {
	int Ope;
	float Value;
	int Ope_Num;

	Unit unit[Equ_Len];

	unit[0].ope = ' ';

	Ope_Num = rand() % 3 + 3;
	unit[Ope_Num+1].ope = '#';//maybe deleted later

	for (int i = 1; i <=Ope_Num; i++) {
		Ope = rand() % 4;
		switch (Ope){
		case 0: {unit[i].ope = '+'; }break;
		case 1: {unit[i].ope = '-'; }break;
		case 2: {unit[i].ope = '*'; }break;
		case 3: {unit[i].ope = '/'; }break;
		default: {};
		}
	}
	for (int i = 0; i < Ope_Num+2; i++) {
		int j = i - 1;
		if (unit[i].ope == '/') { unit[i].value = rand() % 100 + 1; }
		else { unit[i].value = rand() % 101; }
	}
	for (int i = 0; i <=Ope_Num; i++) { unit[i].flag = 0; }

	for (int i = 0; i <= Ope_Num; i++) {
		cout << unit[i].ope << unit[i].value;
		fp<< unit[i].ope << unit[i].value;
	}
	cout << '=' ;
	fp << '=';

	float answer = Equ_calculator(unit);
	cout << answer << endl;
	fp << answer << endl;

}

float Equ_calculator(Unit unit[Equ_Len]) {
	float output=0;
	Unit unit_temp[Equ_Len];
	int m = 0,n=0,p=0;
	unit_temp[0].ope = '+';
	for (int i = 0; i < Equ_Len; i++)unit_temp[i].value = 0;
	for (int i = 0; i <Equ_Len; i++) { unit_temp[i].flag = 0; }
	for (int i = 0; i < Equ_Len; i++) {
		int j = i + 1;
		switch (unit[j].ope) {
		case '*': {
			unit[j].value = unit[i].value * unit[j].value;
		}break;
		case '/': {
			unit[j].value = unit[i].value /unit[j].value;
		}break;

		default: {};
		}

	}

	for (int i = 0; i <Equ_Len; i++) {
		int j = i + 1;
		switch (unit[j].ope) {
		case '+': {
			unit_temp[m].value = unit[i].value;
			p = m + 1;
			unit_temp[p].ope = '+';
			unit_temp[p].flag = 1;
			m++;
		}break;
		case '-': {
			unit_temp[m].value = unit[i].value;
			p = m + 1;
			unit_temp[p].ope = '-';
			unit_temp[p].flag = -1;
			m++;
		}break;
		case '#': {
			unit_temp[m].value = unit[i].value;
			p = m + 1;
			unit_temp[p].ope = '#';
		}break;
		default: {};
		}
	}
	unit_temp[0].flag = 1;
	while (n < Equ_Len && unit_temp[n].ope != '#') {
		output += unit_temp[n].value*unit_temp[n].flag;
		n++;
	}
	return output;
}
