/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:03:25 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/05 16:51:19 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;
        return (1);
    }
    RPN rpnCalculator;
    rpnCalculator.evaluateExpression(argv[1]);
    return (0);
}
