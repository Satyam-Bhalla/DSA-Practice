/*
    https://leetcode.com/problems/product-of-array-except-self/
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

    

    Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
    Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
*/

#include <bits/stdc++.h>
using namespace std;

// O(n) time and O(n) space
vector<int> productArrayExceptSelfOptimized(vector<int> &nums){
    int n = nums.size();
    vector<int> result(n,1);
    int left = 1;
    for(int i=0;i<n;i++){
        result[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for(int i=n-1;i>=0;i--){
        result[i] *= right;
        right *= nums[i];
    }
    return result;
}
vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> ans(length,1);
        vector<int> prefix(length,1);
        vector<int> suffix(length,1);
        
        prefix[0] = 1;
        for(int i=1;i<length;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        
        suffix[length-1]=1;
        for(int i=length-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        
        for(int i=0;i<length;i++){
            ans[i] = prefix[i]*suffix[i]; 
        }
        return ans;
        
    }

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = productArrayExceptSelfOptimized(nums);
    vector<int> result2 = productExceptSelf(nums);
    for(int i=0;i<result2.size();i++){
        cout << result2[i] << ",";
    }
    cout << endl;

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}