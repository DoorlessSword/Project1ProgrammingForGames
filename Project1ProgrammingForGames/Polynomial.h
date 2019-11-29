#pragma once
#include <iostream>
using namespace std;

class Polynomial
{
public:
	Polynomial();
	Polynomial(int power); //fill parameter list with parameters
	Polynomial(int power, double coeffs[]); 
	~Polynomial();
	Polynomial(const Polynomial&);

	int getSize() const;
	double returnCoeff(int p);
	double calculateValue(double x);

	Polynomial& operator=(const Polynomial&);

	//Arithmetic operators
	Polynomial operator+(Polynomial rhs);
	Polynomial operator-(Polynomial rhs);
	Polynomial operator*(double rhs);
	Polynomial operator*(Polynomial rhs);

	//Update operators
	Polynomial& operator+=(Polynomial rhs);
	Polynomial& operator-=(Polynomial rhs);
	Polynomial& operator*=(Polynomial rhs);

	//Relational operators
	bool operator==(Polynomial rhs);
	bool operator!=(Polynomial rhs);

	friend istream& operator>>(istream& inStream, Polynomial& cubic);
	friend ostream& operator<<(ostream& outStream, const Polynomial& cubic);

private:
	double* poly;
	int size;

	//void copy(const Polynomial& copy);
};



