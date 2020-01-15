//
// Created by zozo on 1/15/20.
//

class Class1
{
private:
    //copy and assignment constructors made private
    Class1(const Class1 &);
    Class1 &operator=(const Class1 &);

public:
    Class1(){};
};

class Class2
{
public:
    Class2(){}
    //copy and assignment constructors made public, but deleted
    Class2(const Class2 &) = delete;
    Class2 &operator=(const Class2 &) = delete;
};

int main()
{
//    Class1 original1;
//    Class1 copy1a(original1); // copy c’tor
//    Class1 copy1b = original1; // assigment operator

    Class2 original2;
    Class2 copy2a(original2); // copy c’tor
    Class2 copy2b = original2; // assigment operator

    return 0;
}