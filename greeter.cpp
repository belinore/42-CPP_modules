#include <iostream>
#include <string>

class Greeter
{
public:
    Greeter(const std::string& name) : _name(name) {}
    void greet() const
    {
        if (_lastName.empty())
            std::cout << "Hello, " << _name << "!" << std::endl;
        else
            std::cout << "Hello, " << _name << " " << _lastName << "!" << std::endl;
    }
    void setName(const std::string& name)
    {
        _name = name;
    }
    void setLastName(const std::string& lastName)
    {
        _lastName = lastName;
    }
    void goodbye();
private:
    std::string _name;
    std::string _lastName;
};

void    Greeter::goodbye()
{
    if (_lastName.empty())
        std::cout << "Goodbye " << _name << std::endl;
    else
        std::cout << "Goodbye " << _name << " " << _lastName << std::endl;
}

int main()
{
    Greeter g("Beth");
    Greeter b("Beeb");
    g.greet();
    b.greet();
    g.setName("Elinore");
    g.setLastName("Jones");
    g.greet();
    g.setLastName("Smith");
    g.goodbye();
    b.goodbye();
    return 0;
}
