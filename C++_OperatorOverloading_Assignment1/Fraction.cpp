
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
#include "pch.h"
#include "Fraction.h"
#include <algorithm>
#include <numeric>
Fraction::Fraction() :_numerator(1), _denomenator(1)
{

	//Default constructor for stream insertion operator
}

Fraction::Fraction(int numerator) :_numerator(numerator), _denomenator(1)	//one arg constructor that takes numerator and assigns a denominator with a value of 1 and simplify it with the GCD
{
	int g = std::gcd(_numerator, _denomenator);
	_numerator /= g;
	_denomenator /= g;
	if (_denomenator < 0) {
		_denomenator *= -1;
		_numerator *= -1;
	}

}

Fraction::Fraction(int numerator, int denomenator) : //2 args constructor that takes denominator and numerator and we find the GCD for that so it can be simplified
	_numerator(numerator), _denomenator(denomenator)
{
	int g = std::gcd(_numerator, _denomenator);
	_numerator /= g;
	_denomenator /= g;
	if (_denomenator < 0) {
		_denomenator *= -1;
		_numerator *= -1;
	}
	if (denomenator == 0) {//throw exception if denomenator is 0
		throw std::out_of_range("0 fatal error");
	}
}


/**********************************************************************************************************
		Overloading logical and arethmatic operators for FRACTION class
**********************************************************************************************************/

bool Fraction::operator==(const Fraction& rhs) const//Comparession between 2 fractions if they are equal
{

	return (this->_numerator * rhs._denomenator == this->_denomenator * rhs._numerator);
}

bool Fraction::operator!=(const Fraction& rhs) const//Comparession between 2 fractions if they are NOT equal
{
	return !(this->_numerator * rhs._denomenator == this->_denomenator * rhs._numerator);
}

bool Fraction::operator>(const Fraction& rhs) const//Comparession between 2 fractions if this->Fractions is BIGGER than other fraction
{
	return (this->_numerator * rhs._denomenator > this->_denomenator* rhs._numerator);
}

bool Fraction::operator<(const Fraction& rhs) const//Comparession between 2 fractions if this->Fractions is SMALLER than other fraction
{
	return (this->_numerator * rhs._denomenator < this->_denomenator * rhs._numerator);
}

bool Fraction::operator>=(const Fraction& rhs) const//Comparession between 2 fractions if this->Fractions is BIGGER or EQUAL than other fraction
{
	return (this->_numerator * rhs._denomenator >= this->_denomenator * rhs._numerator);
}

bool Fraction::operator<=(const Fraction& rhs) const//Comparession between 2 fractions if this->Fractions is SMALLER or EQUAL than other fraction
{
	return (this->_numerator * rhs._denomenator <= this->_denomenator * rhs._numerator);
}

Fraction& Fraction::operator+(Fraction& rhs)//Adding two Fractioon objects with simple math operation with operator (+)
{
	_numerator = _numerator * rhs._denomenator + rhs._numerator * _denomenator;
	_denomenator = _denomenator * rhs._denomenator;
	Fraction* tmp = this;
	return *tmp;
}
Fraction& Fraction::operator+=(Fraction& rhs)//Adding two Fraction objects with simple math operation with operator (+=)
{
	_numerator = _numerator * rhs._denomenator + rhs._numerator * _denomenator;
	_denomenator = _denomenator * rhs._denomenator;
	Fraction* tmp = this;
	return *tmp;
}


Fraction& Fraction::operator-(Fraction& rhs)//Subtracting two Fraction object with simple math operation with operator (-)
{
	_numerator = _numerator * rhs._denomenator - rhs._numerator * _denomenator;
	_denomenator = _denomenator * rhs._denomenator;
	Fraction* tmp = this;
	return *tmp;
}
Fraction& Fraction::operator-=(Fraction& rhs)//Subtracting two Fraction object with simple math operation with operator (-)
{
	_numerator = _numerator * rhs._denomenator - rhs._numerator * _denomenator;
	_denomenator = _denomenator * rhs._denomenator;
	Fraction* tmp = this;
	return *tmp;
}
Fraction& Fraction::operator*(Fraction& rhs)//Multiplying two Fractions with simple math operation with operator (*)
{
	this->_numerator = _numerator * rhs._numerator;
	this->_denomenator = _denomenator * rhs._denomenator;
	Fraction* tmp = this;
	return *tmp;
}

Fraction& Fraction::operator*=(Fraction& rhs)//Multiplying two Fractions with simple math operation with operator (*=)
{
	this->_numerator *= rhs._numerator;
	this->_denomenator *= rhs._denomenator;
	Fraction* tmp = this;
	return *tmp;
}

Fraction& Fraction::operator/(Fraction& rhs)//Dividing two Fractions with simple math operation with operator (/)
{
	Fraction tmp(rhs);
	rhs._numerator = rhs._denomenator;
	rhs._denomenator = tmp._numerator;
	this->_numerator = this->_numerator * rhs._numerator;
	this->_denomenator = this->_denomenator * rhs._denomenator;

	return *this;

}

