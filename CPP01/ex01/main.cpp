/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:27:05 by miturk            #+#    #+#             */
/*   Updated: 2024/10/18 14:40:27 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 10;
	Zombie *horde = zombieHorde(N, "Zombie Horde");
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde; //This is how you delete arrays in C++
	return (0);
}