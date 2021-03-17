/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:16:12 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/17 16:22:12 by ahallain         ###   ########.fr       */
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
	Fixed(const Fixed &fixed);
	virtual ~Fixed(void);
	Fixed &operator=(const Fixed &op);
	int getRawBits(void) const;
	void setRawBits(const int raw);
};
#endif
