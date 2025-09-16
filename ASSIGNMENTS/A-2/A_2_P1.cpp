// Write a C++ program to create a class Robot with a default constructor that initializes the robot’s name to "Alpha" and battery level to 100.
//The class should have a member function performTask() that reduces the battery level by 10 and another function displayStatus() to print the robot’s name and battery.
//Include a destructor that prints a shutdown message when the robot object is destroyed.

#include <iostream>
using namespace std;
class robots{
    private:
    string name;
    int bl;
    public:
    robots(){
        name="Alpha";
        bl=100;
        cout<< "Robot "<<name<<" with batter life "<<bl<<"% is created"<<endl;
    }

    void performTask(){
        if(bl>10){
            bl-=10;
            cout<<"Task is Done ! Battery life is now at "<<bl<<"%"<<endl;
        }
        else{
            cout<<"Battery is below 10% please charge"<<endl;
        }
    }

    void displayStatus(){
        cout<<"Robot "<<name<<" is here with battery at "<<bl<<"%"<<endl;
    }

    ~robots(){
        cout<<"Robot "<<name<<" is being shutdowned and thus destroyed"<<endl;
    }
};

int main(){
    robots r;
    r.performTask();
    r.performTask();
    r.displayStatus();
    return 0;
}
