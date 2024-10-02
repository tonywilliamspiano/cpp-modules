/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:53 by tony              #+#    #+#             */
/*   Updated: 2024/10/02 12:09:33 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

// TODO - Review code to make sure I fully understand
//      - Review the differences between the types of casting in CPP
//      - Test rigorously
//      - Test against subject


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Nice try, but only one argument allowed" << std::endl;
        return (1);
    }
    if (!*argv[1]) {
        std::cerr << "Ha! You really don't think I tested empty strings?" << std::endl;
        return (1);
    }
    ScalarConverter myConverter;

    myConverter.convert(argv[1]);
}