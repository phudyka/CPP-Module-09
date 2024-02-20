/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:11:18 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 11:47:21 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        this->_data = copy._data;
    return *this;
}

void	BitcoinExchange::push(const std::string &date, const std::string &price)
{
    this->_data.insert(std::make_pair(date, atof(price.c_str())));
}

void	BitcoinExchange::pop(const std::string &date)
{
    if (!validDate(date))
        return;
    this->_data.erase(date);
}

float	BitcoinExchange::calculatePrice(const std::string &date, float amount)
{
    std::map<std::string, float>::iterator pair = this->_data.lower_bound(date);

    if (pair == this->_data.end())
	{
        std::cerr << "Error: Out of range" << std::endl;
        return 0;
    }
    return (amount * pair->second);
}

bool	validDate(const std::string &date)
{
    if (date.length() != 10)
	{
        std::cerr << "Invalid date format" << std::endl;
        return false;
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
	{
        std::cerr << "Error: invalid date value" << std::endl;
        return false;
    }
    return true;
}

bool	validPrice(const std::string &price)
{
    float num = 0;

    try
	{
        num = atof(price.c_str());
    }
	catch (const std::out_of_range &e)
	{
        std::cerr << "Error: Out of range" << std::endl;
        return false;
    }
    if (num < 0)
	{
        std::cerr << "Error: Negative value" << std::endl;
        return false;
    }
    if (num > 1000)
	{
        std::cerr << "Error: Value too large" << std::endl;
        return false;
    }
    return true;
}