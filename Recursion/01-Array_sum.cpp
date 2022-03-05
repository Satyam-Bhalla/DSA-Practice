#include <iostream>

using namespace std;
int find_sum(int arr[], int n)
{
    if(n==0){
        return arr[0];
    }
    return arr[n]+find_sum(arr,n-1);
}


int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << find_sum(arr, n-1) << endl;
    return 0;
}