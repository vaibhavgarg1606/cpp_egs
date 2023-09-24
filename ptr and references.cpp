#include <iostream>

#define Log(x) std::cout << x << std::endl


void Increment_ptr(int* value){
    (*value)++;
    Log(value);
}

void Increment_ref(int& value){
    value++;
    Log(&value);
}


int main()
{
    int a = 5;
    Increment_ptr(&a);
    Log("\nPointer");
    Log(a);
    Increment_ref(a);
    Log("\nReference");
    Log(a);

    Log("\nMemory Address of a");
    Log(&a);

    std::cin.get();

}



