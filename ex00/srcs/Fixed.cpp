/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:55:48 by paulo             #+#    #+#             */
/*   Updated: 2022/11/14 11:49:29 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

Fixed::Fixed(void) : _fpoint(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fpoint = src.getRawsBits();
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