#include <iostream>
#include <cassert>

// Test in main
class Date{
public:
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
}
