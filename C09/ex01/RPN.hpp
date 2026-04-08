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