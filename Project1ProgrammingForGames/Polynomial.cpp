#include "Polynomial.h"

Polynomial::Polynomial()
{
	poly = new double[0];
	size = 0;
}

Polynomial::Polynomial(int power)
{
	poly = new double[power];
	size = power;
}

Polynomial::Polynomial(int power, double coeffs[])
{
	poly = new double[power];
	size = power;

	for (int i = 0; i < size; ++i) {
		poly[i] = coeffs[i];
	}
}

Polynomial::~Polynomial()
{
	if (size) {
		delete[] poly;
	}
}

Polynomial::Polynomial(const Polynomial& copy)
{
	//this->copy(copy);
	size = copy.getSize();
	poly = new double[size];

	for (int i = 0; i < size; ++i) {
		poly[i] = copy.poly[i];
	}
}


int Polynomial::getSize() const
{
	return size;
}

double Polynomial::returnCoeff(int p)
{
	if (p < size) {
		return poly[p];
	}
}

double Polynomial::calculateValue(double x)
{
	int result = 0;

	result += poly[0];

	for (int i = 1; i < size; ++i) {
		result += (poly[i] * (pow(x, i)));
	}

	return result;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	delete[] this->poly;
	
	//this->copy(rhs);

	size = rhs.getSize();
	poly = new double[size];

	for (int i = 0; i < size; ++i) {
		poly[i] = rhs.poly[i];
	}
	
	return *this;
}

Polynomial Polynomial::operator+(Polynomial rhs)
{
	if (size >= rhs.getSize()) {
		double* arr = new double[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = poly[i];
		}
		for (int j = 0; j < rhs.getSize(); ++j) {
			arr[j] = arr[j] + rhs.poly[j];
		}
		Polynomial polyNew = Polynomial(size, arr);
		delete[] arr;
		return polyNew;
	}
	else if (rhs.getSize() > size) {
		double* arr = new double[rhs.getSize()];
		for (int i = 0; i < rhs.getSize(); ++i) {
			arr[i] = rhs.poly[i];
		}
		for (int j = 0; j < size; ++j) {
			arr[j] = arr[j] + poly[j];
		}
		Polynomial polyNew = Polynomial(size, arr);
		delete[] arr;
		return polyNew;;
	}
}

Polynomial Polynomial::operator-(Polynomial rhs)
{
	if (size >= rhs.getSize()) {
		double* arr = new double[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = poly[i];
		}
		for (int j = 0; j < rhs.getSize(); ++j) {
			arr[j] = arr[j] - rhs.poly[j];
		}
		Polynomial polyNew = Polynomial(size, arr);
		delete[] arr;
		return polyNew;
	}
	else if (rhs.getSize() > size) {
		double* arr = new double[rhs.getSize()];
		for (int i = 0; i < rhs.getSize(); ++i) {
			arr[i] = rhs.poly[i];
		}
		for (int j = 0; j < size; ++j) {
			arr[j] = arr[j] - poly[j];
		}
		Polynomial polyNew = Polynomial(size, arr);
		delete[] arr;
		return polyNew;
	}
}

Polynomial Polynomial::operator*(double rhs)
{
	double* arr = new double[size];

	for (int i = 0; i < size; ++i) {
		arr[i] = poly[i] * rhs;
	}
	
	Polynomial polyNew = Polynomial(size, arr);
	delete[] arr;
	return polyNew;
}

Polynomial Polynomial::operator*(Polynomial rhs)
{
	int newSize = size + rhs.getSize() - 1;
	double* arr = new double[newSize];
	for (int i = 0; i < newSize; ++i) {
		arr[i] = 0;
	}

	for (int j = 0; j < size; ++j) {
		for (int k = 0; k < rhs.getSize(); ++k) {
			arr[j + k] += poly[j] * rhs.poly[k];
		}
	}
	
	Polynomial polyNew = Polynomial(size, arr);
	delete[] arr;
	return polyNew;
}

