/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:03:30 by phudyka           #+#    #+#             */
/*   Updated: 2024/02/05 16:51:22 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <cstring>

class RPN
{
	private:
		std::stack<int> operands;
	public:
		RPN();
		RPN(const RPN &src);
		~RPN();
		RPN &operator=(const RPN &rhs);

    void	evaluateExpression(const std::string &expression);
	
    void	performOperation(char op);
};

#endif
