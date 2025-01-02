/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:38:31 by tony              #+#    #+#             */
/*   Updated: 2023/08/08 10:56:11 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int which_container) {
    this->_which_container = which_container;
}

PmergeMe::PmergeMe(PmergeMe &other)
{
    this->_which_container = other._which_container;
    this->vectorContainer = other.vectorContainer;
    this->dequeContainer = other.dequeContainer;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_which_container = other._which_container;
        this->vectorContainer = other.vectorContainer;
        this->dequeContainer = other.dequeContainer;    
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

// Insertion sort algorithm for sorting small subarrays
void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::insertionSort(std::deque<int>& arr, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::initializeContainer(int size, char **args)
{
    int i = 1;
    int value;


    while (i < size)
    {
        if (!isInteger(args[i], &value))
            throw std::runtime_error("Error! Noninteger as input");
        else if (value < 0)
            throw std::runtime_error("Error! Negative number as input");
        if (this->_which_container == DEQUE)
            this->dequeContainer.push_back(value);
        else if (this->_which_container == VECTOR)
            this->vectorContainer.push_back(value);
        i++;
    }
}

void PmergeMe::printValues()
{
    std::vector<int>::iterator it;

    it = this->vectorContainer.begin();
    while (it != this->vectorContainer.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInsertionSort()
{
    if (_which_container == VECTOR)
        mergeInsertionSort(vectorContainer, 0, vectorContainer.size() - 1, THRESHOLD);
    else if (_which_container == DEQUE)
        mergeInsertionSort(dequeContainer, 0, dequeContainer.size() - 1, THRESHOLD);
}

bool PmergeMe::isInteger(const std::string &input, int *value)
{
    char    *endptr;
    long int num;
    
    if (input.length() > 11)
        return false;
    num = strtol(input.c_str(), &endptr, 10);

    if (*endptr || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
        return false;
    else
    {
        *value = num;
        return true;
    }
}

// Merge function to combine two sorted subarrays into one
void PmergeMe::merge(std::vector<int>& arr, int left, int middle, int right) 
{
    int size_left = middle - left + 1;
    int size_right = right - middle;

    std::vector<int> leftArray(size_left);
    std::vector<int> rightArray(size_right);

    for (int i = 0; i < size_left; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < size_right; ++j)
        rightArray[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < size_left && j < size_right) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < size_left) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < size_right) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge-Insertion Sort algorithm
void PmergeMe::mergeInsertionSort(std::vector<int>& arr, int left, int right, int threshold) 
{
    if (right - left + 1 <= threshold) 
        insertionSort(arr, left, right);
    else 
    {
        if (left < right) {
            int middle = left + (right - left) / 2;
            mergeInsertionSort(arr, left, middle, threshold);
            mergeInsertionSort(arr, middle + 1, right, threshold);
            merge(arr, left, middle, right);
        }
    }
}


// Merge function to combine two sorted subarrays into one
void PmergeMe::merge(std::deque<int>& arr, int left, int middle, int right) 
{
    int size_left = middle - left + 1;
    int size_right = right - middle;

    std::deque<int> leftArray(size_left);
    std::deque<int> rightArray(size_right);

    for (int i = 0; i < size_left; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < size_right; ++j)
        rightArray[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < size_left && j < size_right) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < size_left) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < size_right) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge-Insertion Sort algorithm
void PmergeMe::mergeInsertionSort(std::deque<int>& arr, int left, int right, int threshold) 
{
    if (right - left + 1 <= threshold) 
        insertionSort(arr, left, right);
    else 
    {
        if (left < right) {
            int middle = left + (right - left) / 2;
            mergeInsertionSort(arr, left, middle, threshold);
            mergeInsertionSort(arr, middle + 1, right, threshold);
            merge(arr, left, middle, right);
        }
    }
}

unsigned long getTime() 
{
        struct timeval time;

        gettimeofday(&time, NULL);
        return static_cast<unsigned long>(time.tv_sec) * 1000000 + time.tv_usec;
}
