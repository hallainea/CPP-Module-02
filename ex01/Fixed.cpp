/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:17:05 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/20 10:58:54 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : i(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : i(i << Fixed::bits)
{
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float f) : i(roundf(f * (1 << Fixed::bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=(fixed);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &op)
{
	std::cout << "Assignation operator called" << std::endl;
	Fixed::setRawBits(op.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (Fixed::i);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	Fixed::i = raw;
}

int Fixed::toInt(void) const
{
	return (Fixed::i >> Fixed::bits);
}

float Fixed::toFloat(void) const
{
	return ((float)Fixed::i / (1 << Fixed::bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}
