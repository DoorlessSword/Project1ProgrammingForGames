#pragma once
#include <iostream>

using namespace std;

class Cubic
{
public:
	Cubic();
	Cubic(int a, int b, int c, int d);
	
	int getA() const;
	int getB() const;
	int getC() const;
	int getD() const;

	int retCoeff(int p); //return coefficient of power p
	int calculateCubic(int x); //calculate cubic value for x

	//Arithmetic operators
	Cubic operator+(Cubic rhs);
	Cubic operator-(Cubic rhs);
	Cubic operator*(int rhs);
	Cubic operator*(double rhs);
	
	//Update operators
	Cubic& operator+=(Cubic rhs);
	Cubic& operator-=(Cubic rhs);
	
	//Relational operators
	bool operator==(Cubic rhs);
	bool operator!=(Cubic rhs);

	

private:
	int a;
	int b;
	int c;
	int d;
};

istream& operator>>(istream& inStream, Cubic& cubic);
ostream& operator<<(ostream& outStream, const Cubic& cubic);

