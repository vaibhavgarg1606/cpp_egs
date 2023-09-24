#pragma once


#ifndef _HEADER_FILES_      // check if given symbol is defined or not if not defined proceed further else skip to 'else' statement of endif
#define _HEADER_FILES_      
// Usecd to include header files only once 

#include <iostream>     // Include cout and cin functions       # is a preprocessor symbol

#endif   /* _HEADER_FILES_ */

#define CONST_NUMBER 102        // #define is used to define a constant


#ifdef DEBUG                  // tells preprocessor to look for DEBUG symbol   if defined rest of code b/w efndef and else will be compiled
#define MESSAGE(str)    std::cout << "\nDEGUG\n" << str << std::endl;      // it is a macro which is preprocessor 

#else
#define MESSAGE(str)    std::cout << "\nYOUR ARE NOT IN DEBUG MODE\n"     
// does nothing     i.e wherever there is MESSAGE macro will be Compiled with this defination is DEBUG is not defined

#endif                       


int main()
{
    MESSAGE("Hello World!!");
}
