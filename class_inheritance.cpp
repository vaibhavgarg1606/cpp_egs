#include <iostream>
#include <conio.h>


class Shape
{
protected:
    float a, b;
public:

    void setValues(float _length, float _width)
    {
        a = _length;
        b = _width;

        // std::cout << "length is: " << _length << " width is: " << _width << std::endl;
        std::cout << "length is: " << a << " width is: " << b << std::endl;
    }

    void setValues(float _a)
    {
        a = _a;
        std::cout << "radius is: " << a << std::endl;
    }

    void area()
    {
        std::cout << "Area is: " << a * b << std::endl;
    }
};


class Triangle : public Shape
{
public:
    void area()
    {
        std::cout << "Area of triangle is: " << 0.5f * a * b << std::endl;   
    }
};

class Circle : public Shape
{
public:
    void area()
    {
        std::cout << "Area of circle is: " << 3.14f * a * a << std::endl;   
    }
};



int main()
{    
    Shape rectangle;
    rectangle.setValues(0.8f, 12.0f);
    rectangle.area();

    Triangle tri;
    tri.setValues(3.0f, 23.0f);
    tri.area();

    Circle c;
    c.setValues(5.0f);
    c.area();


    _getch();
    return 0;
}
