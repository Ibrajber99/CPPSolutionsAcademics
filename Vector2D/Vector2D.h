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
	friend std::ostream& operator<<(std::ostream &os,const Vector2D& vec);
private:
	int _x;
	int _y;
};

