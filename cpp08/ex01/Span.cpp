/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:41:58 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/03 11:54:55 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(int N) : _maxLength(N) {}

Span::Span(const Span & old) : _maxLength(old.getMaxLength()) {
    if (this != &old)
        this->addNumbers(old._numbers.begin(), old._numbers.end());
}

Span & Span::operator=(const Span & old)
{
    if (this != &old)
    {
        this->_maxLength = old.getMaxLength();
        this->addNumbers(old._numbers.begin(), old._numbers.end());
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (this->_numbers.size() >= this->getMaxLength())
        throw Span::VectorFullException();
    else 
        this->_numbers.push_back(n);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    this->_numbers.insert(this->_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
    std::vector<int> copy;
    int minSpan;

    minSpan = this->longestSpan();
    copy = this->_numbers;
    std::sort(copy.begin(), copy.end());
    for (std::vector<int>::const_iterator it = copy.begin(); it + 1 != copy.end(); ++it) 
        minSpan = std::min(minSpan, *(it + 1) - *(it));
    return (minSpan);
}

int Span::longestSpan()
{
    std::vector<int> copy;

    copy = this->_numbers;
    std::sort(copy.begin(), copy.end());
    this->_numbers = copy;
    return (*(std::prev(copy.end())) - *(copy.begin()));
}


unsigned int Span::getMaxLength() const
{
    return (this->_maxLength);
}

void Span::printNumbers()
{
    for (std::vector<int>::const_iterator it = this->_numbers.begin(); it != this->_numbers.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

const char * Span::VectorFullException::what() const throw()
{
    return ("Vector already full!");
}
