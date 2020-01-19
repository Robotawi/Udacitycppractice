//
// Created by zozo on 1/19/20.
//

#include <iostream>
#include <memory>
#include <string>

class MyClass
{
private:
    std::string _text;

public:
    MyClass() {}
    MyClass(std::string text) { _text = text; }
    ~MyClass() { std::cout << _text << " destroyed" << std::endl; }
    void setText(std::string text) { _text = text; }
};

int main()
{
    // create unique pointer to proprietary class
    MyClass *ptr = new MyClass();

    std::unique_ptr<MyClass> myClassptr1(ptr);
    std::unique_ptr<MyClass> myClassptr2(new MyClass("String 2"));

    // call member function using ->
    myClassptr1->setText("String 1");

    // use the dereference operator *
    *myClassptr1 = *myClassptr2;

    // use the .get() function to retrieve a raw pointer to the object
    std::cout << "Objects have heap addresses " << myClassptr1.get() << " and " << myClassptr2.get() << std::endl;
    std::cout << "Objects have stack addresses " << &myClassptr1 << " and " << &myClassptr2 << std::endl;

    return 0;
}