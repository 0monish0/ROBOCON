// 4. Input a number and print its prime factors.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Prime factors of " << n << " are: ";
    bool f=false;
    
    while (n % 2 == 0) {
        f=true;
        n = n / 2;
    }
    if(f==true)
    cout<<2<<" ";
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 2) {
        cout << n;
    }
    return 0;
}
