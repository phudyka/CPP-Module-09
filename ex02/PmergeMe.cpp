/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:56:03 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 15:05:16 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    fillContainers(argc, argv);
    printBefore();
    performSortAndMeasureTime();
    printAfter();
    printResult();
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &arr)
{
    std::deque<int>::iterator it1, it2;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin())
        {
            std::deque<int>::iterator prevIt = it2;
            std::advance(prevIt, -1);

            if (*prevIt > temp)
            {
                *it2 = *prevIt;
                it2 = prevIt;
            }
            else
                break;
        }
        *it2 = temp;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int> &arr)
{
    std::list<int>::iterator it1, it2;
    for (it1 = ++arr.begin(); it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin())
        {
            std::list<int>::iterator prevIt = it2;
            std::advance(prevIt, -1);

            if (*prevIt > temp)
            {
                *it2 = *prevIt;
                it2 = prevIt;
            }
            else
                break;
        }
        *it2 = temp;
    }
}

void PmergeMe::fillContainers(int argc, char **argv)
{
    srand(time(NULL));
    for (int i = 1; i < argc; ++i)
    {
        int value = atoi(argv[i]);
        if (value <= 0)
        {
            std::cerr << "Error: Invalid input value \"" << argv[i] << "\". Only positive integers are allowed." << std::endl;
            exit(1);
        }
        inputDeque.push_back(value);
        inputList.push_back(value);
    }
}

void PmergeMe::printBefore()
{
    std::cout << "Before: ";
    display(inputDeque);
}

void PmergeMe::printAfter()
{
    std::cout << "After: ";
    display(inputDeque);
}

void PmergeMe::performSortAndMeasureTime()
{
    clock_t start1 = clock();
    mergeInsertSortDeque(inputDeque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    mergeInsertSortList(inputList);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    printSortingTime(time1, "std::deque");
    printSortingTime(time2, "std::list");
}

void PmergeMe::printSortingTime(double time, const std::string &containerType)
{
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with " << containerType << " container: " << time << " us" << std::endl;
}

void PmergeMe::printResult()
{
    if (inputDeque == std::deque<int>(inputList.begin(), inputList.end()))
        std::cout << "The sorted sequences are equal." << std::endl;
    else
        std::cout << "The sorted sequences are not equal." << std::endl;
}

template <typename T>
void PmergeMe::display(const T &container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}