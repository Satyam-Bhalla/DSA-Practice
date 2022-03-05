/* 
    Question URL - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    Question - Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
               If target is not found in the array, return [-1, -1].
               You must write an algorithm with O(log n) runtime complexity.
    Testcases:-
        Example 1:
            Input: nums = [5,7,7,8,8,10], target = 8
            Output: [3,4]
        Example 2:
            Input: nums = [5,7,7,8,8,10], target = 6
            Output: [-1,-1]
        Example 3:
            Input: nums = [], target = 0
            Output: [-1,-1]
*/

#include <bits/stdc++.h>
#include "../utils/vector.h"

using namespace std;

int findBound(vector<int> nums, int n, int target, bool isFirst){
    int begin = 0, end = n - 1;

    while (begin <= end)
    {

        int mid = (begin + end) / 2;

        if (nums[mid] == target)
        {

            if (isFirst)
            {

                // This means we found our lower bound.
                if (mid == begin || nums[mid - 1] != target)
                {
                    return mid;
                }

                // Search on the left side for the bound.
                end = mid - 1;
            }
            else
            {

                // This means we found our upper bound.
                if (mid == end || nums[mid + 1] != target)
                {
                    return mid;
                }

                // Search on the right side for the bound.
                begin = mid + 1;
            }
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int n, int target){
    int firstOccurrence = findBound(nums, n, target, true);

    if (firstOccurrence == -1)
    {
        vector<int> v = {-1, -1};
        return v;
    }

    int lastOccurrence = findBound(nums, n, target, false);
    vector<int> v = {firstOccurrence, lastOccurrence};
    return v;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 1};
    int n = nums.size();
    int target = 2;
    vector<int> v = searchRange(nums, n, target);
    printVector(v);
    return 0;
}