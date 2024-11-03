/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:41:26 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/03 11:55:02 by awilliam         ###   ########.fr       */
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
        Span(int N);
        Span(const Span & old);
        Span & operator=(const Span & old);
        ~Span();

        void addNumber(int n);
        void addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
        unsigned int getMaxLength() const;
        void printNumbers();

        int longestSpan();
        int shortestSpan();

        class VectorFullException : public std::exception {
        public:
            const char* what() const throw();
};
};

#endif
