/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:06:05 by awilliam          #+#    #+#             */
/*   Updated: 2024/10/02 12:08:19 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath> // For std::fabs

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this == &other) {
        return *this;
    }
    return *this;
}

void ScalarConverter::convert(const std::string &input) {
    double value;
    std::string type;

    type = this->getType(input, &value);
    if (static_cast<double>(value) - static_cast<int>(value) == 0)
        std::cout << std::fixed << std::setprecision(1);
    else if (type == "pseudo-literal")
        value = convertPseudo(input);
    else if (type == "not found") {
        std::cout << "Type not recognized" << std::endl;
        return;
    }
    printValues(type, value);
}

std::string ScalarConverter::getType(const std::string &input, double *value) {
    if (this->isPseudoLiteral(input))
        return "pseudo-literal";
    if (this->isInteger(input, value))
        return "int";
    if (input.length() == 1 && isDisplayableChar(input[0])) {
        *value = input[0];
        return "int";
    }
    if (this->isFloat(input, value))
        return "double";
    if (this->isDouble(input, value))
        return "double";
    return "not found";
}

void ScalarConverter::printValues(std::string type, double value) {

    if (type == "pseudo-literal") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
        return;
    }

    if (!isDisplayableChar(value))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: out of range" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
        std::cout << "float: out of range" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

double ScalarConverter::convertPseudo(const std::string &input) {
    if (input == "nan" || input == "nanf")
        return std::numeric_limits<double>::quiet_NaN();
    if (input == "-inf" || input == "-inff")
        return -std::numeric_limits<double>::infinity();
    if (input == "+inf" || input == "+inff")
        return std::numeric_limits<double>::infinity();
    return 0;
}

// TYPE CHECKERS
bool ScalarConverter::isInteger(const std::string &input, double *value) {
    char *endptr;
    long int num;

    if (input.length() > 11)
        return false;
    num = strtol(input.c_str(), &endptr, 10);

    if (*endptr || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
        return false;
    else {
        *value = num;
        return true;
    }
}

bool ScalarConverter::isDouble(const std::string &input, double *value) {
    char *endptr;
    double num;
    int precision;

    num = strtod(input.c_str(), &endptr);

    if (*endptr || num < std::numeric_limits<double>::min() || num > std::numeric_limits<double>::max())
        return false;
    else {
        *value = num;
        if (input.find('.') < input.length() && input.find('.') < 10) {
            precision = input.length() - input.find('.') - 1;
            if (precision > 16)
                precision = 16;
            std::cout << std::fixed << std::setprecision(precision);
        }
        return true;
    }
}

bool ScalarConverter::isFloat(const std::string &input, double *value) {
    char *endptr;
    float num;
    int precision;

    num = strtod(input.c_str(), &endptr);
    if (*endptr != 'f' || *(endptr + 1) != '\0' || num < std::numeric_limits<float>::min() ||
        num > std::numeric_limits<float>::max())
        return false;
    else {
        *value = num;
        if (input.find('.') < input.length() && input.find('.') < 10) {
            precision = input.length() - input.find('.') - 2;
            if (precision > 16)
                precision = 16;
            std::cout << std::fixed << std::setprecision(precision);
        }
        return true;
    }
}

bool ScalarConverter::isPseudoLiteral(const std::string &input) {
    return input == "nan" || input == "nanf" ||
           input == "+inf" || input == "-inf" ||
           input == "+inff" || input == "-inff";
}

bool ScalarConverter::isDisplayableChar(double c) {
    return c >= 32 && c <= 126;
}
