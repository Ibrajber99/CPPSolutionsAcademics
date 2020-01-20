/*
* @file
* @author  <Ibrahim Jaber>
* @version 1.0
*
*
* @section DESCRIPTION
* < Fraction Oveloded operators>
*
*
* @section LICENSE
* <any necessary attributions>
*
* Copyright 2019 <Brandon Houston>
* Permission to use, copy, modify, and/or distribute this software for
* any purpose with or without fee is hereby granted, provided that the
* above copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*/
// Vector2D.cpp : Defines the functions for the static library.
//
#pragma once
#include <iostream>
#include <sstream>
#include <istream>
#include<ostream>
class Fraction//Class Declaration
{


public:
	//Numerator and denomenator
	int _numerator;
	int _denomenator;
	//Making Class constructors
	Fraction();
	Fraction(int numerator);
	Fraction(int numerator, int denomenator);
	/****************************************************
	 Logical Operators in Class  for Operator Overloading
	*****************************************************/

	bool operator==(const Fraction& rhs)const;
	bool operator!=(const Fraction& rhs)const;
	bool operator>(const Fraction& rhs)const;
	bool operator<(const Fraction& rhs)const;
	bool operator>=(const Fraction& rhs)const;
	bool operator<=(const Fraction& rhs)const;


	/****************************************************
			Arithmatic operators for the class
	*****************************************************/
	Fraction& operator+(Fraction& rhs);
	Fraction& operator+=(Fraction& rhs);
	Fraction& operator-(Fraction& rhs);
	Fraction& operator-=(Fraction& rhs);
	Fraction& operator*(Fraction& rhs);
	Fraction& operator*=(Fraction& rhs);
	Fraction& operator/(Fraction& rhs);
	Fraction& operator/=(Fraction& rhs);


	/****************************************************
	Friend functions for stream insertion and extraction
	*****************************************************/
	friend std::ostream& operator<<(std::ostream& os, const Fraction& vec);
	friend std::istream& operator>>(std::istream& is,  Fraction& vec);

};

/********************************************************************************************
//Logical operators Global/Fiend function so we can compare Data types with user-defined type
*********************************************************************************************/
bool operator>(int x, Fraction& rhs);
bool operator<(int x, Fraction& rhs);


/********************************************************************************************
Arethmetic operators Global/Fiend function so we can compare Data types with user-defined type
*********************************************************************************************/
Fraction operator+(int x, Fraction& rhs);
Fraction operator+=(int x, Fraction& rhs);
Fraction operator+=(Fraction& rhs, int x);
Fraction operator+(Fraction& rhs, int x);


/********************************************************************************************
Arethmetic operators Global/Fiend function so we can compare Data types with user-defined type
*********************************************************************************************/
Fraction operator-(int x, Fraction& rhs);
Fraction operator-=(int x, Fraction& rhs);
Fraction operator-=(Fraction& rhs, int x);
Fraction operator-(Fraction& rhs, int x);

/********************************************************************************************
Arethmetic operators Global/Fiend function so we can compare Data types with user-defined type
*********************************************************************************************/
Fraction operator*(int x, Fraction& rhs);
Fraction operator*(Fraction& rhs, int x);
Fraction operator*=(int x, Fraction& rhs);
Fraction operator*=(Fraction& rhs, int x);

/********************************************************************************************
Arethmetic operators Global/Fiend function so we can compare Data types with user-defined type
*********************************************************************************************/
Fraction operator/(int x, Fraction& rhs);
Fraction operator/(Fraction& rhs, int x);
Fraction operator/=(int x, Fraction& rhs);
Fraction operator/=(Fraction& rhs, int x);


