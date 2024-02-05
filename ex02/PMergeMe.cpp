/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:56:03 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/05 16:56:05 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &src) {
    *this = src;
}

PMergeMe::~PMergeMe() {}

PMergeMe &PMergeMe::operator=(const PMergeMe &rhs) {
    if (this != &rhs) {
        this->firstContainer = rhs.firstContainer;
        this->secondContainer = rhs.secondContainer;
    }
    return *this;
}

void PMergeMe::processSequence(const std::vector<int> &inputSequence) {
    displaySequence(inputSequence, "Before");

    auto startFirstContainer = getCurrentTime();
    firstContainer = inputSequence; // Copy the sequence
    mergeInsertSort(firstContainer, startFirstContainer, "std::vector");
    auto endFirstContainer = getCurrentTime();

    auto startSecondContainer = getCurrentTime();
    secondContainer.assign(inputSequence.begin(), inputSequence.end()); // Copy the sequence
    mergeInsertSort(secondContainer, startSecondContainer, "std::list");
    auto endSecondContainer = getCurrentTime();

    displaySequence(firstContainer, "After");
    std::cout << "Time to process a range of " << inputSequence.size() << " elements with std::vector: "
              << std::chrono::duration_cast<std::chrono::microseconds>(endFirstContainer - startFirstContainer).count()
              << " us" << std::endl;

    displaySequence(secondContainer, "After");
    std::cout << "Time to process a range of " << inputSequence.size() << " elements with std::list: "
              << std::chrono::duration_cast<std::chrono::microseconds>(endSecondContainer - startSecondContainer).count()
              << " us" << std::endl;
}

void PMergeMe::mergeInsertSort(std::vector<int> &sequence, const std::chrono::high_resolution_clock::time_point &startTime, const std::string &containerName) {
    // Implement the merge-insert sort algorithm (Ford-Johnson)
    // ...

    // Dummy implementation (replace with actual sorting algorithm)
    std::sort(sequence.begin(), sequence.end());

    auto endTime = getCurrentTime();
    std::cout << "Time to process a range of " << sequence.size() << " elements with " << containerName << ": "
              << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() << " us"
              << std::endl;
}

void	PMergeMe::displaySequence(const std::vector<int> &sequence, const std::string &label) const {
    std::cout << label << ": ";
    for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::chrono::high_resolution_clock::time_point PMergeMe::getCurrentTime() const
{
    return std::chrono::high_resolution_clock::now();
}
