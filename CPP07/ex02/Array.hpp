/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:06:56 by miturk            #+#    #+#             */
/*   Updated: 2024/11/20 16:40:15 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <stdexcept>

template <typename T>
class Array {
	private:
		T *data;
		int  _size;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		~Array();
		T &operator[](int index);
		const T &operator[](int index) const;
		size_t arr_size() const;
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Out of bounds";
				}
		};
};

template <typename T>
Array<T>::Array() : data(NULL), _size(0) {
	// std::cout << "Default array created" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int size) : data(NULL) {
	// std::cout << "Array created" << std::endl;
	_size = size;
	if (_size > 0) {
		data = new T[_size]();
	}
	else {
		data = NULL;
	}
}

template <typename T>
Array<T>::Array(const Array &copy) : data(NULL), _size(copy._size) {
	// std::cout << "Array copied" << std::endl;
	if (_size > 0) {
		data = new T[_size]();
		for (int i = 0; i < _size; i++) {
			data[i] = copy.data[i];
		}
	}
	else {
		data = NULL;
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy) {
	// std::cout << "Array assigned" << std::endl;
	if (this != &copy) {
		delete[] data;
		_size = copy._size;
		if (_size > 0) {
			data = new T[_size]();
			for (int i = 0; i < _size; i++) {
				data[i] = copy.data[i];
			}
		}
		else {
			data = NULL;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] data;
}

template <typename T>
T &Array<T>::operator[](int index) {
	if (index < 0) {
		throw OutOfBoundsException();
	}
	if (_size <= index) {
		throw OutOfBoundsException();
	}
	return (data[index]);
}

template <typename T>
const T &Array<T>::operator[](int index) const {
	if (index < 0) {
		throw OutOfBoundsException();
	}
	if (_size <= index) {
		throw OutOfBoundsException();
	}
	return (data[index]);
}

template <typename T>
size_t Array<T>::arr_size() const {
	// std::cout << "Array size: " << _size << std::endl;
	return _size;
}

#endif