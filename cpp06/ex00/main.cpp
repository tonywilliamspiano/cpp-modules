/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:53 by tony              #+#    #+#             */
/*   Updated: 2023/07/25 11:02:33 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Nice try, but only one argument allowed" << std::endl;
        return (1);
    }
    if (!*argv[1])
    {
        std::cerr << "Ha! You really don't think I tested empty strings?" << std::endl;
        return (1);
    }
    ScalarConverter myConverter;

    myConverter.convert(argv[1]);
}