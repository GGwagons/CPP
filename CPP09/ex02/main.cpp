/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:23:44 by miturk            #+#    #+#             */
/*   Updated: 2024/12/09 21:24:19 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// JUST FIND A BETTER WAY TO DO THIS

template <typename T, typename A>
void setStorage(T &pm, A **argv) {
	std::string str;
	for (int i = 1; argv[i]; i++) {
		str = argv[i];
		pm.storage(str);
	}
}

template <typename T>
void theLoop(T pm, d &values) {
	PmergeMe *pm = new PmergeMe();
	setStorage(pm, argv);
	values = pm.getValues();
	pm.comboStore(values);
	vd combo = pm.getCombo();
	d d1 = pm.compare(combo);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [value] [value] ... [valueN]" << std::endl;
		return 1;
	}
	try {
		PmergeMe pm;
		v values;
		setStorage(pm, argv); //Da hell is this? Fix it!
		values = pm.getValues();
		pm.checkDouble();
		pm.comboStore(values);

		vd combo = pm.getCombo();
		comboPrint(combo);
		d d1 = pm.compare(combo);
		while (d1.size() != 1) {
			theLoop(pm, d1);
		}
		printContainer(d1);
		vd combo2;
		combo2 = pm.getCombo();
		comboPrint(combo2);
		std::cout << pm.getCompare() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}