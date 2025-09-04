#include <iostream>

class Foo
{
    public:
    void greet()
    {
        std::cout << "Hello from Foo!\n";
    }
} ;

int main(void)
{
    void (Foo::*mbr_fptr)() = &Foo::greet;

    Foo obj;
    //obj.greet(); //no function ptr
    (obj.*mbr_fptr)();

}
