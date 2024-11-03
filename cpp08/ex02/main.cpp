/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:51:11 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/03 12:15:50 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

// TODO - test assignment operator and copy constructor
int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    std::cout << mstack.size() << std::endl << std::endl;
    std::cout << "- - - - - - - - - - - - - - - -" << std::endl;

    // Testing with list instead of stack:
    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);

    std::list<int>::iterator it2 = mlist.begin();
    std::list<int>::iterator ite2 = mlist.end();
    ++it2;
    --it2;
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::cout << std::endl;
    std::cout << mlist.size() << std::endl << std::endl;
}
