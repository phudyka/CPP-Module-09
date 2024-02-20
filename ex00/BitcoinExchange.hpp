/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:11:20 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 11:47:00 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	private:
    	std::map<std::string, float> _data;

	public:
    	BitcoinExchange();
    	BitcoinExchange(const BitcoinExchange &copy);
    	BitcoinExchange &operator=(const BitcoinExchange &copy);
    	~BitcoinExchange();

    void	push(const std::string &date, const std::string &price);
    void	pop(const std::string &date);
    float	calculatePrice(const std::string &date, float amount);
};

bool	validDate(const std::string &date);
bool	validPrice(const std::string &price);

#endif // BITCOIN_EXCHANGE_HPP