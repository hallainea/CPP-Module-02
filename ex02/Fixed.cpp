/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:17:05 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/21 19:08:43 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : i(0)
{
}

Fixed::Fixed(const int i) : i(i << Fixed::bits)
{
}

Fixed::Fixed(const float f) : i(roundf(f * (1 << Fixed::bits)))
{
}

Fixed::Fixed(const Fixed &fixed)
{
	Fixed::operator=(fixed);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
	return (Fixed::i);
}

void Fixed::setRawBits(const int raw)
{
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

Fixed &Fixed::operator=(const Fixed &op)
{
	Fixed::setRawBits(op.getRawBits());
	return (*this);
}

Fixed Fixed::operator+(const Fixed &op) const
{
	return (Fixed(this->toInt() + op.toInt()));
}

Fixed Fixed::operator-(const Fixed &op) const
{
	return (Fixed(this->toInt() - op.toInt()));
}

Fixed Fixed::operator*(const Fixed &op) const
{
	Fixed ret;
	ret.setRawBits((this->getRawBits() * op.getRawBits()) >> this->bits);
	return (ret);
}

Fixed Fixed::operator/(const Fixed &op) const
{
	Fixed ret;
	ret.setRawBits((this->getRawBits() << this->bits) / op.getRawBits());
	return (ret);
}

Fixed &Fixed::operator++(void)
{
	Fixed::i++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	Fixed::operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	Fixed::i--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	Fixed::operator--();
	return (tmp);
}

bool Fixed::operator>(Fixed const &op) const
{
	return (this->getRawBits() > op.getRawBits());
}

bool Fixed::operator<(Fixed const &op) const
{
	return (this->getRawBits() < op.getRawBits());
}

bool Fixed::operator>=(Fixed const &op) const
{
	return (this->getRawBits() >= op.getRawBits());
}

bool Fixed::operator<=(Fixed const &op) const
{
	return (this->getRawBits() <= op.getRawBits());
}

bool Fixed::operator==(Fixed const &op) const
{
	return (this->getRawBits() == op.getRawBits());
}

bool Fixed::operator!=(Fixed const &op) const
{
	return (this->getRawBits() != op.getRawBits());
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}
