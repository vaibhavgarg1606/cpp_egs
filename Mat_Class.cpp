#include <iostream>



template<class genType>
class Mat{

private:
    int rows, cols;
    genType **m_Data;

public:

    Mat(genType **data){
        m_Data = data;
    }

    Mat(){
    }

    void Input_Mat(){

        std::cout << "\nEnter the no of rows and columns of Matrix: " << std::endl;
        std::cin >> rows >> cols;

        free(m_Data);
        m_Data = (genType**) malloc(rows *  sizeof(genType*));
        
        for(int i = 0; i < rows; i++) 
            m_Data[i] = (genType*) malloc(cols * sizeof(genType));



        std::cout << "\nEnter the elements of Matrix: " << std::endl;

        for(int i = 0; i < rows ; i++){
            for(int j = 0; j < rows ; j++){
                std::cin >> m_Data[i][j];
            }
        }
    }

    void Print_Mat(){
        std::cout << "\nMatrix: " << std::endl;

        for(int i = 0; i < rows ; i++){
            for(int j = 0; j < cols ; j++){
                std::cout << m_Data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

};


int main(){


    Mat<int> mat1;
    mat1.Input_Mat();
    mat1.Print_Mat();

}