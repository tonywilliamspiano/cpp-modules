/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:49:32 by tony              #+#    #+#             */
/*   Updated: 2023/08/07 09:41:45 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Bad input: Numbers must be entered within quotes like this:\n\"1 2 3 - +\"" << std::endl;
        return (1);
    }
    if (!*argv[1])
    {
        std::cerr << "No empty arguments! Stop trying to break the code" << std::endl;
        return (1);
    }
    try
    {
        calculateRPN(argv[1]);
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
