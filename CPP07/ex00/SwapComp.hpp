/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwapComp.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:31 by miturk            #+#    #+#             */
/*   Updated: 2024/11/18 13:56:57 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SWAPCOMP_HPP
#define SWAPCOMP_HPP

#include <iomanip>
#include <iostream>
#include <sstream>

template <typename MAX>
MAX max(MAX a, MAX b) {
	if (a > b) {
		return (a);
	}
	return (b);
}
template <typename MIN>
MIN min(MIN a, MIN b) {
	if (a > b || a == b) {
		return (b);
	}
	return (a);
	
}

template <typename SWAP>
void swap(SWAP &a, SWAP &b) {
	SWAP tmp;
	tmp = a;
	a = b;
	b = tmp;
}

class SwapComp {
	private:
		SwapComp();
		SwapComp(const SwapComp &copy);
		SwapComp &operator=(const SwapComp &copy);
		~SwapComp();
	public:
};

#endif