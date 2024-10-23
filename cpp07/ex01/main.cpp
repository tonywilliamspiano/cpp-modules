/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:02:07 by awilliam          #+#    #+#             */
/*   Updated: 2024/10/23 15:53:35 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e', 0};

    std::cout << "intArray: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "doubleArray: ";
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    std::cout << "charArray: ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    iter(intArray, 5, addFive<int>);
    iter(doubleArray, 5, addFive<double>);
    iter(charArray, 6, addFive<char>);

    // Using iter with the printElement function template
    std::cout << "intArray: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "doubleArray: ";
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    std::cout << "charArray: ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    return 0;
}