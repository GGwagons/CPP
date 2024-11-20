/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:54:49 by miturk            #+#    #+#             */
/*   Updated: 2024/11/20 14:51:12 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SwapComp.hpp"

int main( void ) {
	std::cout << "With int:" << std::endl;
	int i1 = 2;
	int i2 = 3;
	::swap( i1, i2 );
	std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
	std::cout << "min( i1, i2 ) = " << ::min( i1, i2 ) << std::endl;
	std::cout << "max( i1, i2 ) = " << ::max( i1, i2 ) << std::endl;
	std::cout << std::endl;
	
	std::cout << "With double:" << std::endl;
	double d1 = 5.2;
	double d2 = 6.3;
	::swap( d1, d2 );
	std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
	std::cout << "min( d1, d2 ) = " << ::min( d1, d2 ) << std::endl;
	std::cout << "max( d1, d2 ) = " << ::max( d1, d2 ) << std::endl;
	std::cout << std::endl;

	std::cout << "With float:" << std::endl;
	float f1 = 2.2f;
	float f2 = 3.3f;
	::swap( f1, f2 );
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min( f1, f2 ) = " << ::min( f1, f2 ) << std::endl;
	std::cout << "max( f1, f2 ) = " << ::max( f1, f2 ) << std::endl;
	std::cout << std::endl;
	
	std::cout << "With char:" << std::endl;
	char c1 = 'A';
	char c2 = 'B';
	::swap( c1, c2 );
	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << "min( c1, c2 ) = " << ::min( c1, c2 ) << std::endl;
	std::cout << "max( c1, c2 ) = " << ::max( c1, c2 ) << std::endl;
	std::cout << std::endl;
	
	std::cout << "With string:" << std::endl;
	std::string s1 = "chaine1";
	std::string s2 = "chaine2";
	::swap(s1, s2);
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << "min( s1, s2 ) = " << ::min( s1, s2 ) << std::endl;
	std::cout << "max( s1, s2 ) = " << ::max( s1, s2 ) << std::endl;
	std::cout << std::endl;
	return 0;
}
