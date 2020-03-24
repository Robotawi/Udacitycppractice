//
// Created by zozo on 1/17/20.
//

//
// Created by zozo on 1/16/20.
//

#include <stdlib.h>
#include <iostream>

class MyContainer{
private:
    int _size{0};
    int *_ptr=nullptr;

public:
    MyContainer(int size){
        _size = size;
        _ptr = new int[_size];
        std::cout << "The container constructor is called, new object at address "<< this <<", and resource at "<< _ptr << ". Its size is "<< _size*
                                                                                                                                              sizeof(int)/1000.0/1024.0<<" Megabytes."<<std::endl;
    }
    ~MyContainer(){
        delete [] _ptr;
        std::cout << "The container destructor is called " << std::endl;
    }
    //copy constructor
    MyContainer(const MyContainer& source){
        _size = source._size;
        _ptr = new int[_size];
        *_ptr = *source._ptr;
        std::cout << "The container **copy** constructor is called, new object at address "<< this <<", and resource at "<< _ptr << ". The copy size is "<< _size*
                                                                                                                                                       sizeof(int)/1000.0/1024.0<<" Megabytes."<<std::endl;
    }
    //copy assignment constructor
    MyContainer& operator=(const MyContainer& source){
        _size = source._size;
        _ptr = new int[_size];
        *_ptr = *source._ptr;
        std::cout << "The container **copy assignment operator**  is called, new object at address "<< this <<", and resource at "<< _ptr << ". The copy size is "<< _size*
                                                                                                                                                                sizeof(int)/1000.0/1024.0<<" Megabytes."<<std::endl;
        return *this;
    }
    //move constructor
    MyContainer(MyContainer&& source){
        _size = source._size;
        _ptr = source._ptr;

        source._size = 0;
        source._ptr = nullptr;
        std::cout << "The container **move** constructor is called, new object at address "<< this <<", and resource at "<< _ptr <<". No copying of the resources is done."<< std::endl;
    }
    //copy assignment operator
    MyContainer& operator=(MyContainer&& source){
        _size = source._size;
        _ptr = source._ptr;

        source._size = 0;
        source._ptr = nullptr;
        std::cout << "The container **move assignment operator** is called, new object at address "<< this <<", and resource at "<< _ptr <<". No copying of the resources is done."<< std::endl;
    }

};

void useMyContainer(MyContainer mycon){
    std::cout << "I got the container to use, check the copying needed to arrive at this point "<< std::endl;
}

int main(){
    MyContainer container1(1000000);
//    MyContainer container2(std::move(container1));
//    MyContainer container3(2500000);
//    container3 = std::move(container2);
    useMyContainer(std::move(container1));
}