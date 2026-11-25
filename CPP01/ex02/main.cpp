#include <iostream>
#include <string>

int main(void)
{
    std::string str_var = "HI THIS IS BRAIN";
    std::string *stringPTR = &str_var;
    std::string &stringREF = str_var;

    std::cout << "stringVAR: " << &str_var << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl;
    std::cout << "stringVAR: " << str_var << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
}

	// std::cout << "stringVAR - contents: " << str_var << " ptr: " << &str_var << std::endl;
    // std::cout << "stringPTR - contents: " << stringPTR << " ptr: " << &stringPTR << std::endl;
    // std::cout << "stringREF - contents: " << stringREF << " ptr: " << &stringREF << std::endl;