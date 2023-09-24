#include <iostream>
#include <conio.h>


class Shape
{
    int a, b;
public:

    Shape(int _length, int _width)
    {
        a = _length;
        b = _width;

        // std::cout << "length is: " << _length << " width is: " << _width << std::endl;
        std::cout << "length is: " << a << " width is: " << b << std::endl;
    }

    void area()
    {
        std::cout << "Area is: " << a * b << std::endl;
    }
};




int main()
{    
    Shape square(8,8);
    Shape rectangle(10,32);

    square.area();
    rectangle.area();

    _getch();
    return 0;
}
