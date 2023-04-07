/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:55:48 by paulo             #+#    #+#             */
/*   Updated: 2022/11/14 13:54:43 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fpoint(0) {
    // std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void) {
    // std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int nb) {
    // std::cout << "Int constructor called" << std::endl;
    this->_fpoint = nb << this->_fbits;
    return ;
}

Fixed::Fixed(const float nb) {
    // std::cout << "Float constructor called" << std::endl;
    this->_fpoint = roundf(nb * (1 << this->_fbits));
    return ;
}

Fixed::Fixed(Fixed const &src) {
    // std::cout << "Copy constructor called" << std::endl;
    this->_fpoint = src._fpoint;

    return ;
}

Fixed & Fixed::operator=(Fixed const &rhs) {
    // std::cout << "Copy assignation operator called" << std::endl;
    this->_fpoint = rhs.getRawsBits();
    return *this;
}

bool    Fixed::operator>(Fixed const &rhs) const {
    return(this->_fpoint > rhs._fpoint);
}

bool    Fixed::operator<(Fixed const &rhs) const {
    return(this->_fpoint < rhs._fpoint);
}

bool    Fixed::operator>=(Fixed const &rhs) const {
    return(this->_fpoint >= rhs._fpoint);
}

bool    Fixed::operator<=(Fixed const &rhs) const {
    return(this->_fpoint <= rhs._fpoint);
}

bool    Fixed::operator==(Fixed const &rhs) const {
    return(this->_fpoint == rhs._fpoint);
}

bool    Fixed::operator!=(Fixed const &rhs) const {
    return(this->_fpoint != rhs._fpoint);
}

Fixed   Fixed::operator+(Fixed const &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(Fixed const &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(Fixed const &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(Fixed const &rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++(void) {
    this->_fpoint++;
    return *this;
}

Fixed & Fixed::operator--(void) {
    this->_fpoint--;
    return *this;
}

Fixed   Fixed::operator++(int) {
    Fixed copy(*this);
    this->_fpoint++;
    return copy;
}

Fixed   Fixed::operator--(int) {
    Fixed copy(*this);
    this->_fpoint--;
    return copy;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
    if(fixed1._fpoint < fixed2._fpoint)
        return fixed1;
    else
        return fixed2;
}

Fixed const &Fixed::min(Fixed const &fixed1, Fixed const &fixed2) {
    if(fixed1._fpoint < fixed2._fpoint)
        return fixed1;
    else
        return fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
    if(fixed1._fpoint > fixed2._fpoint)
        return fixed1;
    else
        return fixed2;
}

Fixed const &Fixed::max(Fixed const &fixed1, Fixed const &fixed2) {
    if(fixed1._fpoint > fixed2._fpoint)
        return fixed1;
    else
        return fixed2;
}

int Fixed::getRawsBits(void) const {
    // std::cout << "getRawsBits member function called" << std::endl;
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
