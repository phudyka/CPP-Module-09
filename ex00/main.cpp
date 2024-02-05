/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:11:15 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/02 11:45:53 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return (1);
    }
    BitcoinExchange exchange;
    exchange.parseBitcoinData("bitcoin_data.csv");
    exchange.parseInputData(argv[1]);
    exchange.processData();
    return (0);
}
