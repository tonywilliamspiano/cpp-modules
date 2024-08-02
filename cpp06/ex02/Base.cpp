/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:04:24 by tony              #+#    #+#             */
/*   Updated: 2023/07/27 10:21:09 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include "Base.hpp"

Base::~Base() {}

Base* Base::generate() {
    Base *ret;
    int randomNumber;

    std::srand((unsigned) std::time(NULL));
    randomNumber = std::rand() % 3;
    if (randomNumber == 0)
        ret = new A;
    else if (randomNumber == 1)
        ret = new B;
    else
        ret = new C;
    
    return ret;
}

void Base::identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer is of type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer is of type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer is of type C" << std::endl;
    else
        std::cout << "Something went wrong while identifying pointers..." << std::endl;
}

void Base::identify(Base& p) {
    if (dynamic_cast<A*>(&p))
        std::cout << "Reference is of type A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "Reference is of type B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "Reference is of type C" << std::endl;
    else
        std::cout << "Something went wrong while identifying references..." << std::endl;
}