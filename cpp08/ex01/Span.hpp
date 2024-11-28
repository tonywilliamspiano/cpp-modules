/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:41:26 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/28 16:41:45 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
private:
    Span();
    std::vector<int> _numbers;
    unsigned int _maxLength;

public:
    Span(unsigned int N);
    Span(const Span &old);
    Span &operator=(const Span &old);
    ~Span();

    void addNumber(int n);

    template<typename ContainerIterator>
    void addNumbers(ContainerIterator begin, ContainerIterator end) {
        _numbers.insert(_numbers.end(), begin, end);
    }

    unsigned int getMaxLength() const;
    void printNumbers();

    int longestSpan();
    int shortestSpan();

    class VectorFullException : public std::exception {
    public:
        const char *what() const throw();
    };
};

#endif
