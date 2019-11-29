#include "Cubic.h"
#include <iostream>
#include <cmath>

using namespace std;

Cubic::Cubic() {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}

Cubic::Cubic(int a1, int b1, int c1, int d1) {
	a = a1;
	b = b1;
	c = c1;
	d = d1;
}

int Cubic::getA() const {
	return a;
}

int Cubic::getB() const {
	return b;
}

int Cubic::getC() const {
	return c;
}

int Cubic::getD() const {
	return d;
}

Cubic Cubic::operator+(Cubic rhs) {
	return Cubic(a + rhs.a, b + rhs.b, c + rhs.c, d + rhs.d);
}

Cubic Cubic::operator-(Cubic rhs) {
	return Cubic(a - rhs.a, b - rhs.b, c - rhs.c, d - rhs.d);
}

Cubic Cubic::operator*(int rhs) {
	return Cubic(a * rhs, b * rhs, c * rhs, d * rhs);
}

Cubic Cubic::operator*(double rhs) {
	return Cubic(a * rhs, b * rhs, c * rhs, d * rhs);
}

Cubic& Cubic::operator+=(Cubic rhs) {
	a += rhs.a;
	b += rhs.b;
	c += rhs.c;
	d += rhs.d;
	return *this;
}

Cubic& Cubic::operator-=(Cubic rhs) {
	a -= rhs.a;
	b -= rhs.b;
	c -= rhs.c;
	d -= rhs.d;
	return *this;
}

bool Cubic::operator==(Cubic rhs) {
	return (a == rhs.a && b == rhs.b && c == rhs.c && d == rhs.d);
}

bool Cubic::operator!=(Cubic rhs) {
	return (a != rhs.a || b != rhs.b || c != rhs.c || d != rhs.d);
}

int Cubic::retCoeff(int p) {
	switch (p)
	{
	default:
		break;
	case 0: return d;
		break;
	case 1: return c;
		break;
	case 2: return b;
		break;
	case 3: return a;
		break;
	}
}

int Cubic::calculateCubic(int x) {
	return (a * pow(x, 3) + b * pow(x, 2) + c * pow(x, 1) + d);
}




const string cube = "x^3 +";
const string square = "x^2 +";
const string ex = "x +";
//need to look at the signs of the coefficients and change based on that
ostream& operator<<(ostream& outStream, const Cubic& cubic) {
	outStream << cubic.getA() << cube
		<< cubic.getB() << square
		<< cubic.getC() << ex
		<< cubic.getD();
	return outStream;
}

//need to do checks and tidy up, ask for and respect signs of coefficients
istream& operator>>(istream& inStream, Cubic& cubic) {
	int w;
	int x;
	int y;
	int z;

	inStream >> w >> x
		>> y >> z;
	cubic = Cubic(w, x, y, z);
	return inStream;
}