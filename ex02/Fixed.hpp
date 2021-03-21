/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:18:35 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/21 19:05:23 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int i;
	const static int bits = 8;

public:
	Fixed(void);
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &fixed);
	virtual ~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);
	int toInt(void) const;
	float toFloat(void) const;

	Fixed &operator=(const Fixed &op);
	Fixed operator+(const Fixed &op) const;
	Fixed operator-(const Fixed &op) const;
	Fixed operator*(const Fixed &op) const;
	Fixed operator/(const Fixed &op) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	bool operator>(Fixed const &op) const;
	bool operator<(Fixed const &op) const;
	bool operator>=(Fixed const &op) const;
	bool operator<=(Fixed const &op) const;
	bool operator==(Fixed const &op) const;
	bool operator!=(Fixed const &op) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	const static Fixed &min(const Fixed &a, const Fixed &b);
	const static Fixed &max(const Fixed &a, const Fixed &b);
};

Fixed &min(Fixed &a, Fixed &b);
Fixed &max(Fixed &a, Fixed &b);

std::ostream &operator<<(std::ostream &out, Fixed const &value);
#endif
