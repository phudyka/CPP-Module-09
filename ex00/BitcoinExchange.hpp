/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:11:20 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/02 11:29:07 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <vector>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <iostream>

class BitcoinExchange
{
	public:
    	BitcoinExchange();
    	BitcoinExchange(const BitcoinExchange &src);
    	~BitcoinExchange();
    	BitcoinExchange &operator=(const BitcoinExchange &rhs);

    void	parseBitcoinData(const std::string &filename);
    void	parseInputData(const std::string &filename);
    void	processData();

	private:
    	std::map<std::string, float> bitcoinData;
    	std::vector<std::pair<std::string, float> > inputData;

    float	getBitcoinValue(const std::string &date) const;
};

#endif