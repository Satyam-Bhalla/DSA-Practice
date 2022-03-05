/*

Given an array of positive integers, each of which represent the number of litres of water in that particular bucket, we have to make the litres of water in every bucket equal.
We are allowed to do two types of operations any number of times:

We can altogether remove a bucket from the sequence
We can remove some water from a bucket
We have to tell what is the minimum number of litres removed to make all buckets have the same amount of water.

Eg.
Input:
1 2 3

Output:
2

Explanation:
We remove bucket 1 and remove 1 liter from Bucket 3, so total water removed is 2 liter (the amount of water in the bucket removed gets added to the total water removed).

*/
/*
    Sort
    5 2 3 4 1
    
    1 2 3 4 5
    0 1 2 3 4  -> 1 1 1 1 1  10
    0 0 1 2 3  -> 0 2 2 2 2  7
    0 0 0 1 2  -> 0 0 3 3 3  6
    0 0 0 0 1  -> 0 0 0 4 4  7
    0 0 0 0 0  -> 0 0 0 0 5  10   
    
    1 2 3 4 5
    
    1 3 4 20 21
    1 2 1 16 5
    
           1
       3       4
    20  21  
    
    
    1 3 0  2  8  -> 11
    
    1 5 15 20 50
    1 4 10 5  30
    
     
    
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{   
    vector<int> nums = {21,20,4,3,1};
  
    // ans = Math.min(ans, totalWater - (nums[i] * (i+1)) );
  
    // // https://leetcode.com/discuss/interview-question/424751/de-shaw-coding-round-question-1
     
      
    // k-i k+1-i k+2-i
      
    // k+k+1+k+2 -3*i
    
    sort(nums.begin(),nums.end());
  
    int min = INT_MAX;
    
    for(int i=0;i<nums.size();i++){
      int sum = 0;
      int j = i-1;
      while(j>=0){
         sum += nums[j];
          j--;
       } 
      for(int k=i+1;k<nums.size();k++){
          int diff = nums[k]-nums[i];
          sum += diff;
      }
      if(sum<min){
        min = sum;
      }
    }
    
    cout << "Min Litres: " << min << endl;
    return 0;
}
