#include <iostream>

/* MACRO to print */
#define LOG(s, x) std::cout << s << x << std::endl

void print_Heading(char* s = ""){
    std::cout << "-------------------------------------------------------" << s << "-------------------------------------------------------" << std::endl; 
}


class BaseClass{

public:

    int pub_var1 = 10, pub_var2 = 12;


    BaseClass(int a = 0, int b = 0, int c = 0, int d = 0 ){
        m_var1 = a, m_var2 = b;
        protected_var1 = c, protected_var2 = d;
        LOG("\nBaseClass's Constructor invoked", ".");
    }


    void public_func1(char *s = "unknown"){
        LOG("\nFunction public_func1() in BaseClass called from ", s);
        private_func1();
    }

    void print_values_1(){
        LOG("private varable 1 = ", m_var1);
        LOG("private varable 2 = ", m_var2);
    }

    void print_values_2(){
        LOG("protected varable 1 = ", protected_var1);
        LOG("protected varable 2 = ", protected_var2);
    }

protected:
    int protected_var1, protected_var2;


    void protected_func1(char *s = "unknown"){
        LOG("\nFunction protected_func1() in BaseClass called from ", s);
    }

private:

    int m_var1, m_var2;

    void private_func1(){
        LOG("\nFunction private_func1() in BaseClass called", ".\n");
    }

};





/* --------------------------------------------------------------------------------------------------------------------------------------------------------

    Access Modifiers - like public, private and protected is added after colon(:) and before base class's name
    this modifier chnages the access modifier of base class's variable and fucntions    
    i.e it can change a variable that is public in base class to protected or private in derived class based on the modifier used.

    'Public' inheritance means that public members of the base class are also public in the derived class, and protected members are also protected.
    
    In the case of 'protected' inheritance (with the word protected in the heading of the definition), both public and protected members of the base 
    class become protected in the derived class.
    
    Finally, for 'private' inheritance, both public and protected members of the base class become private in the derived class. 
    
    In all types of inheritance, private members of the base class are inaccessible to any of the derived classes.

---------------------------------------------------------------------------------------------------------------------------------------------------------- */

class Derived1Level1 : public virtual BaseClass{
public:

    /*  
        : BaseClass is used to run the base class's constructor function with the inputed value otherwise contructor function will run with default value
        we also doesnot take value for private variable but we can still pass their value in baseclass using contructor function.
        
        the private varible are not accesible in derived class but its still being allocated and therefore size of derived class will include private membe of base class.
        if private member are not allocated, all member functions of the base class that need these private variables would be broken.
        so, in conclusion private varible are being allocated and all the function of base class can use this variable but they are inaccessible to derived class  
    */
    Derived1Level1(int c,int d) : BaseClass(12, 21, c, d)
    {
        LOG("\nDerived1Level1's Constructor invoked", ".");
    }

    // overwriting baseclass's public_func1
    void public_func1(char *s = "unknown"){
        LOG("\nFunction public_func1() in Derived1Level1 called from ", s);
        
        // private_func1();         cannot access base class's private 'private_func1', so if we need to call private_func1 we need to re define it.
        protected_func2();          // replacement of private_func1 in baseclass , in this we changed it and defined it as protected method 
        
        // here we don't defined protected_func1 , but as 'protected_func1' is defined as protected in BaseClass we can still access it 
        protected_func1("Derived1Level1 - public_func1");
    }   


    // the protected varibale is still accessable in this class. so we can access those in this function
    // but if we try to overwrite "print_value_1" , we cannot access private variables m_var1 and m_var2 as they are not accessible in derived class
    void print_value_2(){
        LOG("protected varable 1 = ", protected_var1);
        LOG("protected varable 2 = ", protected_var2);
    }


    void public_func_Derived1Level1(){
        LOG("\nDerived1Level1's special public function invoked", ".");
    }



protected:


    void protected_func2(){
        LOG("\nFunction protected_func2() in Derived1Level1 called", ".\n");
    }


private:


};


class Derived2Level1 : public virtual BaseClass{
public:
    Derived2Level1(int c = 0,int d = 0) : BaseClass(12, 21, c, d)
    {
        LOG("\nDerived2Level1's Constructor invoked", ".");
    }

