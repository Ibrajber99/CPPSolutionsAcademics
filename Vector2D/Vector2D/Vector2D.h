#pragma once
#include <string>
#include <ostream>
class Vector2D
{
public:
	Vector2D(int x, int y);
	std::string toString() const;
	bool operator<(const Vector2D& rhs)const;
	bool operator==(const Vector2D& rhs)const;
	bool operator!=(const Vector2D& rhs)const;
	bool operator>(const Vector2D& rhs)const;
	bool operator>=(const Vector2D& rhs)const;
	bool operator<=(const Vector2D& rhs)const;
	//Length function is implemented and functional however it hasn't been impemented in operators since im explicitly combining vectors in the overloaded operators
	int length();

	//Extra overloaded insertion operator
	friend std::ostream& operator<<(std::ostream &os,const Vector2D& vec);
private:
	int _x;
	int _y;
};

