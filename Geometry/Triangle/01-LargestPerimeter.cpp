/*
https://leetcode.com/problems/largest-perimeter-triangle/
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, 
formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, 
return 0.

    Example 1:

    Input: nums = [2,1,2]
    Output: 5
    Example 2:

    Input: nums = [1,2,1]
    Output: 0
*/
#include <bits/stdc++.h>

using namespace std;

int largestPerimeter(vector<int>& A) {
      sort(begin(A), end(A));
      for (int i = A.size() - 1; i >= 2; --i)
        if (A[i] < A[i - 1] + A[i - 2]) 
            return A[i] + A[i - 1] + A[i - 2];
      return 0;
    }
int main(){
    vector<int> A = {2,1,2};
    cout << largestPerimeter(A) << endl;
    return 0;
}
