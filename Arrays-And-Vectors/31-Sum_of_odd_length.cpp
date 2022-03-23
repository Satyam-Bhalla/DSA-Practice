/* 
    Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.
    A subarray is a contiguous subsequence of the array.
    Return the sum of all odd-length subarrays of arr.

    Example 1:
    Input: arr = [1,4,2,5,3]
    Output: 58
    Explanation: The odd-length subarrays of arr and their sums are:
    [1] = 1
    [4] = 4
    [2] = 2
    [5] = 5
    [3] = 3
    [1,4,2] = 7
    [4,2,5] = 11
    [2,5,3] = 10
    [1,4,2,5,3] = 15
    If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
    
    Example 2:
    Input: arr = [1,2]
    Output: 3
    Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
*/

/*
    Just see number of times every position occurs in all the odd length subarray.
    Multiply the contribution of position with element at that position.

    How to calculate contribution?
    Every element will contribute size of array to its right (n-i) * size of array to its left(i+1)
    Since here we only consider odd length divide it by two (ceil divison)


    Example 
    Given array: arr = [1, 2, 3, 4, 5] (n = 5) and formula (i + 1) * (n - i)
    i = 0, contribution = 1 * 5 = 5
    i = 1, contribution = 2 * 4 = 8
    i = 2, contribution = 3 * 3 = 9
    i = 3, contribution = 4 * 2 = 8
    i = 4, contribution = 5 * 1 = 5

*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0,n=arr.size(),i;
        for(i =0;i<n;i++)
		{
            int contribution = ceil((i+1)*(n-i)/2.0);
            ans+=(contribution*arr[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};
    Solution s;
    cout << s.sumOddLengthSubarrays(arr) << endl;
    return 0;
}