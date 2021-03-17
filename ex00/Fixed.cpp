/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:35:29 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/17 16:33:38 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void) : i(0)
{
}

Fixed::Fixed(const Fixed &fixed)
{
	(void)fixed;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(const Fixed &op)
{
	Fixed::setRawBits(op.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (Fixed::i);
}

void Fixed::setRawBits(const int raw)
{
	Fixed::i = raw;
}
