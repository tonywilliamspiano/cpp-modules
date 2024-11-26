/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:40:23 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/26 16:14:40 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() {
        // Because it's interesting:
//        std::cout << "Using container type: "
//                  << typeid(typename std::stack<T>::container_type).name()
//                  << std::endl;
    };

    ~MutantStack() {};

    MutantStack(const MutantStack &rhs) : std::stack<T>(rhs) {};

    MutantStack &operator=(const MutantStack &rhs) {
        std::stack<T>::operator=(rhs);
        return *this;
    };

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() {
        return std::stack<T>::c.begin();
    }

    iterator end() {
        return std::stack<T>::c.end();
    }

    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }

    const_iterator end() const {
        return std::stack<T>::c.end();
    }
};

#endif
