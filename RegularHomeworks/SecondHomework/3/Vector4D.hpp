#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vector4D {

public:

    Vector4D(double, double, double, double);
    const double& operator[](int index) const;
    double& operator[](int index) ;

    Vector4D operator+(const Vector4D&) const;
    Vector4D& operator+=(const Vector4D&);

    Vector4D operator-(const Vector4D&) const;
    Vector4D& operator-=(const Vector4D&);

    Vector4D operator*(const Vector4D&) const;
    Vector4D operator*(double) const;
    Vector4D& operator*=(const Vector4D&);
    Vector4D& operator*=(double);

    Vector4D operator/(const Vector4D&) const;
    Vector4D& operator/=(const Vector4D&);

    bool operator==(const Vector4D&) const;
    bool operator!=(const Vector4D&) const;
    bool operator<(const Vector4D&) const;
    bool operator>(const Vector4D&) const;
    bool operator<=(const Vector4D&) const;
    bool operator>=(const Vector4D&) const;

    bool operator!() const;
    Vector4D operator-() const;
private:
    double first;
    double second;
    double third;
    double fourth;
    vector<double> myVector;
};