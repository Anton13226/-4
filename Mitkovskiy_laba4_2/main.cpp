// Mitkovskiy_laba4_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Mit.h"

using namespace Mit;

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "rus");

	ifstream ReadFile("input.txt");
	ofstream WriteFile("output.txt");

	int size;
	int size2;
	long double Rezalt;
	string text;
	string DecText;
	Alphavit *alphavit;
	
	
	if ((text = Read_File(ReadFile, alphavit,size)) == "")
	{
		cout << "ERROR!!!";
		getchar();
		getchar();
		return 0;
	}
	size2 = text.length();
	Rezalt = Coding(text, alphavit, size);
	DecText = Decoding(alphavit, Rezalt, size2,size);
	Write_File(WriteFile, alphavit, size,Rezalt, DecText);


	return 0;
}
/*
	char A = 'a';
	char B = 'b';
	char C = 'c';

	long double A_l = 0;
	long double A_r = 0;
	long double B_l = 0;
	long double B_r = 0;
	long double C_l = 0;
	long double C_r = 0;

	long double L_old = 0;
	long double R_old = 0;
	long double L_new = 0;
	long double R_new = 0;

	long double Rezultat = 0;

	int size;
	

	ReadFile >> size;

	char *simbol = new char[size];

	for (int i = 0; i < size; i++)
	{
		ReadFile >> simbol[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			A_l = 0;
			A_r = 0.5;
			B_l = 0.5;
			B_r = 0.8;
			C_l = 0.8;
			C_r = 1;

		}
		if ((simbol[i] == A) && (i == 1))
		{
			L_old = A_l;
			R_old = A_r;
			R_new = L_old + (R_old - L_old) * A_r;
			L_new = L_old + (R_old - L_old) * A_l;
			continue;
		}
		if ((simbol[i] == B) && (i == 1))
		{
			L_old = B_l;
			R_old = B_r;
			R_new = L_old + (R_old - L_old) * B_r;
			L_new = L_old + (R_old - L_old) * B_l;
			continue;
		}
		if ((simbol[i] == C) && (i == 1))
		{
			L_old = C_l;
			R_old = C_r;
			R_new = L_old + (R_old - L_old) * C_r;
			L_new = L_old + (R_old - L_old) * C_l;
			continue;
		}
		if (simbol[i] == A)
		{
			L_old = L_new;
			R_old = R_new;
			R_new = L_old + (R_old - L_old) * A_r;
			L_new = L_old + (R_old - L_old) * A_l;
			continue;
		}
		if (simbol[i] == B)
		{
			L_old = L_new;
			R_old = R_new;
			R_new = L_old + (R_old - L_old) * B_r;
			L_new = L_old + (R_old - L_old) * B_l;
			continue;
		}
		if (simbol[i] == C)
		{
			L_old = L_new;
			R_old = R_new;
			R_new = L_old + (R_old - L_old) * C_r;
			L_new = L_old + (R_old - L_old) * C_l;
			continue;
		}
	} 
	Rezultat = (L_new + R_new) / 2;

	WriteFile << size<< endl;
	WriteFile << Rezultat;

	return 0;
}
*/
