/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:55:56 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/05 16:56:53 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <chrono>
# include <cstdlib>
# include <iostream>
# include <algorithm>

class PMergeMe
{
	public:
    	PMergeMe();
    	PMergeMe(const PMergeMe &src);
    	~PMergeMe();
    	PMergeMe &operator=(const PMergeMe &rhs);

    void	processSequence(const std::vector<int> &inputSequence);

	private:
    	std::vector<int> firstContainer;
    	std::list<int> secondContainer;

    void	mergeInsertSort(std::vector<int> &sequence, const std::chrono::high_resolution_clock::time_point &startTime, const std::string &containerName);
    void	displaySequence(const std::vector<int> &sequence, const std::string &label) const;
    std::chrono::high_resolution_clock::time_point	getCurrentTime() const;
};

#endif