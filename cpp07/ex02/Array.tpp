/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:54:04 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/03 11:07:31 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : _myArray(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _myArray(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(const Array &rhs) : _myArray(new T[rhs.size()]), _size(rhs.size()) {
    for (unsigned int i = 0; i < this->_size; i++) {
        this->_myArray[i] = rhs._myArray[i];
    }
}

template<typename T>
Array<T>::~Array() {
    delete[] this->_myArray;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
    if (this != &rhs) {
        delete[] this->_myArray;
        this->_size = rhs.size();
        this->_myArray = new T[rhs.size()];
        for (size_t i = 0; i < this->_size; i++) {
            this->_myArray[i] = rhs._myArray[i];
        }
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](size_t index) const {
    if (index >= this->_size) {
        throw OutOfBoundsException();
    }
    return this->_myArray[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return this->_size;
}

template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Index is out of bounds";
}

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
