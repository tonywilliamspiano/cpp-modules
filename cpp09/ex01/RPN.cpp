/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:54:00 by tony              #+#    #+#             */
/*   Updated: 2023/08/07 09:48:51 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int calculateRPN(std::string input)
{
    std::stack<int> my_stack;
    size_t          i = 0;

    (void) my_stack;
    while (i < input.length())
    {
        if (isdigit(input[i]))
            my_stack.push(input[i] - '0');
        else if (isSign(input[i]))
            makeCalculation(input[i], &my_stack);
        else
            throw std::runtime_error("Error! Bad input");
        i++;
        if (i < input.length() && input[i] != ' ')
            throw std::runtime_error("Error! Bad input");
        i++;
    }
    if (my_stack.size() != 1)
            throw std::runtime_error("Error! Too many numbers, not enough signs");
    std::cout << my_stack.top() << std::endl;
    return (0);
}

int isSign(char c)
{
    if (strchr("+-*/", c))
        return (1);
    else
        return (0);
}

void makeCalculation(char c, std::stack<int> *my_stack)
{
    int a;
    int b;

    if (my_stack->empty() || my_stack->size() == 1)
        throw std::runtime_error("Error! Too many signs, not enough numbers");
    a = my_stack->top();
    my_stack->pop();
    b = my_stack->top();
    my_stack->pop();

    if (c == '-')
        my_stack->push(b - a);
    else if (c == '+')
        my_stack->push(b + a);
    else if (c == '/')
    {
        if (a == 0)
            throw std::runtime_error("Error! Division by zero");
        my_stack->push(b / a);
    }
    else if (c == '*')
        my_stack->push(b * a);
}