Fraction& Fraction::operator/=(Fraction& rhs)//Dividing two Fractions with simple math operation with operator (/=)
{
	Fraction tmp(rhs._denomenator, rhs._numerator);
	this->_numerator *= tmp._numerator;
	this->_denomenator *= tmp._denomenator;
	if (this->_numerator < 0 && this->_denomenator < 0) {
		this->_numerator *= -1;
		this->_denomenator *= -1;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fra)//overloaded Output stream ostream that extracxts denomenator and numerator of the fraction
{
	Fraction tmp(fra);
	os << tmp._numerator << "/" << tmp._denomenator;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& fra)//overloaded Input stream istream that inserts a sequnce of characters accordingly with denomenator and numerator of the fraction
{
	char D;
	is >> fra._numerator >> D >> fra._denomenator;
	return is;
}


/**********************************************************************************************************
	Declaring Global/Free functions so we can compare our user defined objects with native like data types
**********************************************************************************************************/


bool operator>(int x, Fraction& rhs) {//Declaring global function that compares if INT data type is bigger than our user defined type 

	return (x > rhs._numerator / rhs._denomenator);

}
bool operator<(int x, Fraction& rhs) {//Declaring global function that compares if INT data type is smaller than our user defined type 

	return (x < rhs._numerator / rhs._denomenator);

}

Fraction operator+(int x, Fraction& rhs) {//Declaring global function that Adds an INT data type with our user defined type with an overloaded operator (+)
	Fraction tmp{ rhs };
	tmp._numerator = x * tmp._denomenator + tmp._numerator;
	return rhs;
}

Fraction operator+=(int x, Fraction& rhs) {//Declaring global function that Adds an INT data type with our user defined type with an overloaded operator (+=)
	rhs._numerator = x * rhs._denomenator + rhs._numerator;
	return rhs;
}
Fraction operator+=(Fraction& rhs, int x) {//Declaring global function that Adds  our user defined type with INT data type using overloaded operator (+)
	rhs._numerator += x * rhs._denomenator;
	return rhs;
}
Fraction operator+(Fraction& rhs, int x) {//Declaring global function that Adds  our user defined type with INT data type using overloaded operator (+=)
	rhs._numerator += x * rhs._denomenator;
	return rhs;
}

Fraction operator-(int x, Fraction& rhs) {//Declaring global function that Subtracts an INT data type with our user defined type with an overloaded operator (-)
	Fraction tmp(x);

	tmp._numerator = (rhs._denomenator * tmp._numerator) - rhs._numerator;
	tmp._denomenator *= rhs._denomenator;
	return tmp;

}
Fraction operator-(Fraction& rhs, int x) {//Declaring global function that Subtracts our user defined type with INT data type using an overloaded operator (-)
	rhs._numerator = (rhs._numerator - (x * rhs._denomenator));
	return rhs;

}

Fraction operator-=(int x, Fraction& rhs) {//Declaring global function that Subtracts INT data type with our user defined type using an overloaded operator (-=)
	Fraction tmp(x);

	tmp._numerator = (rhs._denomenator * tmp._numerator) - rhs._numerator;
	tmp._denomenator *= rhs._denomenator;
	return tmp;

}
Fraction operator-=(Fraction& rhs, int x) {//Declaring global function that Subtracts our user defined type with INT data type using an overloaded operator (-=)

	rhs._numerator = (rhs._numerator - (x * rhs._denomenator));
	return rhs;

}

Fraction operator*(int x, Fraction& rhs)//Declaring global function that Multiplies an INT data type with our user defined type with an overloaded operator (*)
{
	Fraction tmp(x);
	tmp._denomenator = tmp._denomenator * rhs._denomenator;
	tmp._numerator = tmp._numerator * rhs._numerator;
	return tmp;
}

Fraction operator*(Fraction& rhs, int x) //Declaring global function that Multiplies our user defined type with INT data type using an overloaded operator (*)
{
	Fraction tmp(x);
	tmp._denomenator = tmp._denomenator * rhs._denomenator;
	tmp._numerator = tmp._numerator * rhs._numerator;
	return tmp;
}

Fraction operator*=(int x, Fraction& rhs)//Declaring global function that Multiplies an INT data type with our user defined type with an overloaded operator (*=)
{
	rhs._numerator *= x;
	rhs._denomenator = 1;
	return rhs;
}

Fraction operator*=(Fraction& rhs, int x)//Declaring global function that Multiplies our user defined type with INT data type using an overloaded operator (*)
{
	rhs._numerator *= x;
	rhs._denomenator *= 1;
	return rhs;
}

Fraction operator/(int x, Fraction& rhs)//Declaring global function that Divides an INT data type with our user defined type with an overloaded operator (/)
{

	Fraction tmp;
	tmp._denomenator = 1 * rhs._numerator;
	tmp._numerator = x * rhs._denomenator;
	return tmp;
}

Fraction operator/(Fraction& rhs, int x)//Declaring global function that Divides our user defined type with INT data type using an overloaded operator (/)
{
	Fraction tmp(x);
	tmp._numerator = tmp._denomenator * rhs._numerator;
	tmp._denomenator = x * rhs._denomenator;
	return tmp;

}

Fraction operator/=(int x, Fraction& rhs)//Declaring global function that Divides an INT data type with our user defined type with an overloaded operator (/=)
{
	rhs._numerator = rhs._numerator * 1;
	rhs._denomenator = x * rhs._denomenator;
	return rhs;
}

Fraction operator/=(Fraction& rhs, int x)//Declaring global function that Divides our user defined type with INT data type using an overloaded operator (/=)
{
	rhs._numerator = rhs._numerator * 1;
	rhs._denomenator = x * rhs._denomenator;
	return rhs;
}


