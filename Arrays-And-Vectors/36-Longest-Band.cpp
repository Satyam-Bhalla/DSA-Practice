/*
	https://leetcode.com/problems/longest-consecutive-sequence/
	Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
	You must write an algorithm that runs in O(n) time.

	Example 1:
	Input: nums = [100,4,200,1,3,2]
	Output: 4
	Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

	Example 2:
	Input: nums = [0,3,7,2,5,8,4,6,0,1]
	Output: 9
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int largestBand(vector<int> arr){
	int n = arr.size();
	unordered_set<int> s;
	
	//Data inside a set
	for(int x : arr){
		s.insert(x);
	}

	//Iterate over the arr
	int largestLen = 1;

	for(auto element : s){
		int parent = element - 1;

		if(s.find(parent)==s.end()){
			//find entire band / chain starting from element
			int next_no = element + 1;
			int cnt = 1;

			while(s.find(next_no)!=s.end()){
				next_no++;
				cnt++;
			}

			if(cnt>largestLen){
				largestLen = cnt;
			}
		}
	}


	return largestLen;
}



int main(){

	vector<int> arr{1, 9, 3, 0, 18, 5, 2, 10, 7, 12, 6};
	cout << largestBand(arr)<<endl;

	return 0;
}