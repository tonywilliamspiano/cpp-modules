/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:02:07 by awilliam          #+#    #+#             */
/*   Updated: 2024/10/23 16:16:56 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

//class Shirt {
//public:
//    Shirt(std::string color, std::string size) : _color(color), _size(size) { return; }
//    std::string getColor(void) const { return this->_color; }
//    std::string getSize(void) const { return this->_size; }
//
//private:
//    std::string _color;
//    std::string _size;
//};
//
//std::ostream &operator<<(std::ostream &o, Shirt const &rhs) {
//    o << "A " << rhs.getColor() << " shirt with size: " << rhs.getSize() << std::endl;
//    return o;
//}

void printSeparation() {
    std::cout << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - ";
    std::cout << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e', 0};

    std::cout << "Printing all elements of an intArray: ";
    iter(intArray, 5, printElement<int>);
    printSeparation();

    std::cout << "Printing all elements of a doubleArray: ";
    iter(doubleArray, 5, printElement<double>);
    printSeparation();

    std::cout << "Printing all elements of a charArray: ";
    iter(charArray, 5, printElement<char>);
    printSeparation();

    std::cout << "Adding 5 to all arrays... ";
    iter(intArray, 5, addFive<int>);
    iter(doubleArray, 5, addFive<double>);
    iter(charArray, 6, addFive<char>);
    printSeparation();

    // Using iter with the printElement function template
    std::cout << "intArray plus 5: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    printSeparation();

    std::cout << "doubleArray plus 5: ";
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;
    printSeparation();

    std::cout << "charArray plus 5: ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;
    printSeparation();

//    =============================================================
//    Shirt shirtArray[] = {
//            Shirt("red", "M"),
//            Shirt("blue", "L"),
//            Shirt("green", "S"),
//            Shirt("yellow", "XL"),
//            Shirt("black", "M")
//    };
//
//    std::cout << "Array of shirt objects: ";
//    iter(shirtArray, 5, printElement<Shirt>);
//    std::cout << std::endl;

    return 0;
}