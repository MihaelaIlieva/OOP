#include "Vector4D.hpp"

Vector4D::Vector4D(double first, double second, double third, double fourth)
{
	this->first = first;
	this->second = second;
	this->third = third;
	this->fourth = fourth;

	this->myVector.push_back(this->first);
	this->myVector.push_back(this->second);
	this->myVector.push_back(this->third);
	this->myVector.push_back(this->fourth);
}

const double& Vector4D::operator[](int index) const
{
	switch (index) {
	case 0: return this->first;
	case 1: return this->second;
	case 2: return this->third;
	case 3: return this->fourth;
	}
}

double& Vector4D::operator[](int index)
{
	return myVector[index];
}

Vector4D Vector4D::operator+(const Vector4D& other) const
{
	double newFirst = (this->first + other.first);
	double newSecond = (this->second + other.second);
	double newThird = (this->third + other.third);
	double newFourth = (this->fourth + other.fourth);

	return Vector4D(newFirst, newSecond, newThird, newFourth);
}

Vector4D& Vector4D::operator+=(const Vector4D& other)
{
	*this = *this + other;
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& other) const
{
	double newFirst = (this->first - other.first);
	double newSecond = (this->second - other.second);
	double newThird = (this->third - other.third);
	double newFourth = (this->fourth - other.fourth);

	return Vector4D(newFirst, newSecond, newThird, newFourth);
}

Vector4D& Vector4D::operator-=(const Vector4D& other)
{
	*this = *this - other;
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& other) const
{
	double newFirst = (this->first * other.first);
	double newSecond = (this->second * other.second);
	double newThird = (this->third * other.third);
	double newFourth = (this->fourth * other.fourth);

	return Vector4D(newFirst, newSecond, newThird, newFourth);
}

Vector4D Vector4D::operator*(double number) const
{
	double newFirst = (this->first*number);
	double newSecond = (this->second *number);
	double newThird = (this->third * number);
	double newFourth = (this->fourth *number);

	return Vector4D(newFirst, newSecond, newThird, newFourth);
}

Vector4D& Vector4D::operator*=(const Vector4D& other)
{
	*this = *this * other;
	return *this;
}

Vector4D& Vector4D::operator*=(double number)
{
	*this = *this * number;
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& other) const
{
	double newFirst = (this->first / other.first);
	double newSecond = (this->second / other.second);
	double newThird = (this->third / other.third);
	double newFourth = (this->fourth / other.fourth);

	return Vector4D(newFirst, newSecond, newThird, newFourth);
}

Vector4D& Vector4D::operator/=(const Vector4D& other)
{
	*this = *this / other;
	return *this;
}

bool Vector4D::operator==(const Vector4D& other) const
{
	if (this->first == other.first &&
		this->second == other.second &&
		this->third == other.third &&
		this->fourth == other.fourth) {
		return true;
	}
	return false;
}

bool Vector4D::operator!=(const Vector4D& other) const
{
	if (this->first != other.first ||
		this->second != other.second ||
		this->third != other.third ||
		this->fourth != other.fourth) {
		return true;
	}
	return false;
}

bool Vector4D::operator<(const Vector4D& other) const
{
	if (this->first < other.first) {
		return true;
	}
	else if (this->first > other.first) {
		return false;
	}
	else {
		if (this->second < other.second) {
			return true;
		}
		else if (this->second > other.second) {
			return false;
		}
		else {
			if (this->third < other.third) {
				return true;
			}
			else if (this->third > other.third) {
				return false;
			}
			else {
				if (this->fourth < other.fourth) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

bool Vector4D::operator>(const Vector4D& other) const
{
	if (this->first > other.first) {
		return true;
	}
	else if (this->first < other.first) {
		return false;
	}
	else {
		if (this->second > other.second) {
			return true;
		}
		else if (this->second < other.second) {
			return false;
		}
		else {
			if (this->third > other.third) {
				return true;
			}
			else if (this->third < other.third) {
				return false;
			}
			else {
				if (this->fourth > other.fourth) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

bool Vector4D::operator<=(const Vector4D& other) const
{
	if (*this < other || *this == other) {
		return true;
	}
	return false;
}

bool Vector4D::operator>=(const Vector4D& other) const
{
	if (*this > other || *this == other) {
		return true;
	}
	return false;
}

bool Vector4D::operator!() const
{
	if (*this==Vector4D(0,0,0,0)) {
		return true;
	}
	return false;
}

Vector4D Vector4D::operator-() const
{
	return Vector4D(-this->first,-this->second,-this->third,-this->fourth);
}