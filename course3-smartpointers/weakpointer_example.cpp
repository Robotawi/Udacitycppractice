//
// Created by zozo on 1/19/20.
//

#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> mySharedPtr1(new int);
    std::cout << "shared pointer count = " << mySharedPtr1.use_count() << std::endl;
    std::shared_ptr<int> mySharedPtr2(mySharedPtr1);
    std::cout << "shared pointer count = " << mySharedPtr2.use_count() << std::endl;

    std::weak_ptr<int> myWeakPtr1(mySharedPtr1);
    std::weak_ptr<int> myWeakPtr2(myWeakPtr1);
    std::cout << "shared pointer count = " << mySharedPtr2.use_count() << std::endl;

    std::shared_ptr<int> mySharedPtr3(mySharedPtr2);
    std::cout << "shared pointer count = " << mySharedPtr2.use_count() << std::endl;
    std::cout << "shared pointer count = " << mySharedPtr3.use_count() << std::endl;
    // std::weak_ptr<int> myWeakPtr3(new int); // COMPILE ERROR

    return 0;
}