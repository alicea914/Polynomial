//-----------------------------------------------------------------------------
#include "polynomial.h"
#include <cstdlib>
#include <vector>

/**
 * CSS 342: Mathematics & Computing
 * poly_tests.cpp
 * Description: Driver for testing polynomial functionality.
 * @author Alvaro Licea, Jr.
 * @version 10/8/2015
 */

int main()
{
  //Test objects.
  int length = 5;
  std::vector<Polynomial> polys;
  Polynomial a;
  Polynomial b;

  srand(time(NULL));

  int i = 0, k = 0;
  Polynomial* temp;
  for (int a = 0; a < length - 1; a++) {
    i = rand() % 100 + 1;
    //std::cout << i << " " << k << std::endl;
    k = rand() % 100;

    temp = new Polynomial(i, k);

    //std::cout << *temp << std::endl;

    polys.push_back(*temp);

    std::cout << polys[a] << std::endl;
  }

/*
  std::cout << "~*~*~*~*__Polynomial Tests__*~*~*~*~\n";
  std::cout << "Written by Alvaro Licea, Jr.\n";

  // test the Constructor and overloaded cin operator
  std::cout << "\nTesting constructors...\n";
  std::cout << "---------------------------------------";
  std::cout << "----------------------------------------\n";
  std::cout << "This is a Poly:\t\t\t" << a << "\n";

  // test the overloaded cin operator
  std::cout << "\nTesting cin operator (input required from user)...\n";
  std::cout << "---------------------------------------";
  std::cout << "----------------------------------------\n";
  std::cin  >> b;
  std::cout << "This is b Poly:\t\t\t" << b << "\n";

  // test the accessors
  std::cout << "\nTesting accessors...\n";
  std::cout << "---------------------------------------";
  std::cout << "----------------------------------------\n";
  std::cout << "a Poly\n";
  std::cout << "The highest degree of this polynomial is:\t"
            << a.highest_degree() << "\n";
  std::cout << "The length of the polynomial array is:\t\t"
            << a.length() << "\n";
  std::cout << "Is this polynomial a zero polynomial?\t\t"
            << a.is_zero() << "\n";

  std::cout << "---------------------------------------";
  std::cout << "----------------------------------------\n";
  std::cout << "b Poly\n";
  std::cout << "The highest degree of this polynomial is:\t"
            << b.highest_degree() << "\n";
  std::cout << "The length of the polynomial array is:\t\t"
            << b.length() << "\n";
  std::cout << "Is this polynomial a zero polynomial?\t\t"
            << b.is_zero() << "\n";
*/

}
//-----------------------------------------------------------------------------
