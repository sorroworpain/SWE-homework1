#pragma once
#define Equ_Len 7//��ʽ��ֵ��Ŀ���ֵ

extern int Ope_Num;
extern float Value;
extern int Ope;

typedef struct Cal_Unit {
	char ope;
	float value;
	int flag;
}Unit;

extern Unit unit[Equ_Len];


void Equ_generator(void);
float Equ_calculator(Unit unit[Equ_Len]);

