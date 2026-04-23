/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:39:10 by belinore          #+#    #+#             */
/*   Updated: 2026/04/23 14:12:48 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>

class RPN
{
    private:
    std::string _expression;

    public:
    RPN(std::string expression);
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    void processExpression();
};

#endif