/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:03:28 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/20 11:04:48 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
        this->operands = rhs.operands;
    return (*this);
}

void	RPN::evaluateExpression(const std::string &expression)
{
    int	operand;
    std::istringstream iss(expression);
    std::string	token;

    while (iss >> token)
	{
        if (isdigit(token[0]))
		{
            std::istringstream(token) >> operand;
            operands.push(operand);
        }
		else if (token.size() == 1 && strchr("+-*/", token[0]))
            performOperation(token[0]);
        else
		{
            std::cerr << "Error: Invalid token - " << token << std::endl;
            return ;
        }
    }
    if (!operands.empty())
        std::cout << operands.top() << std::endl;
    else
        std::cerr << "Error: Empty expression" << std::endl;
}

void RPN::performOperation(char op)
{
    if (operands.size() < 2)
	{
        std::cerr << "Error: Insufficient operands for operation" << std::endl;
        return ;
    }
    int	operand2 = operands.top();
    operands.pop();
    int	operand1 = operands.top();
    operands.pop();
    switch (op)
	{
        case '+':
            operands.push(operand1 + operand2);
            break ;
        case '-':
            operands.push(operand1 - operand2);
            break ;
        case '*':
            operands.push(operand1 * operand2);
            break ;
        case '/':
            if (operand2 == 0)
			{
                std::cerr << "Error: Division by zero" << std::endl;
                return ;
            }
            operands.push(operand1 / operand2);
            break ;
        default:
            std::cerr << "Error: Invalid operator - " << op << std::endl;
    }
}