Polynomial& Polynomial::operator+=(Polynomial rhs)
{
	if (size >= rhs.getSize()) {
		for (int j = 0; j < rhs.getSize(); ++j) {
			poly[j] = poly[j] + rhs.poly[j];
		}
		return *this;
	}
	else if (rhs.getSize() > size) {
		for (int j = 0; j < size; ++j) {
			rhs.poly[j] = rhs.poly[j] + poly[j];
		}
		return *this;
	}
}

Polynomial& Polynomial::operator-=(Polynomial rhs)
{
	if (size >= rhs.getSize()) {
		for (int j = 0; j < rhs.getSize(); ++j) {
			poly[j] = poly[j] - rhs.poly[j];
		}
		return *this;
	}
	else if (rhs.getSize() > size) {
		for (int j = 0; j < size; ++j) {
			rhs.poly[j] = rhs.poly[j] - poly[j];
		}
		return *this;
	}
}

Polynomial& Polynomial::operator*=(Polynomial rhs)
{
	int newSize = (size + (rhs.getSize() - 1));
	double* arr = new double[newSize];
	for (int i = 0; i < newSize; ++i) {
		arr[i] = 0;
	}

	for (int j = 0; j < size; ++j) {
		for (int k = 0; k < rhs.getSize(); ++k) {
			arr[j + k] += (poly[j] * rhs.poly[k]);
		}
	}

	delete[] this->poly;

	Polynomial polyNew = Polynomial(newSize, arr);
	this->size = polyNew.getSize();
	this->poly = polyNew.poly;

	delete[] arr;

	return *this;
}

bool Polynomial::operator==(Polynomial rhs)
{
	if (size != rhs.getSize()) {
		return false;
	}
	else {
		for (int i = 0; i < size; ++i) {
			if (poly[i] != rhs.poly[i]) {
				return false;
			}
		}
		return true;
	}
}

bool Polynomial::operator!=(Polynomial rhs)
{
	int temp = 0;
	for (int i = 0; i < size; ++i) {
		if (poly[i] != rhs.poly[i]) {
			++temp;
		}
	}
	if (temp > 0) {
		return true;
	}
	else {
		return false;
	}
}

/*void Polynomial::copy(const Polynomial& copy)
{
	size = copy.getSize();
	poly = new double[size];

	for (int i = 0; i < size; ++i) {
		poly[i] = copy.poly[i];
	}
}*/

istream& operator>>(istream& inStream, Polynomial& polynomial)
{
	int size = 0;
	int coeff = 0;
	
	cout << "What is the highest power of your polynomial?" << endl;
	inStream >> size;

	double* arr = new double[size-1];
	
	for (int i = 0; i < size-1; ++i) {
		cout << "Enter the coefficient of x^" << i << endl;
		inStream >> coeff;
		arr[i] = coeff;
		coeff = 0;
	}

	polynomial = Polynomial(size - 1, arr);

	return inStream;
}


ostream& operator<<(ostream& outStream, const Polynomial& polynomial)
{
	const string xPower = "x^";
	const string plus = " + ";
	const string minus = " - ";
	// TODO: insert return statement here
	for (int i = polynomial.getSize() - 1; i > -1; --i) {
		if (i == 0) {
			if (polynomial.poly[i] < 0) {
				outStream << " " << polynomial.poly[i];
			}
			else {
				outStream << plus << polynomial.poly[i];
			}
		}
		else if (i == polynomial.getSize() - 1) {
			if (polynomial.poly[i] < 0) {
				outStream << polynomial.poly[i] << xPower << i;
			}
			else {
				outStream << polynomial.poly[i] << xPower << i;
			}
		}
		else if(polynomial.poly[i] > -1) {
			outStream << plus << polynomial.poly[i] << xPower << i;
		}
		else if (polynomial.poly[i] < 0) {
			outStream << " " << polynomial.poly[i] << xPower << i;
		}
	}

	return outStream;
}
