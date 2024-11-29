/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:22:07 by miturk            #+#    #+#             */
/*   Updated: 2024/10/23 12:37:21 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float par){
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(par *(1 << _fractionalBits));
}

Fixed::Fixed(const int num) {
	// std::cout << "Int constructor called" << std::endl;
	_value = num << _fractionalBits;
}
Fixed::Fixed(const Fixed &fixed) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	// std::cout << "Copy assignment operator called" << std::endl;
	_value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return (_value);	
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat(void) const {
	float f = static_cast<float>(_value) / (1 << _fractionalBits);
	return f;
}

int Fixed::toInt(void) const {
	int i = _value >> _fractionalBits;
	return i;
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed res;
	res.setRawBits(this->_value + fixed.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed res;
	res.setRawBits(this->_value - fixed.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed res;
	res.setRawBits((this->_value * fixed.getRawBits()) >> _fractionalBits);
	return res;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed res;
	res.setRawBits((this->_value << _fractionalBits) / fixed.getRawBits());
	return res;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_value++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_value--;
    return temp;
}

Fixed &Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed &Fixed::operator--(void) {
	this->_value--;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
	bool res = (this->_value > fixed.getRawBits()) ? true : false;
	return res;
}

bool Fixed::operator<(const Fixed &fixed) const {
	bool res = (this->_value < fixed.getRawBits()) ? true : false;
	return res;
}

bool Fixed::operator>=(const Fixed &fixed) const {
	bool res = (this->_value >= fixed.getRawBits()) ? true : false;
	return res;
}

bool Fixed::operator<=(const Fixed &fixed) const {
	bool res = (this->_value <= fixed.getRawBits()) ? true : false;
	return res;
}

bool Fixed::operator==(const Fixed &fixed) const {
	bool res = (this->_value == fixed.getRawBits()) ? true : false;
	return res;
}

bool Fixed::operator!=(const Fixed &fixed) const {
	bool res = (this->_value != fixed.getRawBits()) ? true : false;
	return res;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a > b) ? b : a;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	return (a > b) ? b : a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}