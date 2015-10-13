#include "polynomial.h"

Polynomial::Polynomial() {
	poly = new int[DEFAULT_LENGTH];
	degree = DEFAULT_EXPONENT_SIZE;
	arr_length = DEFAULT_LENGTH;
	poly[0] = DEFAULT_VALUE;
	zero = true;
}

Polynomial::~Polynomial() {
	if(poly != nullptr)
		delete[] poly;
}

bool Polynomial::is_zero() const {
	return zero;	
}

int Polynomial::highest_degree() const {
	return degree;
}

int Polynomial::length() const {
	return arr_length;
}

int* Polynomial::get_poly_arr() const {
	return poly;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
	if(poly.get_poly_arr() == nullptr) {
		return (os << "ERROR: Polynomial array is null.\n");		
	} else {
		if(poly.is_zero()) {
			return (os << "0");
		}
		int* current = poly.get_poly_arr();
		int highest_degree = poly.highest_degree();
		os << current[highest_degree] << "x^" << highest_degree;
			
		for ( int degree = poly.highest_degree()- 1; degree >= 0; degree--) {
			if (current[degree] == 0) {
				continue;
			} else if (current[highest_degree] == 1) {
				os << "x^" << degree << " ";
			} else if(current[degree] > 1) {
				os << "+" << current[degree] << "x^" << degree << " ";			
			} else if (current[degree] < 0) {
				os << current[degree] << "x^" << degree << " ";
			}
		}
	}
	return os;
}