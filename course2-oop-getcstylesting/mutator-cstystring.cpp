#include <string>
#include <cstring>
#include <iostream>

class Car {
    private:
    int horsepower;
    int weight;
    std::string brand;
    public:
    void SetBrand(std::string s);
    void SetBrand(char *);
    std::string GetBrand();

};
//A std::string can be set to equal a c style string directly
void Car::SetBrand(std::string s){
    brand = s;
}

void Car::SetBrand(char* b){
    brand = b;
}

std::string Car::GetBrand(){return brand;}


// Test in main()
int main()
{
    Car car1;
    char brand1[] = "Peugeot";
    car1.SetBrand(brand1);
    std::cout << car1.GetBrand() << "\n";

    ///

    Car car2;
    std::string brand2 = "Toyota";
    car2.SetBrand(brand2);
    std::cout << car2.GetBrand() << "\n";
}