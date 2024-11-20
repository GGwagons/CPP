/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:59:38 by miturk            #+#    #+#             */
/*   Updated: 2024/11/20 19:10:12 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

int main() {
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	iter( tab, 5, print<const int>);
	iter( tab2, 5, print<Awesome> );
	
	std::cout << std::endl;
	std::cout << "Int Array" << std::endl;
	int intArray[5] = {1, 2, 3, 4, 5};
	::iter(intArray, 5, print);
	std::cout << std::endl;

	std::cout << "Double Array" << std::endl;
	double doubleArray[5] = {1.0, 2.0, 3.2, 4.3, 5.4};
	::iter(doubleArray, 5, print);
	std::cout << std::endl;

	std::cout << "Float Array" << std::endl;
	float floatArray[5] = {1.3f, 2.6f, 3.12f, 4.55f, 5.56f};
	::iter(floatArray, 5, print);
	std::cout << std::endl;
	
	std::cout << "String Array 1" << std::endl;
	std::string stringArray1 = "Hello, World!";
	size_t len = stringArray1.size();
	// size does not include the null terminator at the end of the string
	::iter(stringArray1.c_str(), len, print);
	std::cout << std::endl;

	std::cout << "String Array 2" << std::endl;
	std::string stringArray2 = "Hello, World!";
	// If you set the 2nd argument to 14 it will print the null terminator at the end of the string
	::iter(stringArray2.c_str(), 13, print);
	std::cout << std::endl;

	std::cout << "String Array 3" << std::endl;
	const char stringArray3[14] = "Hello, World!";
	// If you set the 2nd argument to 14 it will print the null terminator at the end of the string
	::iter(stringArray3, 13, print);
	std::cout << std::endl;
	
	return (0);
}
