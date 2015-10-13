#include "polynomial.h"

int main() 
{
	std::cout << "Polynomial Tests";

	// First test the C'tor and overloaded output operator
	Polynomial a;
	std::cout << a << "/n";

	// Then test the accessors
	std::cout << "The highest degree of this polynomial is: " << a.highest_degree() << "\n";
	std:: cout << "The length of the array is " << a.length() << "\n";
}