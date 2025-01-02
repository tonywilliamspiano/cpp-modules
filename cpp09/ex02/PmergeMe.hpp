/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:38:33 by tony              #+#    #+#             */
/*   Updated: 2023/08/08 10:56:41 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque> 
# include <vector>
# include <sys/time.h>

# define DEQUE 0
# define VECTOR 1
# define THRESHOLD 10

class PmergeMe {
    private:
    	PmergeMe();
        std::vector<int> vectorContainer;
        std::deque<int> dequeContainer;
        int             _which_container;
    
    	void merge(std::vector<int>& arr, int left, int middle, int right);
    	void merge(std::deque<int>& arr, int left, int middle, int right);
		void insertionSort(std::vector<int>& arr, int left, int right);
		void insertionSort(std::deque<int>& arr, int left, int right);
        bool isInteger(const std::string &input, int *value);
		void mergeInsertionSort(std::vector<int>& arr, int left, int right, int threshold);
		void mergeInsertionSort(std::deque<int>& arr, int left, int right, int threshold);


    
    public:
    	PmergeMe(int which_container);
    	~PmergeMe();
    	PmergeMe(PmergeMe &to_copy);
    	PmergeMe &operator=(const PmergeMe &to_copy);
    
    	void initializeContainer(int size, char **args);
    	void printValues();
        void mergeInsertionSort();
};

unsigned long getTime();

#endif
