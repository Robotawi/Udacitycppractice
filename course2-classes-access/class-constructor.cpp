#include <iostream>
#include <cassert>

// Test in main
class Date{
public:
    Date(){}; //default constructor

    Date(int d, int m, int y){
        Day(d);
        Month(m);
        Year(y);
    }
    void Day(int d){
        if (d >=1 && d <= 31) day = d;
    }
    void Month(int m){
        if (m >=1 && m <= 12){month = m;}
    }
    void Year(int y){
        if (y >=1 && y <= 3000){year = y;}
    }

    int Day(){ return day;}
    int Month(){ return  month;}
    int Year(){ return year;}

private:
    int day{0};
    int month{0};
    int year{0};
};

int main()
{
    Date date;
    date.Day(-1);
    date.Month(14);
    date.Year(2000);
    assert(date.Day() != -1);
    assert(date.Month() != 14);
    assert(date.Year() == 2000);
    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";

    //initialize with braces
    Date date2(6,3,2010);
    std::cout << date2.Day() << "/" << date2.Month() << "/" << date2.Year() << "\n";
    //initialize with parentheses
    Date date3{6,3,2010};
    std::cout << date3.Day() << "/" << date3.Month() << "/" << date3.Year() << "\n";
}
