/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:39:15 by belinore          #+#    #+#             */
/*   Updated: 2026/04/23 18:55:19 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <stack>
#include <sstream>

RPN::RPN(std::string expression) : _expression(expression)
{
    if (_expression.empty())
        throw std::invalid_argument("Expression cannot be empty");
}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _expression(other._expression) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _expression = other._expression;
    return (*this);
}

static void evaluate(std::stack<int> &numbers, char op)
{
    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();
    int result;
    switch (op)
    {
        case '+':
            result = a + b; break;
        case '-':
            result = a - b; break;
        case '*':
            result = a * b; break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Division by zero");
            result = a / b; break;
        default:
            throw std::invalid_argument("Invalid operator: " + std::string(1, op));
    }
    numbers.push(result);
}

void RPN::processExpression()
{
    std::stack<int> stack;
    std::stringstream ss(_expression);
    std::string token;
    while (ss >> token)
    {
        if (token.size() == 2 && token[0] == '-' && isdigit(token[1]))
            stack.push(-(token[1] - '0'));
        else if (token.size() != 1) 
            throw std::invalid_argument("Invalid token in expression: " + token);
        else if (isdigit(token[0]))
            stack.push(token[0] - '0');
        else if ((token == "+" || token == "-" || token == "*" || token == "/"))
        {
            if (stack.size() < 2)
                throw std::invalid_argument(
                    "Invalid expression format: expected at least two numbers before operator "
                    + token);
            evaluate(stack, token[0]);
        }
        else
            throw std::invalid_argument("Invalid token in expression: " + token);
    }
    if (stack.size() != 1)
        throw std::invalid_argument("Invalid expression format: expected one result only");
    std::cout << stack.top() << "\n";
}

//old char based implementation, replaced with stringstream for better token parsing and error handling
// void RPN::processExpression()
// {
//     std::cout << "Processing expression: " << _expression << "\n";
//     std::stack<int> stack;
//     for (size_t i = 0; i < _expression.size(); i++)
//     {
//         if (_expression[i] == ' ')
//             continue ;
//         if (_expression[i] >= '0' && _expression[i] <= '9')
//             stack.push(_expression[i] - '0');
//         else if (stack.size() > 1)
//             evaluate(stack, _expression[i]);
//         else
//             throw std::invalid_argument("Invalid expression format: expected at least two numbers before operator " + std::string(1, _expression[i]));
//         if (i + 1 < _expression.size() && _expression[i + 1] != ' ')
//             throw std::invalid_argument("Invalid expression format: expected space after token " + std::string(1, _expression[i]));
//     }
//     if (stack.size() != 1)
//         throw std::invalid_argument("Invalid expression format: expected exactly one result, got " + std::to_string(stack.size()));
//     std::cout << stack.top() << "\n";
// }