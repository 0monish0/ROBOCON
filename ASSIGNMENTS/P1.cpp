// Input a number and print how many times each digit (0–9) appears.
//author-monish
#include <iostream>
#include <string>
using namespace std;
int main(){
    string n;
    cout <<"Enter the number:";
    cin >> n;
    int a[10]={0};

    for(int i=0;i<n.length();i++){
        a[n[i]-'0']++;
    }
    for(int i =0;i<10;i++){
        if(a[i]>0){
            cout << i << " has appeared " << a[i] << " times" << endl;
        }
    }
}
