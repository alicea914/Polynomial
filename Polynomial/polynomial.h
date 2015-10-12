#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <stdio.h>

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
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
	friend std::istream& operator>>(std::istream& is, const Polynomial& poly);

public:
	static const int DEFAULT_EXPONENT_SIZE = 0;
	static const int DEFAULT_LENGTH = 1;
	static const int DEFAULT_VALUE = 0;

	Polynomial();
	~Polynomial();

	int highest_degree() const;
	int length() const;

	Polynomial operator+(const Polynomial&) const;
	Polynomial operator-(const Polynomial&) const;
	Polynomial operator*(const Polynomial&) const;
	Polynomial operator/(const Polynomial&) const;

protected: 
	int* poly;
	int degree;
	int arr_length;
};

#endif // !POLYNOMIAL_H
