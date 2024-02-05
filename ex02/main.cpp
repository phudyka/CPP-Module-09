/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:53:19 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/05 16:57:22 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int	main(int argc, char **argv)
{
    if (argc < 2)
	{
        std::cerr << "Usage: " << argv[0] << " <int1> <int2> ... <intN>" << std::endl;
        return (1);
    }
    std::vector<int> inputSequence;
    for (int i = 1; i < argc; ++i)
        inputSequence.push_back(std::atoi(argv[i]));
    PMergeMe pMergeMe;
    pMergeMe.processSequence(inputSequence);

    return (0);
}
