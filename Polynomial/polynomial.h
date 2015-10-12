#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

/**
 * CSS 342: Mathematics in Computing
 * Polynomial.h
 * Class:	Polynomial
 * Purpose:	Data structure representing a polynomial function in mathematics.
 *			The index of the array is the power, and the value is the constant.
 *			This class allows the user to add, subtract, multiply, and divide
 *			polynomials using an arbitrary driver.
 * 
 * @author Alvaro Licea, Jr.
 * @version 10/8/2015
 */
class Polynomial
{
	friend ostream& operator<<(ostream$ os, const Polynomial& poly);
	friend istream& operator>>(istream& is, const Polynomial& poly);

public:
	int length()
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	Polynomial operator/(const Polynomial&);

	Polynomial operator+=(const Polynomial&);
	Polynomial operator-=(const Polynomial&);
	Polynomial operator*=(const Polynomial&);
	Polynomial operator/=(const Polynomial&);

	Polynomial operator==(const Polynomial&) const;
	Polynomial operator!=(const Polynomial&) const;

protected:
	int* poly_array;
	int length;
}
#endif // !POLYNOMIAL_H
