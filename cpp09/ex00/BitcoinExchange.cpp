/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:42:08 by awilliam          #+#    #+#             */
/*   Updated: 2025/01/02 11:21:02 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string database, std::string input_file) {
    if (this->readIntoMap(database) == 1)
        return;
    this->readInputFile(input_file);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &rhs) {
    this->bitcoin_data = rhs.bitcoin_data;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &rhs) {
    this->bitcoin_data = rhs.bitcoin_data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::readIntoMap(const std::string file_name) {
    std::ifstream infile(file_name);
    std::string line;
    std::string date;
    std::string price;
    double price_val;
    size_t str_position;

    // TODO - Throw exceptions instead of print error
    if (!infile)
        return this->printError("Error: could not open file.", "");
    getline(infile, line);
    if (line != "date,exchange_rate")
        return this->printError("Invalid database header! Should be: 'date,exchange_rate'", "");
    while (getline(infile, line)) {
        str_position = line.find_first_of(",");
        date = line.substr(0, str_position);
        price = line.substr(str_position + 1);
        if (str_position >= line.length() || price == "" || date == "")
            return this->printError("Must be two comma separated values", line);
        if (!isValidDate(date))
            return this->printError("Date invalid!", line);
        if (!checkDouble(price, &price_val))
            return this->printError("Price not readable", line);
        this->bitcoin_data[date] = price_val;
    }
    return 0;
}

int BitcoinExchange::readInputFile(const std::string file_name) {
    std::ifstream infile(file_name);
    std::string line;

    // TODO - Throw exceptions instead of print error
    if (!infile)
        return this->printError("Error: could not open file.", "");
    getline(infile, line);
    if (line != "date | value")
        return this->printError("Invalid input header! Should be: 'date | value'", "");
    while (getline(infile, line)) {
        getDate(line);
    }
    return 0;
}

void BitcoinExchange::getDate(std::string line) {
    std::string date;
    std::string amt;
    double price;
    size_t str_position;
    double amt_val;

    str_position = line.find_first_of(" |");
    date = line.substr(0, str_position);
    amt = line.substr(str_position + 3);

    // TODO - Throw exceptions instead of print error - Then get rid of elses
    if (str_position >= line.length() || amt == "" || date == "")
        this->printError("bad input:", line);
    else if (!checkDouble(amt, &amt_val))
        this->printError("Could not parse Bitcoin amount as double:", line);
    else if (amt_val > 1000)
        this->printError("Bitcoin amount out of range:", line);
    else if (!isValidDate(date))
        this->printError("Invalid date:", line);
    else {
        price = getPrice(date);
        if (price == -1)
            this->printError("Date outside range of database:", line);
        else
            std::cout << GREEN << date << " => " << amt_val << " => " << amt_val * price << RESET << std::endl;
    }
}

// TODO - Understand map and iterator better, be able to explain
double BitcoinExchange::getPrice(const std::string date) const {
    std::map<std::string, double>::const_iterator it = bitcoin_data.begin();
    std::map<std::string, double>::const_iterator tmp;

    if (date < it->first)
        return -1.0;
    tmp = it;
    it++;
    while (it != bitcoin_data.end()) {
        if (date < it->first)
            return tmp->second;
        tmp = it;
        it++;
    }
    return -1.0;
}

bool BitcoinExchange::checkDouble(const std::string &input, double *value) {
    char *endptr;
    double num = 0.0;

    if (input == "0")
        return true;
    num = strtod(input.c_str(), &endptr);

    if (*endptr || num < 0 || num > std::numeric_limits<double>::max())
        return false;
    else {
        *value = num;
        return true;
    }
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    int days_of_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string year;
    std::string month;
    std::string day;
    double year_d;
    double month_d;
    double day_d;

    if (date.length() != 10)
        return false;
    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);

    if (!checkDouble(year, &year_d) || !checkDouble(month, &month_d) || !checkDouble(day, &day_d))
        return false;
    if (month_d > 12 || day_d > days_of_month[static_cast<int>(month_d - 1)])
        return false;
    if (static_cast<int>(month_d) == 2 && static_cast<int>(day_d) == 29 && static_cast<int>(year_d) % 4 != 0)
        return false;

    return true;
}

// TODO - Handle this with exceptions in main instead.
int BitcoinExchange::printError(std::string msg, std::string line) {
    std::cerr << YELLOW << "Error: " << msg << " " << MAGENTA << line << RESET << std::endl;
    return 1;
}
