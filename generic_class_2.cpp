#include <iostream>


template<class genType, int size = 10>
class List{
private:
    genType storage[size];

public:

    List(genType* ptr){
        for (int i = 0; i < size; i++ )
            storage[i] = ptr[i];
    }   

    genType& operator[](int index){
        if(index >= size){
            std::cout << "Array index out of bound." << std::endl;
        }else
        return storage[index];
    }

    
    void print() const {
        for (int i = 0; i < size; i++)
            std::cout << storage[i] << " ";
        std::cout << std::endl;
    }

};




int main(){

    int a[] = {1, 2, 3, 4, 5, 7, 8, 9 ,8 ,1};
    List<int> l1(a);    // use the default size;
    l1.print();

    std::cout << l1[3] << std::endl;

    int b[] = {1, 2, 3, 4, 5};
    List<int, 5> l2(b);     // initializing using different size 
    l2.print();

    float c[] = {1.2f, 4.2f, 7.4f};
    List<float, 3> l3(c);       // initializing with float datatype and size = 3
    l3.print();


    std::cout << sizeof(l1) << " " << sizeof(l2) << " " << sizeof(l3) << " " << std::endl;


}