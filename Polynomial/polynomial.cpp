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
  std::cout << "heeheehooho" << is_zero() ;
  if(this != NULL && poly != NULL)
    delete[] poly;
}

Polynomial::Polynomial(int c, int e) {
  degree = e;
  arr_length = degree + 1;
  poly = new int[arr_length];

  for(int i = 0; i < arr_length; i++) {
    poly[i] = DEFAULT_VALUE;
  }
  poly[e] = c;
}

bool Polynomial::is_zero() const {
  return zero;
}

void Polynomial::set_zero(const bool z) {
  zero = z;
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

bool Polynomial::set_poly(const std::vector<int> data) {
  /**
    * Display contents of data
   */

   for(std::vector<int>::const_iterator i = data.begin(); i != data.end(); ++i)
     std::cout << *i << " ";

  std::cout << "\n";
  //*/
  if(data.empty()) {
    std::cout << "Container is empty: nothing to set\n";
    return true;
  }

  int temp_size = -1;

  if((temp_size = poly_size_from_vector(data)) == -1) {
    return false;
  }

  this->degree = temp_size;
  this->arr_length = temp_size + 1;

  if(poly != NULL) {
    delete[] poly;
  }

  poly = new int[arr_length];
  for(int i = 0; i < arr_length; i++) {
    poly[i] = 0;
  }
  int temp_const, temp_exp, i = 0;

  while(i < data.size() ) {
    temp_const = data[i];
    temp_exp = data[i+1];
    poly[temp_exp] = temp_const;
    i+=2;
  }

  set_zero(false);
  return true;
}

int Polynomial::poly_size_from_vector(std::vector<int> v)  const {
  if(v.size() < 2) {
    return 0;
  }
  int largest = INT_MIN;

  // data from user input: <const> <expo> <const> <expo> ...
  // start at first exponent element and check every exponent
  // assign largest exponent to return variable
  for(int i = 0; i < v.size(); i+=2) {
    if(v[i+1] > largest)
      largest = v[i+1];
  }

  if(largest == INT_MIN)
    largest = 0;

  return largest;
}


std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
  if(poly.get_poly_arr() == NULL) {
    return (os << "ERROR: Polynomial array is NULL\n");
  }
  if(poly.is_zero()) {
    return (os << "0");
  }
  return (os << poly.print());
}

std::string Polynomial::print() const {
  // set up stream to hold formatted output
  std::stringstream retVal;

  // if the polynomial is zero, we're done
  if(is_zero()) {
    retVal << "0";
    return retVal.str();
  }

  // format largest degree first
  int biggest = highest_degree();
  retVal << poly[biggest] << "x^" << biggest << " ";

  // loop from end of poly to beginning and format to Cx^n
  // where C is the constant, and n is the exponent from poly
  for (int d = degree - 1; d >= 0; d--) {
    if (d == 0) {
      if (poly[d] > 0)
        retVal << "+ " << poly[d] << " ";
      else if (poly[d] < 0)
        retVal << poly[d] << " ";
      else
        continue;
    }
    // mathematicians dislike seeing 1 * varable
    if (d == 1) {
      if (poly[d] == 1)
        retVal << "+ x ";
      else if (poly[d] > 1)
        retVal << "+ " << poly[d] << "x ";
      else if (poly[d] < 0)
        retVal << poly[d] << "x ";
      else
        continue;
    }

    else if (poly[d] == 1) {
      retVal << "+ x^" << d << " ";
    }

    else if (poly[d] > 1) {
      retVal << "+ " << poly[d] << "x^" << d << " ";
    }
    // 1 * variable hack here, too
    else if (poly[d] < 0) {
      if(d != 1)
        retVal << poly[d] << "x^" << d << " ";
    }
  }

return retVal.str();
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
  poly.set_zero(false);
  return is;
}
//-----------------------------------------------------------------------------
