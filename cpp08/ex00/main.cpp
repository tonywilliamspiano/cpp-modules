/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:12:43 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/28 16:34:05 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {

    // Test with int vector
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        int result = easyfind(vec, 3);
        std::cout << "Value found: " << result << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        int result = easyfind(vec, 6);
        std::cout << "Value found: " << result << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    // Test with float vector, just for fun
    std::vector<float> floatVec;
    floatVec.push_back(1.3f);
    floatVec.push_back(2.5f);
    floatVec.push_back(3.7f);
    floatVec.push_back(4.2f);
    floatVec.push_back(1.0f);

    try {
        float result = easyfind(floatVec, 3); // Should find the float 1.0f
        std::cout << "Value found: " << result << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        float result = easyfind(floatVec, 6); // Will throw an exception
        std::cout << "Value found: " << result << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    // Test with list
    std::list<int> list;
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(1);
    list.push_back(2);

    try {
        float result = easyfind(list, 2); // Should find the float 1.0f
        std::cout << "Value found: " << result << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
