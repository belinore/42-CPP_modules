#include <iostream>

void hello() 
{    
    std::cout << "Hello\n";
}

void (*f_ptr)() = &hello;

int main (void)
{
    f_ptr();
}
