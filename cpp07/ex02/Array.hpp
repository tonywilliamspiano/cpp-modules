/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:54:04 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/03 11:16:22 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {
private:
    T *_myArray;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &rhs);
    ~Array();

    Array &operator=(const Array &rhs);
    T &operator[](size_t index) const;
    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

template<typename T>
std::ostream &operator<<(std::ostream &s, const Array<T> &arr);

#include "Array.tpp"

#endif