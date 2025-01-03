/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:38:23 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/28 16:52:40 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

// TODO - Also test copy constructor and assignment operator
int main() {
    try {
        Span sp(5); // Create a Span with a capacity of 5 integers

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.printNumbers();
        // Test shortestSpan() and longestSpan()
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Add many numbers to the Span using iterators
        std::vector<int> numbersToAdd;
        numbersToAdd.push_back(1);
        numbersToAdd.push_back(2);
        numbersToAdd.push_back(3);
        numbersToAdd.push_back(4);
        numbersToAdd.push_back(5);
        sp.addNumbers(numbersToAdd.begin(), numbersToAdd.end());

        // Test shortestSpan() and longestSpan() again after adding more numbers
        sp.printNumbers();
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Test copy and assignment:
        Span sp2(sp);
        Span sp3 = sp;
        std::cout << "OG Span: ";
        sp.printNumbers();
        std::cout << "#2 Span: ";
        sp2.printNumbers();
        std::cout << "#3 Span: ";
        sp3.printNumbers();


        // Test the exception:
        sp.addNumber(3);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::list<int> numbers(20000);
        std::srand(static_cast<unsigned>(time(nullptr)));
        std::generate(numbers.begin(), numbers.end(), std::rand);

        Span span(numbers.size());

        span.addNumbers(numbers.begin(), numbers.end());

        std::cout << std::endl;
        std::cout << "Max element: " << *(std::max_element(numbers.begin(), numbers.end())) << std::endl;
        std::cout << "Min element: " << *(std::min_element(numbers.begin(), numbers.end())) << std::endl;

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
