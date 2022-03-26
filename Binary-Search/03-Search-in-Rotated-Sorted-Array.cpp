/*
    There is an integer array nums sorted in ascending order (with distinct values).

    Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

    You must write an algorithm with O(log n) runtime complexity.
    Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

    Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

    Example 3:
    Input: nums = [1], target = 0
    Output: -1
*/
#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& a, int key) {
    int lo = 0;
    int hi = a.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1; // avoid overflow, same as mid = (lo + hi) / 2

        if (a[mid] == key)
            return mid;

            // the bottom half is sorted
            if (a[lo] <= a[mid]) {
                if (a[lo] <= key && key < a[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } 
            // the upper half is sorted
            else {
                if (a[mid] < key && key <= a[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
    }
    return -1;
}

int main(){
    vector<int> a = {4,5,6,7,0,1,2};
    cout << search(a, 0) << endl;
    return 0;
}