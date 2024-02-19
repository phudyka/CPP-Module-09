/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:53:19 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/19 17:37:42 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try {
        std::deque<int> inputSequence;

        if (argc < 2)
            throw std::invalid_argument("Error: Insufficient arguments");
        for (int i = 1; i < argc; ++i)
		{
            int	num;
            std::istringstream(argv[i]) >> num;
            if (std::istringstream(argv[i]).fail())
                throw std::invalid_argument("Error: Invalid argument - not an integer");
            inputSequence.push_back(num);
        }
        PmergeMe pmergeMe(inputSequence);
        pmergeMe.displaySequence();
        pmergeMe.mergeInsertSort();
        pmergeMe.displaySequence();

    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}