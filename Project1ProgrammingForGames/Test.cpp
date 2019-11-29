#include "Cubic.h"
#include "Polynomial.h"
using namespace std;

int main() {
	//Cubic Test
	cout << "<------------------ Cubic Tests ------------------>" << endl;
	
	Cubic cubicOne = Cubic(3, 5, 6, 2);
	Cubic cubicTwo = Cubic(2, 7, 2, 5);
	Cubic cubicThree = Cubic(2, 7, 2, 5);

	cout << endl << "---List of Cubic---" << endl;
	cout << "cubicOne: " << cubicOne << endl;
	cout << "cubicTwo: " << cubicTwo << endl;
	cout << "cubicThree: " << cubicThree << endl;

	cout << endl << "---Arithmetic operator tests---" << endl;
	cout << "cubicOne + cubicTwo: ";
	cubicOne = cubicOne + cubicTwo;
	cout << cubicOne << endl;
	
	cout << "cubicOne - cubicTwo: ";
	cubicOne = cubicOne - cubicTwo;
	cout << cubicOne << endl;

	cout << "cubicOne * 3: ";
	cubicOne = cubicOne * 3;
	cout << cubicOne << endl;

	cout << "cubicOne * 2.0: ";
	cubicOne = cubicOne * 2.0;
	cout << cubicOne << endl;

	cout << endl << "---Calculation tests---" << endl;
	cout << "Returned coeffecient of x^2: ";
	cout << cubicOne.retCoeff(2) << endl;

	cout << "Value of cubic with an x=4";
	cout << cubicOne.calculateCubic(4) << endl;

	cout << endl << "---Relational operator tests---" << endl;
	if (cubicOne == cubicTwo) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (cubicThree == cubicTwo) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	
	if (cubicOne != cubicTwo) {
		cout << "false" << endl;
	}
	else {
		cout << "true" << endl;
	}
	if (cubicThree != cubicTwo) {
		cout << "false" << endl;
	}
	else {
		cout << "true" << endl;
	}

	cout << endl << "---Update operator tests---" << endl;
	cout << "cubicOne += cubicTwo: ";
	cubicOne += cubicTwo;
	cout << cubicOne << endl;

	cout << "cubicTwo -= cubicThree: ";
	cubicTwo -= cubicThree;
	cout << cubicTwo << endl;

	//Polynomial Test
	cout << "\n<------------------ Polynomial Tests ------------------>" << endl << endl;
	//polynomial size 5
	int s = 5;
	int t = 3;
	double coeffs[]	= { 5, 4, 3, 2, 1 };
	double coeffsTwo[] = { 6, 7, 8, 9, 10 };
	double coeffsThree[] = { 10, 8, 6, 4, 2 };
	double coeffsFour[]	= { -2, -12, 4, 6, -5 };
	double coeffsFive[] = { 3, 2, 4 };
	double coeffsSix[] = { 1, 5, 2 };

	Polynomial polyOne = Polynomial(s, coeffs);
	Polynomial polyTwo = Polynomial(s, coeffsTwo);
	Polynomial polyThree = Polynomial(s, coeffsThree);
	Polynomial polyFour = Polynomial(s, coeffsFour);
	Polynomial polyOneTwo = Polynomial(s, coeffs);
	Polynomial polyFive = Polynomial(t, coeffsFive);
	Polynomial polySix = Polynomial(t, coeffsSix);

	cout << "---List of polynomials---" << endl;
	cout << "polyOne: " << polyOne << endl;
	cout << "polyTwo: " << polyTwo << endl;
	cout << "polyThree: " << polyThree << endl;
	cout << "polyFour: " << polyFour << endl;
	cout << "polyOneTwo: " << polyOneTwo << endl;
	cout << "polyFive: " << polyFive << endl;
	cout << "polySix: " << polySix << endl << endl;

	cout << "---Comparator tests---" << endl;
	cout << "Does polyOne == polyOneTwo? ";
	if (polyOne == polyOneTwo) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cout << "Does polyOne == polyFour? ";
	if (polyOne == polyFour) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cout << "Does polyOne != polyOneTwo? ";
	if (polyOne != polyOneTwo) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cout << "Does polyOne != polyThree? ";
	if (polyOne != polyThree) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cout << endl << "---Update operator tests---" << endl;
	cout << "Value of polyOne += polyTwo: ";
	polyOne += polyTwo;
	cout << polyOne << endl;

	cout << "Value of polyOne -= polyTwo: ";
	polyOne -= polyTwo;
	cout << polyOne << endl;

	//cout << "Value of polyOne *= polyFour: ";
	//polyOne *= polyFour;
	//cout << polyOne << endl;


	cout << endl << "---Arithmetic operator tests---" << endl;
	cout << "polyOne + polyTwo: ";
	polyOne = polyOne + polyTwo;
	cout << polyOne << endl;
	cout << "polyOne * 4: ";
	polyOne = polyOne * 4;
	cout << polyOne << endl;

	cout << "polyOne - polyTwo: ";
	polyOne = polyOne - polyTwo;
	cout << polyOne << endl;

	cout << "polyFour + polyThree: ";
	polyFour = polyFour - polyThree;
	cout << polyFour << endl;

	cout << "polyFive * polySix: ";
	polyFive = polyFive * polySix;
	cout << polyFive << endl;

	cout << endl << "---Return value tests---" << endl;
	cout << "polySix: " << polySix << endl;
	cout << "Coefficient of power 2 in polySix: ";
	cout << polySix.returnCoeff(2) << endl;

	cout << "polyThree: " << polyThree << endl;
	cout << "Value of polyThree with an X value of 2: ";
	cout << polyThree.calculateValue(2.0) << endl;

	cout << endl << "---Assignment operator test---" << endl;
	cout << "polyOne: " << polyOne << endl;
	cout << "polyTwo: " << polyTwo << endl;
	polyOne = polyTwo;
	cout << "polyOne should equal polyTwo: " << polyOne << endl;
	polyOne = polyOne;
	cout << "polyOne should equal polyOne: " << polyOne << endl;

	cout << endl << "---Copy constructor test---" << endl;
	cout << "polyOne: " << polyOne << endl;
	Polynomial polySeven = polyOne;
	cout << "polySeven should equal polyOne: " << polySeven << endl;
};