/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:55:48 by paulo             #+#    #+#             */
/*   Updated: 2022/11/14 12:03:22 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fpoint(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int nb) {
    std::cout << "Int constructor called" << std::endl;
    this->_fpoint = nb << this->_fbits;
    return ;
}

Fixed::Fixed(const float nb) {
    std::cout << "Float constructor called" << std::endl;
    this->_fpoint = roundf(nb * (1 << this->_fbits));
    return ;
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fpoint = src._fpoint;
    
    return ;
}

Fixed & Fixed::operator=(Fixed const &rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    this->_fpoint = rhs.getRawsBits();
    
    return *this;
}

int Fixed::getRawsBits(void) const {
    std::cout << "getRawsBits member function called" << std::endl;
    return this->_fpoint;
}

void Fixed::setRawsBits(int const raw) {
    this->_fpoint = raw;
    return ;
}

int Fixed::toInt(void) const {
    return (this->_fpoint >> this->_fbits);
}

float Fixed::toFloat(void) const {
    return (((float)this->_fpoint) / (1 << this->_fbits));
}


std::ostream & operator<<(std::ostream &ostream, Fixed const &fixed) {
    ostream << fixed.toFloat();
    return ostream;
}
