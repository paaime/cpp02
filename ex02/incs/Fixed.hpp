/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:51:27 by paulo             #+#    #+#             */
/*   Updated: 2022/10/29 17:33:35 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed();
        ~Fixed();
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(Fixed const &src);
        Fixed &operator=(Fixed const &rhs);        
        int     getRawsBits(void) const;
        void    setRawsBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;
        static Fixed &min(Fixed &fixed1, Fixed &fixed2);
        static const Fixed &min(Fixed const &fixed1, Fixed const &fixed2);
        static Fixed &max(Fixed &fixed1, Fixed &fixed2);
        static const Fixed &max(Fixed const &fixed1, Fixed const &fixed2);

        bool operator>(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const;

        Fixed operator+(Fixed const &rhs) const;
        Fixed operator-(Fixed const &rhs) const;
        Fixed operator*(Fixed const &rhs) const;
        Fixed operator/(Fixed const &rhs) const;
        

        Fixed &operator++(void);
        Fixed &operator--(void);

        Fixed operator++(int);
        Fixed operator--(int);

    private:
        int                 _fpoint;
        static const int    _fbits = 8;
        
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed);

#endif