/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:11:15 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 11:47:04 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int	getData(BitcoinExchange &btc)
{
    std::string		date;
    std::string		value;
    std::string		line;
    std::fstream	file;

    file.open("data.csv", std::fstream::in);
    if (!file.is_open())
	{
        std::cerr << "Error: could not open data.csv" << std::endl;
        return (1);
    }
    std::getline(file, line);
    while (std::getline(file, line))
	{
        date = line.substr(0, 10);
        try
		{
            value = line.substr(line.find(',') + 1);
        }
		catch (const std::out_of_range &e)
		{
            std::cerr << "Error: no value" << std::endl;
            continue ;
        }
        btc.push(date, value);
    }
    file.close();
    return (0);
}

static int	parseInput(BitcoinExchange &btc, char *filename)
{
    float			price;
    std::string		date;
    std::string		value;
    std::string		line;
    std::fstream	file;

    file.open(filename, std::fstream::in);
    if (!file.is_open())
	{
        std::cerr << "Error: could not open " << filename << std::endl;
        return 1;
    }
    std::getline(file, line);
    while (std::getline(file, line))
	{
        date = line.substr(0, 10);
        try
		{
            value = line.substr(line.find('|') + 1);
        }
		catch (const std::out_of_range &e)
		{
            std::cerr << "Error: no value" << std::endl;
            continue;
        }
        if (validDate(date) && validPrice(value))
		{
            price = btc.calculatePrice(date, atof(value.c_str()));
            std::cout << date << " =>" << value << " = " << price << std::endl;
        }
    }
    file.close();
    return (0);
}

int	main(int ac, char **av)
{
    BitcoinExchange	btc;

    if (ac != 2)
	{
        std::cerr << "Usage: ./ex00 [filename]" << std::endl;
        return (1);
    }
    if (getData(btc) || parseInput(btc, av[1]))
        return (1);
    return (0);
}
