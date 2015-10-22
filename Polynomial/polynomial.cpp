//-----------------------------------------------------------------------------
#include "polynomial.h"

Polynomial::Polynomial() {
  poly = new int[DEFAULT_LENGTH];
  degree = DEFAULT_EXPONENT_SIZE;
  arr_length = DEFAULT_LENGTH;
  poly[0] = DEFAULT_VALUE;
  zero = true;
}

Polynomial::~Polynomial() {
  if(poly != NULL)
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

bool Polynomial::set_poly(std::vector<int> container) {
  return false;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
  // ERROR if NULL, otherwise display 0 if polynomial is zero
  if(poly.get_poly_arr() == NULL) {
    return (os << "ERROR: Polynomial array is NULL\n");		
  } else {
    if(poly.is_zero()) {
      return (os << "0");
    }
    
    // initialize pointer and format output
    int* current = poly.get_poly_arr();
    int highest_degree = poly.highest_degree();
    os << current[highest_degree] << "x^" << highest_degree;
		
    // loop from end of poly to beginning, and format output	
    for (int degree = poly.highest_degree()- 1; degree >= 0; degree--) {
      if (current[degree] == 0) {
        continue;
      } else if (current[highest_degree] == 1) {
        os << "x^" << degree << " ";
      } else if(current[degree] > 1) {
        os << "+" << current[degree] << "x^" << degree << " ";
      } else if (current[degree] < 0) {
        os << current[degree] << "x^" << degree << " ";
      } else {
        os << "x^" << degree << " ";
      }
    }
  }

  return os;
}

std::istream& operator>>(std::istream& is, Polynomial& poly) {
   std::cout << "Please enter input like below:\n";
  std::cout << "<const> <exp> (0 0 to quit)\n";
  std::cout << "<const> <exp> (0 0 to quit)\n";
  std::cout << "\t...\n";

  std::vector<int> container;
  int constant = 0;
  int exponent = 0;
  
  // used to get the loops started
  is >> constant >> exponent;

  // keep running until 0 0 is entered;
  while(true) {

    // if the input is erroneous, ask for more input
    while((! is >> constant) || (! is >> exponent)) {
      is.clear();
      is.ignore(100, '\n');
      std::cout << "ERROR: Enter paired values like below:\n";
      std::cout << "<const> <exp> (0 0 to quit)\n";
      is >> constant >> exponent;
    }

    // stop if input is 0 0, otherwise add to vector, and read in again
    if(constant == 0 && exponent == 0)
      break;  
    else {
      container.push_back(constant);
      container.push_back(exponent);
    }

    // read again
    is >> constant >> exponent;           
  }
  
  // 0 0 is entered, set up the polynomial
  poly.set_poly(container);
  return is;
}
//-----------------------------------------------------------------------------
