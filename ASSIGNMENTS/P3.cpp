// Check whether an array contains duplicate values.
#include <iostream>
using namespace std;
int main() {
    int arr[5];
    cout<<"Enter the numbers:";
    for(int i = 0; i<5;i++){
        cin >> arr[i];
    }
    int c =0;
    for(int i =0;i<5;i++){
        for(int j = i+1;j<5;j++){
            if(arr[i]==arr[j]){
                cout<<"The array contains duplicate values";
                return 0;
            }
        }
    }
    cout<<"The array does not contain duplicate values";
}
