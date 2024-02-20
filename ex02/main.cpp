/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:53:19 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 11:28:58 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		std::deque<int> inputSequence;
        if (argc < 2)
            throw std::invalid_argument("Error");
        for (int i = 1; i < argc; ++i)
		{
    		int	num;
			std::istringstream(argv[i]) >> num;
    		if (std::istringstream(argv[i]).fail())
        		throw std::invalid_argument("Error");
    		if (num < 0)
        		throw std::invalid_argument("Error");
    		inputSequence.push_back(num);
		}
        if (inputSequence.empty())
            throw std::invalid_argument("Error");
        PmergeMe pmergeMe(inputSequence);
        pmergeMe.displaySequence();
        pmergeMe.mergeInsertSort();
        pmergeMe.displaySequence();
    }
	catch (const std::invalid_argument& e)
	{
        std::cerr << e.what() << std::endl;
        return (1);
    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}