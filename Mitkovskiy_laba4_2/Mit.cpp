#include "stdafx.h"
#include "Mit.h"

string Mit::Read_File(ifstream & ReadFile, Alphavit *&alphavit, int &Size_Alpavit)
{
	string text;

	ReadFile >> Size_Alpavit;
	alphavit = new Alphavit[Size_Alpavit];

	for (int i = 0; i < Size_Alpavit; i++)
	{
		ReadFile >> alphavit[i].Symbols;
		ReadFile >> alphavit[i].Probability;
		if (i == 0)
		{
			alphavit[i].Symbols_left = 0.0;
			alphavit[i].Symbols_right = alphavit[i].Probability;
		}
		else
		{
			alphavit[i].Symbols_left = alphavit[i - 1].Symbols_right;
			alphavit[i].Symbols_right = alphavit[i].Symbols_left + alphavit[i].Probability;
		}
	}

	long double N = 0.0;
	for (int i = 0; i < Size_Alpavit; i++)
	{
		N = N + alphavit[i].Probability;
	}

	if (N != 1)
		return text;

	

	
	getline(ReadFile, text, '\0');
	text.erase(text.begin());
	text.erase(text.begin());

	return text;
}

long double Mit::Coding(string & text, Alphavit *alphavit, int &Size_Alpavit)
{
	long double L_old;
	long double R_old;
	long double L_new;
	long double R_new;
	long double Rezalt;

	for (int i = 0; i < text.length(); i++)
	{
		for (int j = 0; j < Size_Alpavit; j++)
		{
			if (i == 0)
				break;
			if ((text[i] == alphavit[j].Symbols) && (i==1))
			{
				L_old = alphavit[j].Symbols_left;
				R_old = alphavit[j].Symbols_right;
				L_new = L_old + (R_old - L_old)*alphavit[j].Symbols_left;
				R_new = L_old + (R_old - L_old)*alphavit[j].Symbols_right;
				L_old = L_new;
				R_old = R_new;
				break;
			}
			if ((text[i] == alphavit[j].Symbols) && (i == (text.length()-1)))
			{
				L_new = L_old + (R_old - L_old)*alphavit[j].Symbols_left;
				R_new = L_old + (R_old - L_old)*alphavit[j].Symbols_right;
				break;
			}
			if (text[i] == alphavit[j].Symbols)
			{
				L_new = L_old + (R_old - L_old)*alphavit[j].Symbols_left;
				R_new = L_old + (R_old - L_old)*alphavit[j].Symbols_right;
				L_old = L_new;
				R_old = R_new;
				break;
			}
		}
	}
	Rezalt = (L_new + R_new) / 2;

	return Rezalt;
}

string Mit::Decoding(Alphavit * alphavit, long double Rezalt, int Size_String, int Size_Alphavit)
{
	string DecText;
	char *text = new char[Size_String+1];
	for (int i = 0; i < Size_String; i++)
	{
		for (int j = 0; j < Size_Alphavit; j++)
		{
			if ((Rezalt >= alphavit[j].Symbols_left) && (Rezalt < alphavit[j].Symbols_right) && (i == Size_String - 1))
			{
				text[i] = alphavit[j].Symbols;
				Rezalt = ((Rezalt - alphavit[j].Symbols_left) / (alphavit[j].Symbols_right - alphavit[j].Symbols_left));
				text[i + 1] = '\0';
				break;
			}
			if ((Rezalt >= alphavit[j].Symbols_left) && (Rezalt < alphavit[j].Symbols_right))
			{
				text[i] = alphavit[j].Symbols;
				Rezalt = ((Rezalt - alphavit[j].Symbols_left) / (alphavit[j].Symbols_right - alphavit[j].Symbols_left));
				break;
			}

		}
	}
	DecText = text;

	return DecText;
}

void Mit::Write_File(ofstream & WriteFile, Alphavit *alphavit, int Size_Alpavit, long double Rezalt, string DecText)
{
	for (int i = 0; i < Size_Alpavit; i++)
	{
		WriteFile << alphavit[i].Symbols << " [" << alphavit[i].Symbols_left << "; " << alphavit[i].Symbols_right << ")" << endl;
	}
	WriteFile << endl;
	WriteFile << "Кодировка:  " << Rezalt << endl;
	WriteFile << endl;
	WriteFile << DecText;
}
