/*
    Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

    Example 1:
    Input: nums = [1,1,1], k = 2
    Output: 2

    Example 2:
    Input: nums = [1,2,3], k = 3
    Output: 2

*/


#include <bits/stdc++.h>

using namespace std;

/*
    Detailed Intuition With Example:
    While iterating through the array if we can store the prefixSum at each index in a HashMap 
    and at the same time check if a prefixSum exists for the current runningSum-k. we'll use use
    a HashMap to compute and store the prefix sums as Keys and the corresponding frequencies as 
    Values. We'll run through the example step by step -

    Input:
        nums = [3,9,-2,4,1,-7]
        k = 5
    Step1:
        nums = [3,9,-2,4,1,-7]
                ^
        count = 0
        sum = 3
        map = [3:1]
        k = 5

        # 1 (i.e., runningSum-k, 3-5=-2) not found in map
        # add the curr sum 3 in map

    Step2:
        nums = [3,9,-2,4,1,-7]
                ^
        count = 0
        sum = 12
        map = [3:1, 12:1]

        # 0 (12-5) not found in map
        # add the curr sum 12 in map

    Step3:
        nums = [3,9,-2,4,1,-7]
                    ^
        count = 0
        sum = 10
        map = [3:1, 12:1, 10:1]

        # 7 (10-5) not found in map
        # add the curr sum 10 in map

    Step4:
        nums = [3,9,-2,4,1,-7]
                    ^
        count = 0
        sum = 14
        map = [3:1, 12:1, 10:1, 14:1]

        # 4 (14-5) not found in map.
        # add the curr sum 14 in map

    Step5:
        nums = [3,9,-2,4,1,-7]
                        ^
        count = 1
        sum = 15
        map = [3:1, 12:1, 10:1, 14:1 , 15:1]

        # 5 (15-5) found in map . Increment the count
        #add cur sum 15 in map
        
    Step 6:
        nums = [3,9,-2,4,1,-7]
                            ^
        count = 2
        sum = 8
        map = [3:1, 12:1, 10:1, 14:1 , 15:1,8:1]

        # 6 (8-5) found in map . Increment the count
        #add cur sum 8 in map
*/


int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int sum=0,ans=0;
    mp[sum] = 1;
    for(auto it:nums){
        sum += it;
        int find = sum - k;
        if(mp.find(find) != mp.end()){
            ans += mp[find];
        }
        mp[sum]++;
    }
    return ans;
}


int main(){
    vector<int> nums = {3,9,-2,4,1,-7};
    int k = 5;
    cout<<subarraySum(nums,k)<<endl;
    return 0;
}