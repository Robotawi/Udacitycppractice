//
// Created by zozo on 1/21/20.
//

#include <vector>
#include <iostream>

using namespace std;
int main(){
    std::vector<int> vect;

    for (int i = 0; i < 10; i++){
        vect.push_back(i);
    }
    cout << "vector size is "<< vect.size() <<endl;
    for (int i = 0 ; i < vect.size() ; i++){
        std::cout << vect.at(i) << std::endl;
    }

    vect.resize(13);
    cout << "vector size is "<< vect.size() <<endl;
    for (int i = 0 ; i < vect.size() ; i++){
        std::cout << vect.at(i) << std::endl;
    }

    cout << "Printing vector elements using iterators " <<endl;
    for (auto i = vect.rbegin(); i != vect.rend(); i++){
        std::cout << *i << std::endl;
    }
    cout<< "Vector size is "<< vect.size() << endl;

    cout<< "Vector max size is "<< vect.max_size() << endl;

    cout<< "Vector capacity is "<< vect.capacity() << endl;

    vect.insert(vect.begin()+3,51);

    cout << "Printing vector elements using iterators after inverting (4,51)" <<endl;
    for (auto i = vect.begin(); i != vect.end(); i++){
        std::cout << *i << std::endl;
    }

//    vect.clear();
//    cout<< "Vector size after clear is "<< vect.size() << endl;
//    cout<< "Vector shrink to fit size of 7 " << endl;
//    vect.shrink_to_fit(7);
//    cout << "Printing vector elements using iterators " <<endl;
//    for (auto i = vect.begin(); i != vect.end(); i++){
//        std::cout << *i << std::endl;
//    }
    return 0;


}