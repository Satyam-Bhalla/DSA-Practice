#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int iterativeFactorial(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int main(){
    int a = 6402373705728000/131681894400;
    cout  << a << endl;

    cout << factorial(5) << endl;
    return 0;
}