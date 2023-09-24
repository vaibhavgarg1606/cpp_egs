#include <iostream>


class C {

// elements and functions accessible anywhere                                                   ~ i.e can be accessed anywhere with class instance
public:
    int X, Y;


    /*  Constructor fucntion of class which is called when a class instance is initialized
        eg.  C x(12, 32 , "instance_1"); 
        in above eg during initialization 'CONSTRUCTOR' fucntion 'C' is called with value x = 12, y= 32 and name = "instance_1"
        syntax for CONSTRUCTOR func :   
            class_name (arg_list){
            }
    */
    C(int x = 0, int y = 0, char *name = ""){
        strcpy(m_Name, name);
        m_x = x;
        m_y = y;
    }


    /*  A Destructor is a function that is automatically invoked when an object is destroyed,
        which takes place upon exit from the block in which the object is defined or upon the call of delete.
        Destructors take no arguments and return no values so that there can be only one destructor per class.
        syntax:
            ~class_name (){
            }
    */
    ~C(){
        std::cout << "Destructor function invoked." << std::endl;
    }


    void publicFunc1(){
        std::cout << "Function 1 of Object " << m_Name << " called." << std::endl;
    }


    
    void publicFunc2(int x, int y){
        m_x = x, m_y = y;
        std::cout << "value of x and y changed in object " << m_Name << " to " << m_x << " and " << m_y<< std::endl;
    }


// elements and functions accessible only in the object inside                                  ~ i.e can be accessed only in the functions in this class
private:
    int m_x, m_y;
    char m_Name[20];


// elements and functions accessible only in the object inside or in inherited class            ~ i.e can be accessed only in the functions in this class or in inherited class
protected:


};



int main(){

    C c1(10, 20, "instance_1");         // CONSTRUCTOR FUNCTION invoked
    c1.publicFunc1();
    c1.publicFunc2(15, 25);

    c1.X = 12, c1.Y = 23;

    std::cout << c1.X << " and " << c1.Y << std::endl;

}   // DESCTRUCTOR FUNCTION invoked