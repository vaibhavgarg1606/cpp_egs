#include <iostream>

#define CONVERT(var) convert(#var)

char* convert( char* name )
{
    return name;
}

int main()
{
    int dumbass = 12;
    char* vai = "vaibhav";
    char* name = CONVERT(dumbass);
    std::cout << name << "\t" << typeid(name).name() << std::endl;
    std::cout << vai << "\t" << typeid(vai).name() << std::endl;
}