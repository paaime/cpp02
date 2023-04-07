/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paime <paime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:51:27 by paulo             #+#    #+#             */
/*   Updated: 2022/11/14 16:48:36 by paime            ###   ########.fr       */
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
        Fixed & operator=(Fixed const &rhs);
        int     getRawsBits(void) const;
        void    setRawsBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;

    private:
        int                 _fpoint;
        static const int    _fbits = 8;
        
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed);

#endif