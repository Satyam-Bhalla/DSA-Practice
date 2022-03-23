/*
    https://practice.geeksforgeeks.org/problems/minimum-swaps/1
    Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
    
    Example 1:
    Input: nums = {2, 8, 5, 4}
    Output: 1
    Explaination: swap 8 with 4.

    Example 2:
    Input: nums = {10, 19, 6, 3, 5}
    Output: 2
    Explaination: swap 10 with 3 and swap 19 with 5.
    
    Your Task: You do not need to read input or print anything. Your task is to complete the
    function minSwaps() which takes the nums as input parameter and returns an integer denoting 
    the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 

    Expected Time Complexity: O(nlogn)
    Expected Auxiliary Space: O(n)
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countMinSwaps(vector<int> arr){

    // Know the actual positions of elements (sorting)
    //store the current indices
    int n = arr.size();
    pair<int,int> ap[n];
    for(int i=0;i<n;i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    //sorting
    sort(ap,ap+n);

    //build the main logic
    vector<bool> visited(n,false);

    int ans = 0;
    for(int i=0;i<n;i++){

        // if element is visited or element is in right postion 
        int old_position = ap[i].second;
        if(visited[i]==true or old_position==i){
            continue;
        }

        // visiting the element (index) for first time 
        int node = i;
        int cycle = 0;

        while(!visited[node]){
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += (cycle-1);

    }
   
    return ans;

}


int main() {
    vector<int> arr{5,4,3,2,1};
    cout<<countMinSwaps(arr)<<endl;
    return 0;
}
