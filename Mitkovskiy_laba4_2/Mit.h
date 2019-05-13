#pragma once
#include <math.h>
#include <iostream>
#include <stdio.h> 
#include "stdlib.h" 
#include "fstream"
#include <string>
#include <vector>
using namespace std;

namespace Mit 
{
	struct Alphavit
	{
		char Symbols;
		long double Probability;
		long double Symbols_left;
		long double Symbols_right;
	};

	string Read_File(ifstream &ReadFile, Alphavit *&alphavit, int &Size_Alpavit);
	long double Coding(string &text, Alphavit *alphavit, int &size);
	string Decoding(Alphavit *alphavit, long double Rezalt, int Size_String, int Size_Alpavit);
	void Write_File(ofstream &WriteFile, Alphavit *alphavit, int Size_Alpavit, long double Rezalt, string DecText);
}