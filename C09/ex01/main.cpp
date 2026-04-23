/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:39:19 by belinore          #+#    #+#             */
/*   Updated: 2026/04/23 20:06:51 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: expected usage ./RPN <expression>\n";
        return (1);
    }
    try
    {
        RPN reverse_polish_notation(argv[1]);
        reverse_polish_notation.processExpression();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return (0);
}
