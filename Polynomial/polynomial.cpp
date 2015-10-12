#include "polynomial.h"

Polynomial::Polynomial() {
	poly = new int[DEFAULT_LENGTH];
	degree = DEFAULT_EXPONENT_SIZE;
	arr_length = DEFAULT_LENGTH;
	poly[0] = DEFAULT_VALUE;
}

Polynomial::~Polynomial() {
	if(poly != nullptr)
		delete[] poly;
}

int Polynomial::highest_degree() const {
	return degree;
}

int Polynomial::length() const {
	return arr_length;
}