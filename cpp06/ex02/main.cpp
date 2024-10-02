/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:53 by tony              #+#    #+#             */
/*   Updated: 2024/10/02 12:08:33 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main() {
    Base base;
    Base *unknown;

    unknown = base.generate();
    A *a = new A();
    B *b = new B();
    C *c = new C();

    base.identify(unknown);
    base.identify(a);
    base.identify(b);
    base.identify(c);
    std::cout << std::endl;


    base.identify(*unknown);
    base.identify(*a);
    base.identify(*b);
    base.identify(*c);
    std::cout << std::endl;

    delete unknown;
    delete a;
    delete b;
    delete c;
}