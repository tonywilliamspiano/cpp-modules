/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:06:07 by tony              #+#    #+#             */
/*   Updated: 2024/10/02 11:43:56 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>

class ScalarConverter {
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);

    void convert(const std::string &input);
    std::string getType(const std::string &input, double *value);
    void printValues(std::string type, double value);

    double convertPseudo(const std::string &input);

    bool isInteger(const std::string &input, double *value);
    bool isFloat(const std::string &input, double *value);
    bool isDouble(const std::string &input, double *value);
    bool isPseudoLiteral(const std::string &input);
    bool isDisplayableChar(double c);
};

#endif