/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:50:43 by awilliam          #+#    #+#             */
/*   Updated: 2024/10/23 15:55:11 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Test with int data type
        Array<int> intArray; // Default constructor, creates an empty array
        Array<int> intArray2(5); // Creates an array of 5 elements initialized by default

        for (unsigned int i = 0; i < intArray2.size(); ++i) {
            intArray2[i] = i * 10; // Setting values using the subscript operator
        }

        // Test copy constructor and assignment operator
        Array<int> intArrayCopy = intArray2; // Copy constructor
        Array<int> intArrayCopy2;
        intArrayCopy2 = intArray2; // Assignment operator

        // Modify the original and copied arrays independently
        intArray2[0] = 42;
        intArrayCopy[1] = 42;
        intArrayCopy2[2] = 42;

        // Display elements of the arrays
        std::cout << "intArray2: ";
        for (unsigned int i = 0; i < intArray2.size(); ++i) {
            std::cout << intArray2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "intArrayCopy: ";
        for (unsigned int i = 0; i < intArrayCopy.size(); ++i) {
            std::cout << intArrayCopy[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "intArrayCopy2: ";
        for (unsigned int i = 0; i < intArrayCopy2.size(); ++i) {
            std::cout << intArrayCopy2[i] << " ";
        }
        std::cout << std::endl;

        // Test out-of-bounds access
        std::cout << "Testing out-of-bounds access: ";
        try {
            std::cout << intArray[0] << std::endl; // Should throw an exception
        } catch (const std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    try {
        // Test with string data type
        Array<std::string> stringArray(3);

        for (unsigned int i = 0; i < stringArray.size(); ++i) {
            stringArray[i] = "STRING"; // Setting values using the subscript operator
        }

        // Test copy constructor and assignment operator
        Array<std::string> stringArrayCopy = stringArray;

        // Modify the original and copied arrays independently
        stringArray[0] = "OG ARRAY";
        stringArrayCopy[0] = "COPY ARRAY";

        // Display elements of the arrays
        std::cout << "stringArray: ";
        for (unsigned int i = 0; i < stringArray.size(); ++i) {
            std::cout << stringArray[i] << " | ";
        }
        std::cout << std::endl;

        std::cout << "stringArray Copy: ";
        for (unsigned int i = 0; i < stringArrayCopy.size(); ++i) {
            std::cout << stringArrayCopy[i] << " | ";
        }
        std::cout << std::endl;

        // Test out-of-bounds access
        std::cout << "Testing out-of-bounds access: ";
        try {
            std::cout << stringArray[7] << std::endl; // Should throw an exception
        } catch (const std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}