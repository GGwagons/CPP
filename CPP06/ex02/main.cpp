/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:13:44 by miturk            #+#    #+#             */
/*   Updated: 2024/11/14 17:38:37 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	srand(time(0));
	int random = rand() % 3;
	switch (random) {
		case 0 :
			return new A;
		case 1 :
			return new B;	
		case 2 :
			return new C;
		default :
			return (NULL);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "It's pointer A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "It's pointer B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "It's pointer C" << std::endl;
	else
		std::cout << "Dynamic cast pointer failed" << std::endl;
}

void identify(Base &p) {
	A refA;
	B refB;
	C refC;
	try {
		refA = dynamic_cast<A &>(p);
		std::cout << "It's reference to A" << std::endl;
	}
	catch(const std::exception &e) {};
	try{
		refB = dynamic_cast<B &>(p);
		std::cout << "It's reference to B" << std::endl;
	}
	catch(const std::exception &e) {};
	try {
		refC = dynamic_cast<C &>(p);
		std::cout << "It's reference to C" << std::endl;
	}
	catch(const std::exception &e) {};
	
}

int main() {
	Base *pointer;
	pointer = generate();
	identify(pointer);
	identify(*pointer);
	delete pointer;
	std::cout << std::endl;
	Base *p;
	for (int i =  0; i < 10; i++) {
		p = generate();
		identify(p);
		identify(*p);
		delete p;
		sleep(1);
	}
	return (0);
}