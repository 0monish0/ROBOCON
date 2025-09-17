// 2. Code to print if a number is perfect number or not. A number is perfect if the sum of its divisors (excluding itself) equals the number.
// Example: 28 = 1 + 2 + 4 + 7 + 14.
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number";
    cin >>n;
    int sum =0;
    for(int i =1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    cout<<"The sum of divisors is:"<<sum<<endl;
    if(sum==n){
        cout<<"Its a perfect number";
    }
    else{
        cout<<"Its not a perfect number";
    }
}
