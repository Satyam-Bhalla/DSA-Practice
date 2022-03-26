/*
    Given an unsorted integer array nums, return the smallest missing positive integer.
    You must implement an algorithm that runs in O(n) time and uses constant extra space.
    
    Example 1:
    Input: nums = [1,2,0]
    Output: 3

    Example 2:
    Input: nums = [3,4,-1,1]
    Output: 2

    Example 3:
    Input: nums = [7,8,9,11,12]
    Output: 1
*/

#include <bits/stdc++.h>

using namespace std;

int firstMissingPositiveOptimised(vector<int>& A) {
    int n = A.size();
        for(int i = 0; i < n; ++ i)
        while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            swap(A[i], A[A[i] - 1]);
    for(int i = 0; i < n; ++ i)
        if(A[i] != i + 1)
            return i + 1;
    return n + 1;
}

int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> s;
    for(auto i:nums){
        if(i>0){
            s.insert(i);
        }
    }
    if(s.empty()){
        return 1;
    }
    int n = nums.size();
    int i;
    for(i=1;i<=n;i++){
        if(s.count(i)==0){
            return i;
        }
    }
    return i;
}

int main(){
    vector<int> nums = {1,2,0};
    cout << firstMissingPositive(nums) << endl;
    cout << firstMissingPositiveOptimised(nums) << endl;

    return 0;
}