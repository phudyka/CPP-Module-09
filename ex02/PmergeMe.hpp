/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:36:38 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 11:29:36 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <stdexcept>
#include <sstream>

class PmergeMe
{
	public:
		PmergeMe(const std::deque<int>& inputSequence);
    void	mergeInsertSort();
    void	displaySequence() const;
    void	displayTimeForDeque() const;
    void	displayTimeForList() const;

	private:
    	std::deque<int> dequeContainer;
    	std::list<int> listContainer;
    std::clock_t startDeque, endDeque, startList, endList;

    void	merge(std::list<int>::iterator listBegin, std::list<int>::iterator listEnd,
               std::deque<int>::iterator dequeBegin, std::deque<int>::iterator dequeEnd);
    void	insert(std::deque<int>::iterator dequeInsertPos, int value);
};

#endif // PMERGEME_HPP