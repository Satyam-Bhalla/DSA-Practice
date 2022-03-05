/* 
    Question URL - https://leetcode.com/problems/majority-element/
    Question - Given an array nums of size n, return the majority element.
               The majority element is the element that appears more than ⌊n / 2⌋ times. 
               You may assume that the majority element always exists in the array.
    Testcases:- 
        Example 1:
            Input: nums = [3,2,3]
            Output: 3
        Example 2:
            Input: nums = [2,2,1,1,1,2,2]
            Output: 2
*/

#include <bits/stdc++.h>

using namespace std;

// Sorting based approach
int firstApproach(vector<int> v, int n) {
    sort(v.begin(), v.end());
    return v[n/2];
}


// Boyer-Moore algorithm approach
/*
    Essentially, what Boyer-Moore does is look for a suffix sufsuf of nums where suf[0]suf[0] 
    is the majority element in that suffix. To do this, we maintain a count, which is incremented
    whenever we see an instance of our current candidate for majority element and decremented 
    whenever we see anything else. Whenever count equals 0, we effectively forget about everything 
    in nums up to the current index and consider the current number as the candidate for majority
    element. It is not immediately obvious why we can get away with forgetting prefixes of nums - 
    consider the following examples (pipes are inserted to separate runs of nonzero count).

    [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]

    Here, the 7 at index 0 is selected to be the first candidate for majority element. 
    count will eventually reach 0 after index 5 is processed, so the 5 at index 6 will be the next 
    candidate. In this case, 7 is the true majority element, so by disregarding this prefix, we are 
    ignoring an equal number of majority and minority elements - therefore, 7 will still be the 
    majority element in the suffix formed by throwing away the first prefix.
*/
int secondApproach(vector<int> v, int n) {
    int count = 0, maj = 0;
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            maj = v[i];
        }
        if(v[i] == maj) {
            count++;
        } else {
            count--;
        }
    }
    return maj;
}



int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    int n = nums.size();
    cout << firstApproach(nums, n) << endl;
    cout << secondApproach(nums, n) << endl;
    return 0;
}