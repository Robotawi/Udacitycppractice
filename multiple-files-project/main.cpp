#include <iostream>
#include <vector>
#include "addone.h"
#include "incrementandsum.h"
void printvector(std::vector<int> &vectorofint){
    for (auto &i : vectorofint){
        // v is a reference to a vector
        // &i
      std::cout<< i <<", ";
    }
}
//addone only
/*int main() {
    //std::cout << "Hello, Worldy!!" << std::endl;
    //return 0;

    std::vector<int> v{1, 2, 3, 4};
    addone(v);
//    addone(v);
//    addone(v);
    printvector(v);
    std::cout<< "\n";
}
 */
int main() {
    //std::cout << "Hello, Worldy!!" << std::endl;
    //return 0;

    std::vector<int> v{1, 2, 3, 4};
    auto summy = addoneincrement(v);
    std::cout<< "Sum is "<<summy<<"\n";
}

//The h files are included, but the cpp files are given to compiler
//The h files guides the compiler to the cpp files

