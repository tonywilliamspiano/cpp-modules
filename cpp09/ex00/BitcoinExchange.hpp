/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:42:01 by awilliam          #+#    #+#             */
/*   Updated: 2025/01/02 11:00:16 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <algorithm>
# include <fstream>
# include "colors.hpp"

class BitcoinExchange {
private:
    std::map<std::string, double> bitcoin_data;
    BitcoinExchange();
    int printError(std::string msg, std::string line);

    double getPrice(const std::string date) const;
    void getDate(std::string line);

    bool checkDouble(const std::string &input, double *value);
    bool isValidDate(const std::string &date);

public:
    BitcoinExchange(std::string database, std::string input_file);
    BitcoinExchange(BitcoinExchange &rhs);
    BitcoinExchange &operator=(BitcoinExchange &rhs);
    ~BitcoinExchange();

    int readIntoMap(const std::string file_name);
    int readInputFile(const std::string file_name);
};

#endif
