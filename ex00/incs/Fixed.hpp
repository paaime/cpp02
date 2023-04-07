/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:51:27 by paulo             #+#    #+#             */
/*   Updated: 2022/10/29 11:00:57 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed const &src);
        Fixed & operator=(Fixed const &rhs);
        int     getRawsBits(void) const;
        void    setRawsBits(int const raw);    

    private:
        int                 _fpoint;
        static const int    _fbits = 8;
        
};

#endif