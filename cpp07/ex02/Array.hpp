/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:54:04 by awilliam          #+#    #+#             */
/*   Updated: 2024/10/23 15:55:02 by awilliam         ###   ########.fr       */
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

    Array(const Array &oldInstance) : _myArray(new T[oldInstance.size()]), _size(oldInstance.size()) {
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_myArray[i] = oldInstance._myArray[i];
        }
    };

    ~Array() {
        delete[] this->_myArray;
    };

    Array &operator=(const Array &oldInstance) {
        if (this != &oldInstance) {
            this->_size = oldInstance.size();
            this->_myArray = new T[oldInstance.size()];
            for (unsigned int i = 0; i < this->_size; i++) {
                this->_myArray[i] = oldInstance._myArray[i];
            }
        }
        return (*this);
    };

    T &operator[](size_t index) {
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

#endif