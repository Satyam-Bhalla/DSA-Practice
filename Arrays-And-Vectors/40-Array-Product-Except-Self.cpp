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
#include<vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    int n = arr.size();
      // Base case
    if (n == 1) {
        return {0};
    }
 
    int i, temp = 1;
 
    vector<int> prod(n,1);
    /* In this loop, temp variable contains product of
       elements on left side excluding arr[i] */
    for (i = 0; i < n; i++) {
        prod[i] = temp;
        temp *= arr[i];
    }
 
    /* Initialize temp to 1
    for product on right side */
    temp = 1;
 
    /* In this loop, temp variable contains product of
       elements on right side excluding arr[i] */
    for (i = n - 1; i >= 0; i--) {
        prod[i] *= temp;
        temp *= arr[i];
    }
    return prod;
}