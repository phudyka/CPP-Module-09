/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:36:38 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 15:04:20 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>

class PmergeMe
{
public:
    PmergeMe(int argc, char **argv);
    template <typename T>
    void	display(const T &container);
    void	mergeInsertSortDeque(std::deque<int> &arr);
    void	mergeInsertSortList(std::list<int> &arr);

private:
    std::deque<int>	inputDeque;
    std::list<int>	inputList;
    void	fillContainers(int argc, char **argv);
    void	printBefore();
    void	performSortAndMeasureTime();
    void	printAfter();
    void	printSortingTime(double time, const std::string &containerType);
    void	printResult();
};