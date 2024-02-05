/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:11:18 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/02 11:32:52 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
	{
        this->bitcoinData = rhs.bitcoinData;
        this->inputData = rhs.inputData;
    }
    return (*this);
}

void	BitcoinExchange::parseBitcoinData(const std::string &filename)
{
    char	delim;
    float	value;
    std::string	date;
    std::string	line;
    std::ifstream	file(filename.c_str());

	if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    while (std::getline(file, line))
	{
        std::istringstream iss(line);
        if (iss >> date >> delim >> value)
            bitcoinData[date] = value;
    }
    file.close();
}

void	BitcoinExchange::parseInputData(const std::string &filename)
{
    char	delim;
    float	value;
    std::string	date;
    std::string	line;
    std::ifstream	file(filename.c_str());

    if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
    }
    while (std::getline(file, line))
	{
        std::istringstream iss(line);
        if (iss >> date >> delim >> value)
            inputData.push_back(std::make_pair(date, value));
    }
    file.close();
}

void	BitcoinExchange::processData()
{
    for (size_t i = 0; i < inputData.size(); ++i)
	{
        std::string date = inputData[i].first;
		float value = inputData[i].second;
        float bitcoinValue = getBitcoinValue(date);
        if (bitcoinValue == -1.0f)
            std::cerr << "Error: not a positive number." << std::endl;
        else
            std::cout << date << " => " << value << " = " << (bitcoinValue * value) << std::endl;
    }
}

float BitcoinExchange::getBitcoinValue(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = bitcoinData.find(date);
    if (it != bitcoinData.end())
        return (it->second);
    return -1.0f;
}