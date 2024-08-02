/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:06:07 by tony              #+#    #+#             */
/*   Updated: 2023/07/25 12:28:41 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>

class A;
class B;
class C;

class Base {
    public:
        virtual ~Base();

        Base *generate(void);
        void identify(Base *p);
        void identify(Base &p);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif