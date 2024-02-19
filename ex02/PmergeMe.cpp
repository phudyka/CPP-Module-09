/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:56:03 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/19 17:39:10 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::deque<int>& inputSequence)
    : dequeContainer(inputSequence.begin(), inputSequence.end()), listContainer(inputSequence.begin(), inputSequence.end()) {}

void PmergeMe::mergeInsertSort()
{
    startDeque = std::clock();
    std::sort(dequeContainer.begin(), dequeContainer.end());
    endDeque = std::clock();
    startList = std::clock();

    for (std::list<int>::iterator it = listContainer.begin(); it != listContainer.end(); ++it) {
        std::list<int>::iterator upperBound = std::upper_bound(listContainer.begin(), it, *it);
        dequeContainer.insert(std::lower_bound(dequeContainer.begin(), dequeContainer.end(), *it), *it);
        listContainer.splice(upperBound, listContainer, it);
    }
    endList = std::clock();
    displayTimeForDeque();
    displayTimeForList();
}

void PmergeMe::merge(std::list<int>::iterator listBegin, std::list<int>::iterator listEnd,
                     std::deque<int>::iterator dequeBegin, std::deque<int>::iterator dequeEnd)
{
    while (listBegin != listEnd && dequeBegin != dequeEnd) {
        if (*listBegin < *dequeBegin)
		{
            insert(dequeBegin, *listBegin);
            ++listBegin;
		}      
		else
            ++dequeBegin;
    }
    while (listBegin != listEnd)
	{
        insert(dequeEnd, *listBegin);
        ++listBegin;
    }
}

void PmergeMe::insert(std::deque<int>::iterator dequeInsertPos, int value)
{
    dequeContainer.insert(dequeInsertPos, value);
}

void PmergeMe::displaySequence() const
{
    std::cout << "Before: ";
    for (std::deque<int>::const_iterator it = dequeContainer.begin(); it != dequeContainer.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (std::list<int>::const_iterator it = listContainer.begin(); it != listContainer.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::displayTimeForDeque() const
{
    std::cout << "Time to process a range with deque: "
              << (static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC) * 1e6 << " us" << std::endl;
}

void PmergeMe::displayTimeForList() const
{
    std::cout << "Time to process a range with list: "
              << (static_cast<double>(endList - startList) / CLOCKS_PER_SEC) * 1e6 << " us" << std::endl;
}