    /* OverWriting BaseClass's pub_ */
    void public_func1(char *s = "unknown"){
        LOG("\nFunction public_func1() in Derived2Level1 called from ", s);
        // can access BaseClass's protected function
        BaseClass::protected_func1("Derived2Level1");

        // cannot access BaseClass's private function
        /* private_func1();        ~ result in error */

        // Invoking overWritten protected function
        protected_func1("Derived2Level1");
        // Derived2Level1::protected_func1("Derived2Level1");       similar to above statement
    }

    void public_func_Derived2Level1(){
        LOG("\nDerived2Level1's special public function invoked", ".");
    }


protected:
    void protected_func1(char *s = "unknown"){
        LOG("\nFunction protected_func1() in DerivedClass called from ", s);
    }

};



/*
    DerivedLevel2 is defined as a class derived from both Derived1Level1 and Derived2Level1, inheriting in this way all the member functions of Derived1Level1 and Derived2Level1.
    However, DerivedLevel2 also inherits the same member functions from BaseClass twice because both classes used in the definition of DerivedLevel2 are derived from BaseClass. 
    This is redundant at best, and at worst can cause a compilation error, like " 'member is ambiguous BaseClass::protected_func1() and BaseClass::protected_func1().' "
    It seem like they are both same function but compiler treat the baseclass's function inherited from Derivaed1Level1 and Derivaed2Level1 as 2 different fucntion and as they both have same function signature,
    it lead to compilation error.

    To prevent this from happening, the definitions of the two classes include the modifier 'virtual', which means that DerivedLevel2 contains only one copy of each member function from BaseClass.
    this help in preventing compilation error and also in saving memory by not declaring extra member.


    In this we have inherited Derived1Level1 as public and Derived2Level1 as protected meaning all function in Derived1Level1 is treated as they are in Derived1Level1,
    but public function and member in Derived2Level1 will become protected , i.e cannot be used outside class defination or in inherited class.
    we can also inherit from both class as public but , i have listed one as protected to show an example.
*/

class DerivedLevel2 : public Derived1Level1 , protected Derived2Level1{

public:

    DerivedLevel2(int c,int d) : Derived1Level1(c, d)
    {
        LOG("\nDerivedLevel2's Constructor invoked", ".");
    }

    void public_func1(char *s = "unknown"){
        LOG("\nFunction public_func1() in DerivedLevel2 called from ", s);

        Derived1Level1::protected_func2();

        // It will invoke protected_func1 defined in BaseClass  
        BaseClass::protected_func1("DerivedLevel2");

        // while this will invoke protected_func1 defined in Derived2Level1  
        Derived2Level1::protected_func1("DerivedLevel2");

    }   



};


int main(){

    print_Heading(" * BaseClass * ");
    BaseClass bs(13, 43, 11, 21);
    bs.public_func1("bs - Baseclass Instance-1");
    bs.print_values_1();
    bs.print_values_2();
    LOG("", sizeof(bs));
    print_Heading("--------------");
    
    print_Heading(" * Derived1Level1 * ");
    Derived1Level1 d1l1(100, 200);
    d1l1.public_func1("d1l1 - Derived1Level1 Instance-1");
    d1l1.print_values_1();
    d1l1.print_values_2();
    d1l1.public_func_Derived1Level1();
    LOG("", sizeof(d1l1));
    print_Heading("--------------");

    print_Heading(" * Derived2Level1 * ");
    Derived2Level1 d2l1(1, 2);
    d2l1.public_func1("d2l1 - Derived2Level1 Instance-1");
    d2l1.public_func_Derived2Level1();
    LOG("", sizeof(d2l1));
    print_Heading("--------------");

    print_Heading(" * DerivedLevel2 * ");
    DerivedLevel2 dl2(12, 39);
    dl2.public_func1("dl2 - DerivedLevel2 Instance-1");
    /*
        by making Derived1Level1 public and Derived2Level1 as protected, we can access public method of Derived1Level1 here
        but we cannot access public method of Derived2Level1 , as it become protected function in DerivedLevel1

    */
    dl2.public_func_Derived1Level1();
    // dl2.public_func_Derived2Level1();
    
    LOG("", sizeof(dl2));
    print_Heading("--------------");

}