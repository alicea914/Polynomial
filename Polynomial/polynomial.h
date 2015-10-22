//-----------------------------------------------------------------------------
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <climits>
#include <vector>

/**
 * CSS 342: Mathematics & Computing
 * Polynomial.h
 * Class:	Polynomial
 * Description:	Represents a polynomial function in mathematics.
 *		The array index is the power, and the value is the constant.
 *		This class allows the user to add, subtract, multiply, and
 * 		divide polynomials using an arbitrary  *driver.
 * 
 * @author Alvaro Licea, Jr.
 * @version 10/8/2015
 */
class Polynomial
{
  friend std::ostream& operator<<(std::ostream&, const Polynomial&);
  friend std::istream& operator>>(std::istream&, Polynomial&);

public:

  static const int DEFAULT_LENGTH = 1;
  static const int DEFAULT_EXPONENT_SIZE = 0;
  static const int DEFAULT_VALUE = 0;

  
  int highest_degree() const;
  bool is_zero() const;  
  int length() const;
  bool set_poly(const std::vector<int>);

  Polynomial();
  ~Polynomial();

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
  int* poly;
  int degree;
  int arr_length;
  bool zero; 
  int* get_poly_arr() const;
  int poly_size_from_vector(const std::vector<int>) const;
};
#endif // !POLYNOMIAL_H
//-----------------------------------------------------------------------------
