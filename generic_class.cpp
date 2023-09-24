#include <iostream>
#include <math.h>

#define LOG(s, x) std::cout << s << x << std::endl



/*  with the help of generic class we can take data type as input and initialize methods and variable with specified data type 
    it helps in Code Reusability as we can use same class for different data type (i.e int float double etc).

    if not for generic class we have to define class for all the datatype we need to use, with the help of generic this task can be done easily by onlu defining class once
*/
template<class genType>
class Vector2{

private:
    genType m_x, m_y;


public: 
    Vector2(genType x, genType y){
        m_x = x, m_y = y;
    }

    Vector2(){
        m_x = 0.f, m_y = 0.f;
    }

    genType GetLength(){
        return sqrt(m_x * m_x + m_y * m_y);
    }

    Vector2<genType> Normalized(){
        genType l = GetLength();
        return Vector2<genType>(m_x/l, m_x/l);
    }

    void Normalize(){
        genType l = GetLength();
        m_x /= l;
        m_y /= l;
    }




    /*  Operator overloading function are function which overload basic operator for an object
        When defining the operator, you write a function where the function name is operatorx and x is the operator symbol (note that there is no space)
    */
    Vector2 operator+(Vector2 const& other){
        Vector2 res;

        res.m_x = m_x + other.m_x;
        res.m_y = m_y + other.m_y;
        return res;
    }

    void operator+=(const Vector2& other){

        m_x += other.m_x;
        m_y += other.m_y;

    }

    /*  the std::cout << operator can only be overloaded by defining it outside the class scope as it take class instance as a argument
        therefore to access all the operator in a class we define this function as 'friend', which enable it to access all private, public or protected variable
    */
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v);


    void print(){
        std::cout << "X = " << m_x << " and Y = " << m_y << std::endl;
    }

};




/* ----------------------------------------------------------- * CODE TO BE REFACTORED * -----------------------------------------------------------------
    in this the datatype of argument v should be Vector2<genType>, it need to be updated to solve this issue
    currently harcoded type as 'float' , can lead to error with other datatypes
---------------------------------------------------------------------------------------------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream& os, const Vector2<float>& v){
        os << "x = " << v.m_x << " and y = " << v.m_y ;
        return os;
}


void main(){

    Vector2<float> v1(3.f, 4.0f);
    LOG("length of vector v1 = ", v1.GetLength());

    v1.print();

    Vector2<float> v2(2.f, 6.0f);

    v1 += v2;


    std::cout << v1 << std::endl ;

}