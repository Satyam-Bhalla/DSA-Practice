/*
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

    Example 1:

    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2,2]
    Example 2:

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [4,9]
    Explanation: [9,4] is also accepted.
    

    Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000
    

    Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> m;
        for (auto n : nums1) {
            ++m[n];
        }
        
        // First K elements of Vector nums1 contains the result
        int k = 0;
        for (auto n : nums2) {
            auto it = m.find(n);
            if (it != end(m) && --it->second >= 0) {
                nums1[k++] = n;
            }
        }
        return vector<int> (nums1.begin(), nums1.begin() + k);
        
        // sort(begin(nums1), end(nums1));
        // sort(begin(nums2), end(nums2));
        // nums1.erase(set_intersection(begin(nums1), end(nums1),
        //     begin(nums2), end(nums2), begin(nums1)), end(nums1));
        // return nums1;
}


int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> res = intersect(nums1, nums2);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}