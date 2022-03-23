/*
	https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
	Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

	Return the shortest such subarray and output its length.
	Example 1:
	Input: nums = [2,6,4,8,10,9,15]
	Output: 5
	Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
	Example 2:

	Input: nums = [1,2,3,4]
	Output: 0
	Example 3:

	Input: nums = [1]
	Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> arr,int i){
	int x = arr[i];
	if(i==0){
		return x > arr[1];
	}
	if(i==arr.size()-1){
		return x < arr[i-1];
	}
	return x > arr[i+1] or x < arr[i-1];

}

// pair<int,int> subarraySort(vector<int> arr) {

// 	int smallest = INT_MAX;
// 	int largest = INT_MIN;

// 	for(int i=0;i<arr.size();i++){
// 		int x = arr[i];
		
// 		if(outOfOrder(arr,i)){
// 			smallest = min(smallest,x);
// 			largest = max(largest,x);
// 		}
// 	}

// 	//next step find the right index where smallest and largest lie (subarray) for out solution
// 	if(smallest==INT_MAX){
// 		return {-1,-1};
// 	}

// 	int left = 0;
// 	while(smallest >= arr[left]){
// 		left++;
// 	}
// 	int right = arr.size() - 1;
// 	while(largest <= arr[right]){
// 		right--;
// 	}

// 	return {left,right};

// }
int findUnsortedSubarray(vector<int>& arr) {
        if(arr.size()<2){
            return 0;
        }
        int smallest = INT_MAX;
        int largest = INT_MIN;

        for(int i=0;i<arr.size();i++){
            int x = arr[i];

            if(outOfOrder(arr,i)){
                smallest = min(smallest,x);
                largest = max(largest,x);
            }
        }

        //next step find the right index where smallest and largest lie (subarray) for out solution
        if(smallest==INT_MAX){
            return 0;
        }

        int left = 0;
        while(smallest >= arr[left]){
            left++;
        }
        int right = arr.size() - 1;
        while(largest <= arr[right]){
            right--;
        }

	    return right-left+1;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    // auto p = subarraySort(arr);
    // cout<< p.first <<" and "<<p.second <<endl;
	cout << findUnsortedSubarray(arr) << endl;

    return 0;
}
