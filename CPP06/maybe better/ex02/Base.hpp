/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:31:09 by miturk            #+#    #+#             */
/*   Updated: 2024/11/18 12:43:09 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cassert>
//#include <unistd.h> //used for sleep to get random results from srand(time(0));

class Base {
	private:
	public:
	virtual ~Base();
};


#endif