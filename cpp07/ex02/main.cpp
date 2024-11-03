/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:50:43 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/03 11:27:57 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

//
int main() {
    try {
        // Test with int data type
        Array<int> intArray; // Default constructor, creates an empty array
        Array<int> intArray2(5); // Creates an array of 5 elements initialized by default

        for (unsigned int i = 0; i < intArray2.size(); ++i) {
            intArray2[i] = i * 10; // Setting values using the subscript operator
        }

        // Test copy constructor and assignment operator
        Array<int> intArrayCopy(intArray2);
        Array<int> intArrayCopy2(10);
        intArrayCopy2 = intArray2;

        // Modify the original and copied arrays independently
        intArray2[0] = 42;
        intArrayCopy[1] = 42;
        intArrayCopy2[2] = 42;

        // Display arrays
        std::cout << "intArray2: " << intArray2;
        std::cout << "intArrayCopy: " << intArrayCopy;
        std::cout << "intArrayCopy2: " << intArrayCopy2;

        std::cout << "Size of intArrayCopy: " << intArrayCopy.size() << std::endl;

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
        Array<std::string> stringArrayCopy = Array<std::string>(stringArray);
        Array<std::string> stringArrayCopy2 = stringArray;

        // Modify the original and copied arrays independently
        stringArray[0] = "OG ARRAY";
        stringArrayCopy[0] = "COPY ARRAY WITH CONSTRUCTOR";
        stringArrayCopy2[0] = "COPY ARRAY WITH ASSIGNMENT";

        // Display the arrays
        std::cout << "stringArray: " << stringArray;
        std::cout << "stringArray Copy: " << stringArrayCopy;
        std::cout << "stringArray Copy2: " << stringArrayCopy2;

        // Test out-of-bounds access
        std::cout << "Testing out-of-bounds access: ";
        try {
            std::cout << stringArray[7] << std::endl; // Should throw an exception
        } catch (const std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "Testing out of bounds for negative number: " << stringArray[-1] << std::endl;

    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}