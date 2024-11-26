/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:28:43 by wagons            #+#    #+#             */
/*   Updated: 2024/11/26 16:24:07 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	std::cout << "Add to Top: " << mstack.top() << std::endl;
	mstack.push(17);
	std::cout << "Add to Top: " << mstack.top() << std::endl;
	std::cout << "Before Pop->Top Value: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "After Pop->Top Value: " << mstack.top() << std::endl;
	std::cout << "Size Of Stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "Begining of Stack: " << *mstack.begin() << std::endl;
	std::cout << "Test ++i: " << *++it << std::endl;
	std::cout << "Test --i: " << *--it << std::endl;
	std::cout << "---The Stack Values---" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "---End---" << std::endl;
	std::stack<int> s(mstack);
	MutantStack<int>::iterator s_it = mstack.begin();
	MutantStack<int>::iterator s_ite = mstack.end();
	while (s_it != s_ite) {
		std::cout << *s_it << std::endl;
		++s_it;
	}

	std::cout << "-----STD::LIST<INT>-----" << std::endl;
	std::list<int> mstack1;
	mstack1.push_back(5);
	std::cout << "Add to Top: " << mstack1.back() << std::endl;
	mstack1.push_back(17);
	std::cout << "Add to Top: " << mstack1.back() << std::endl;
	std::cout << "Before Pop->BACK Value: " << mstack1.back() << std::endl;
	mstack1.pop_back();
	std::cout << "After Pop->BACK Value: " << mstack1.back() << std::endl;
	std::cout << "Size Of Stack: " << mstack1.size() << std::endl;
	mstack1.push_back(3);
	mstack1.push_back(5);
	mstack1.push_back(737);
	mstack1.push_back(0);
	std::list<int>::iterator it1 = mstack1.begin();
	std::list<int>::iterator ite1 = mstack1.end();
	std::cout << "Begining of Stack: " << *mstack1.begin() << std::endl;
	std::cout << "Test ++i: " << *++it1 << std::endl;
	std::cout << "Test --i: " << *--it1 << std::endl;
	std::cout << "---The Stack Values---" << std::endl;
	while (it1 != ite1) {
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::cout << "---End---" << std::endl;
	std::list<int> s1(mstack1);
	std::list<int>::iterator s_it1 = mstack1.begin();
	std::list<int>::iterator s_ite1 = mstack1.end();
	while (s_it1 != s_ite1) {
		std::cout << *s_it1 << std::endl;
		++s_it1;
	}
	return 0;
}
