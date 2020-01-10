//take a vector, add one to each element, then sum all the elements
#include "addone.h"
#include <vector>
#include <iostream>

int addoneincrement(std::vector<int> &vec){
    int sum = 0;
    addone(vec);
    for (auto &i : vec){
        sum+=i;
    }
    std::cout<<"sum is "<< sum <<" \n";
    return sum;
}