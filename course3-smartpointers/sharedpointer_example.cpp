//
// Created by zozo on 1/19/20.
//

#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shared1(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
    }

    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    return 0;
}