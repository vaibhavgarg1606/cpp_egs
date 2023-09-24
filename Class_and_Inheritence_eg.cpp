#include <iostream>


class A{
public:
    int a, b;
private:
    int c, d;
};


class B : public virtual A {
    
public:

    void x(char *s = "inkowns"){

    }

};


class C : public virtual A{

};


class D : public B, public C {

};


void main(){

    A a;
    B b;
    C c;
    D d;

    b.x("aksjdh");

    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(c) << std::endl;
    std::cout << sizeof(d) << std::endl;

}


