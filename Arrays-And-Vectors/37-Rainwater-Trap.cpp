/*
	Given n non-negative integers representing an elevation map where the width of each bar is 1,
	compute how much water it can trap after raining.
	
	Example 1:
	Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
	Output: 6
	Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

	Example 2:
	Input: height = [4,2,0,3,2,5]
	Output: 9
*/

#include <iostream>
#include <vector>
using namespace std;


int trappedWater(vector<int> heights) {

 	//Complete
 	int n = heights.size();
 	if(n<=2){
 		return 0;
 	}

 	//Left Max, Right Max
 	vector<int> left(n,0), right(n,0);
 	left[0] = heights[0];
 	right[n-1] = heights[n-1];

 	for(int i=1;i<n;i++){
 		left[i] = max(left[i-1],heights[i]);
 		right[n-i-1] = max(right[n-i],heights[n-i-1]);
 	}

 	//water 
 	int water = 0;
 	for(int i=0;i<n;i++){
 		water += min(left[i],right[i]) - heights[i];
 	}
	
  return water;
}

int main() {
    vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedWater(water)<<endl;
    return 0;
}
