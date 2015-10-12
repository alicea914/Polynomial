#ifndef	POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <stdio.h>

class Polynomial {
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend std::istream& operator>>(std::istream&, const Polynomial&);
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

	Polynomial operator+=(const Polynomial&);
	Polynomial operator-=(const Polynomial&);
	Polynomial operator*=(const Polynomial&);
	Polynomial operator/=(const Polynomial&);

	bool operator==(const Polynomial&) const;
	bool operator!=(const Polynomial&) const;

protected: 
	int* poly;
	int degree;
	int arr_length;
};

#endif