// Vector2D.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Vector2D.h"
#include <sstream>

// TODO: This is an example of a library function
void fnVector2D()
{
}

Vector2D::Vector2D(int x, int y):_x(x),_y(y)
{
	//Throw exception if one of parameters is less than 0
	if (x < 0 || y < 0) {
		throw std::out_of_range("Cannot be intialized with an amount lesser than 0");
	}
	//if combining them together returns a 
	else if (x + y < 0) {
		throw std::out_of_range("Cannot be intialized with an amount lesser than 0");
	}
}



std::string Vector2D::toString() const
{
	std::stringstream ss;
	ss << "("<< _x <<"," << _y << ")";
	return ss.str();
}



bool Vector2D::operator==(const Vector2D& rhs)const
{
	return this->_x + this->_y == rhs._x + rhs._y;
}

bool Vector2D::operator!=(const Vector2D& rhs) const
{
	return this->_x + this->_y != rhs._x + rhs._y;
}

bool Vector2D::operator>(const Vector2D& rhs) const
{
	return this->_x + this->_y > rhs._x + rhs._y;
}

bool Vector2D::operator>=(const Vector2D& rhs) const
{
	return !(this->_x + this->_y < rhs._x + rhs._y) || this->_x + this->_y == rhs._x + rhs._y;
}

bool Vector2D::operator<=(const Vector2D& rhs) const
{
	return !(this->_x + this->_y > rhs._x + rhs._y) || this->_x + this->_y == rhs._x + rhs._y;
}


//Length function
int Vector2D::length()
{
	return this->_x +this->_y;
}

bool Vector2D::operator<(const Vector2D& rhs)const
{
	return this->_x +this->_y  < rhs._x + rhs._y;
}


//Extra
std::ostream& operator<<(std::ostream& os, const Vector2D& vec)
{
	os << "(" << vec._x << "," << vec._y << ")";
	return os;
}
