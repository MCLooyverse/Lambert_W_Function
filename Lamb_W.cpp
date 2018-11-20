#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>



const float e = 2.7182818284590452353602874713527;
unsigned int Precision = 10;



double WInv(double x) { return x * pow(e, x); }



double LambW(double x)
{
	if (x >= -1.0 / e)
	{
		int Place0 = 0;

		if (WInv(1) < x)
		{
			while (WInv(pow(10, Place0 + 1)) < x)
				++Place0;
		}
		else if (WInv(1) > x)
		{
			while (WInv(pow(10, Place0)) > x)
				--Place0;
		}

		double Output = 0;

		for (int Place = Place0; Place > Place0 - Precision; --Place)
		{
			unsigned short int Digit = 9;
			while (WInv(Output + Digit * pow(10, Place)) > x)
				--Digit;

			Output += Digit * pow(10, Place);
		}

		return Output;
	}
	else
		return 0;
}
