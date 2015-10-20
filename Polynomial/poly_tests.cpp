//-----------------------------------------------------------------------------
#include "polynomial.h"

int main() 
{
  //Test objects. 
  Polynomial* polynomial_array = new Polynomial[20];
  Polynomial a;

  std::cout << "~*~*~*~*__Polynomial Tests__*~*~*~*~\n";
  std::cout << "Written by Alvaro Licea, Jr.\n";

  // First test the Constructor and overloaded output operator
  std::cout << "\nTesting the constructor, and cout operator...\n";
  std::cout << "---------------------------------------";
  std::cout << "----------------------------------------\n";
  std::cout << "This is a Poly:\t\t\t" << a << "\n";

  // Then test the accessors
  std::cout << "\nTesting the degree, length, and is_zero accessors...\n";
  std::cout << "---------------------------------------";
  std::cout << "----------------------------------------\n";
  std::cout << "The highest degree of this polynomial is:\t"
            << a.highest_degree() << "\n";
  std::cout << "The length of the polynomial array is:\t\t" 
            << a.length() << "\n";
  std::cout << "Is this polynomial a zero polynomial?\t\t" 
            << a.is_zero() << "\n";
}
//-----------------------------------------------------------------------------
