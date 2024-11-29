/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:22:07 by miturk            #+#    #+#             */
/*   Updated: 2024/10/23 11:18:42 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_value = num << _fractionalBits;
}

Fixed::Fixed(const float par) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(par * (1 << _fractionalBits));
};

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	_value = fixed.getRawBits();
	return *this;
};

int Fixed::getRawBits(void) const {
	return (_value);	
};

void Fixed::setRawBits(int const raw) {
	_value = raw;
};

float Fixed::toFloat(void) const {
	float f = (float)(_value) / (1 << _fractionalBits);
	return f;
};

int Fixed::toInt(void) const {
	int i = _value >> _fractionalBits;
	return i;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
};