/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:53:19 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 15:05:36 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    PmergeMe PmergeMe(argc, argv);
    return (0);
}