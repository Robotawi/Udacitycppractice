#include <iostream>
using namespace std;

class Heart{
private:
    int rate{80};
    friend class Human;

};

class Human{
private:
    Heart heart;
public:
    void Exercise(){heart.rate = 130;}
    void Sleep(){heart.rate = 65;}
    int HeartRate(){return heart.rate;}
};


int main(){
    Human myself;
    cout<<"Standard HR "<< myself.HeartRate();
    myself.Sleep();
    cout<<", after sleeping HR "<< myself.HeartRate();
    myself.Exercise();
    cout<<", after exercise HR "<< myself.HeartRate()<<" \n";
    return 0;
}