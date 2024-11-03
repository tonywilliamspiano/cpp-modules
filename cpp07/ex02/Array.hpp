/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:54:04 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/03 11:07:31 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template<typename T>
class Array {
private:
    T *_myArray;
    unsigned int _size;

public:
    Array() : _myArray(NULL), _size(0) {};

    Array(unsigned int n) : _myArray(new T[n]), _size(n) {};

    Array(const Array &rhs) : _myArray(new T[rhs.size()]), _size(rhs.size()) {
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_myArray[i] = rhs._myArray[i];
        }
    };

    ~Array() {
        delete[] this->_myArray;
    };

    Array &operator=(const Array &rhs) {
        if (this != &rhs) {
            this->_size = rhs.size();
            this->_myArray = new T[rhs.size()];
            for (unsigned int i = 0; i < this->_size; i++) {
                this->_myArray[i] = rhs._myArray[i];
            }
        }
        return (*this);
    };

    T &operator[](size_t index) const {
        if (index >= this->_size) {
            throw OutOfBoundsException();
        }
        return this->_myArray[index];
    };

    unsigned int size() const {
        return (this->_size);
    };

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char *what() const throw() { return "Index is out of bounds"; }
    };
};

template<typename T>
std::ostream &operator<<(std::ostream &s, const Array<T> &arr) {
    s << "[ ";

    for (size_t i = 0; i < arr.size(); ++i) {
        s << arr[i];
        if (i != arr.size() - 1) {
            s << ", ";
        }
    }
    s << " ]" << std::endl;
    return s;
}

#endif