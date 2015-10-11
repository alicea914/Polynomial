#ifndef	POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
public:
	static const int DEFAULT_SIZE = 1;
	static const int DEFAULT_VALUE = 1;

	Polynomial();
	~Polynomial();

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
	int size;
};

#endif