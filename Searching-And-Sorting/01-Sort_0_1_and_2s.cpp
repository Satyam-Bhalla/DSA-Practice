/*
    Question URL - https://leetcode.com/problems/sort-colors/
    Question -  Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
                We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    Testcases:- 
        Example 1:
            Input: nums = [2,0,2,1,1,0]
            Output: [0,0,1,1,2,2]
        Example 2:
            Input: nums = [2,0,1]
            Output: [0,1,2]
    Solution Explanation:-  If we encounter a 0, we know that it will be on the low end of the array, and if we encounter a 2, we know it will be on the high end of the array.
                            To achieve this in one pass without preprocessing (counting), we simply traverse the unknown will generating the low and high ends.
                            Take this example:
                            Assume our input is: 1 0 2 2 1 0 (short for simplicity).
                            Running the algorithm by hand would look something like:
                                1 0 2 2 1 0
                                ^         ^
                                L         H
                                M

                                Mid != 0 || 2
                                Mid++

                                1 0 2 2 1 0
                                ^ ^       ^
                                L M       H

                                Mid == 0
                                Swap Low and Mid
                                Mid++
                                Low++

                                0 1 2 2 1 0
                                ^ ^     ^
                                L M     H

                                Mid == 2
                                Swap High and Mid
                                High--

                                0 1 0 2 1 2
                                ^ ^   ^
                                L M   H

                                Mid == 0
                                Swap Low and Mid
                                Mid++
                                Low++

                                0 0 1 2 1 2
                                    ^ ^ ^
                                    L M H

                                Mid == 2
                                Swap High and Mid
                                High--

                                0 0 1 1 2 2
                                    ^ ^
                                    L M
                                    H

                                Mid <= High is our exit case
*/

#include <bits/stdc++.h>
#include "../utils/vector.h"
using namespace std;

/*Function to put all 0s on left and all 1s on right*/

void sort012(vector<int> &nums, int n){
    int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high){
        if (nums[mid] == 0){
            tmp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = tmp;
            low++;
            mid++;
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else if (nums[mid] == 2){
            tmp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = tmp;
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {0, 2, 0, 1, 2, 2, 1};
    int n = nums.size() - 1;

    sort012(nums, n);
    printVector(nums);

    return 0;
}