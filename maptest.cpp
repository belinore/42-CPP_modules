#include <map>
#include <iostream>
#include <string>

int main()
{
    std::map<std::string, int> m;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;

    std::cout << "Map contents:\n";
    for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << it->first << ": " << it->second << "\n";
    }

     return (0);

}