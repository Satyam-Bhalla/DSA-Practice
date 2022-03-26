/*
    Given an integer n, return any array containing n unique integers such that they add up to 0.

    Example 1:
    Input: n = 5
    Output: [-7,-1,1,3,4]
    Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

    Example 2:
    Input: n = 3
    Output: [-1,0,1]
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> sumZero(int n) {
    vector<int> A(n);
    // for (int i = 0; i < n; ++i)
    //     A[i] = i * 2 - n + 1;
    // return A;
    
    int l = 0, r = A.size() - 1;
    while (l < r) {
        A[l] = r;
        A[r] = -r;
        l++; r--;
    }
    return A;
}

int main(){
    int n = 5;
    vector<int> A = sumZero(n);
    for (int i = 0; i < A.size(); ++i)
        cout << A[i] << " ";
    return 0;
}