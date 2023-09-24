#include <iostream>
#include <string>


struct Vector3
{
    float x, y, z;

    // constructor runs after every initialization
    Vector3() : x(10), y(11), z(12) {}      // we can assign value this way in class and struct in here function block "{}" is empty but we have already assign the value 
};


int main()
{
    // STACK    
    /*  on Stack memory, memory is stacked on top of each other so memory of value will be near to array (as array is pointer and therfore is memory address) and array will be near to memory of vector
        can be check in VISUAL STUDIO by going in project -> WINDOW -> MEMORY -> MEMORY ADDRESS 1    and in there search the memory address

        in Stack memory is automatically alloted and also deleted after completion of its scope , for eg if in function after ending of func memory will be freed and deleted

        -> Fast as fuck boi
        -> one cpu instruction
        -> auto allocation and freeing of memory
    */
    int value = 5;
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    Vector3 vector;



    // HEAP
    /*  this can be assigned by new keywords or smart pointers  smart pointer uses new but also releases memeory after completion   but in new we need to do it mnaually
        both at core level uses mallocate (memeory allocate) which is a fucntion which helps in allocating memory and giving it back

        In Heap Memory is assigned manually therefore we need to delete or release it manually , if not it will released on end of program  or memory will be wasted without any usage 
        eg variable which should be ended after completion of scope will keep on existing and keep occuping memory without any usage, which result in memory leak and in large program (like game where we don't realse memory of a 3d program) it may lead to termination of appplication / game.

        -> it can be used for more lifetime or lifetime larger than ots scope
        -> can be used where memory in stack is not sufficient eg texture or 3d models
    */
    int* hvalue = new int;
    *hvalue = 5;
    int* harray = new int[5];
    harray[0] = 1;
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;
    Vector3* hvector = new Vector3();   // paranthesis optional

    // manually freeing memory / deletion of memory   --smart pointer will do it for us but for new we need to do it
    delete hvalue;
    delete[] harray;    // as it is array
    delete hvector;


    std::cin.get();
}
