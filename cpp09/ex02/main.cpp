/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:39:13 by tony              #+#    #+#             */
/*   Updated: 2023/08/08 11:04:30 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colors.hpp"

int main(int argc, char **argv)
{
    clock_t start;
    clock_t end;
    double vector_time;
    double deque_time;

    
    if (argc < 3)
    {
        std::cerr << "Not enough arguments!" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe vector_sort(VECTOR);
        PmergeMe deque_sort(DEQUE);
    
        vector_sort.initializeContainer(argc, argv);
        std::cout << MAGENTA << "Before: " << GREEN;
        vector_sort.printValues();
        start = clock();
        vector_sort.mergeInsertionSort();
        end = clock();
        vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

        deque_sort.initializeContainer(argc, argv);
        start = clock();
        deque_sort.mergeInsertionSort();
        end = clock();
        deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

        std::cout << MAGENTA << "After: " << GREEN; 
        vector_sort.printValues();
        std::cout << RESET << std::endl;


        std::cout << GREEN << "Time to sort " << CYAN << argc - 1 << GREEN << " elements with Vector: " << MAGENTA << vector_time << YELLOW << " µs" << std::endl; 
        std::cout << GREEN << "Time to sort " << CYAN << argc - 1 << GREEN << " elements with Deque: " << MAGENTA << deque_time << YELLOW << " µs" << std::endl; 
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
