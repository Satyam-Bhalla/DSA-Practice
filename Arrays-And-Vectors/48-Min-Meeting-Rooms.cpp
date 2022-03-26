/*
    Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.
    Example 1:
    Input: intervals = [[0,30],[5,10],[15,20]]
    Output: 2

    Example 2:
    Input: intervals = [[7,10],[2,4]]
    Output: 1
*/

#include <bits/stdc++.h>

using namespace std;

/*
    Intuition
    Track the change of room numbers in time order.

    Explanation:

    Save all time points and the change on current meeting rooms.
    Sort all the changes on the key of time points.
    Track the current number of using rooms cur and update result res.
    Time Complexity:
    Time O(NlogN)
    Space O(N)
*/
int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> m;
    for (auto &t : intervals)
        m[t[0]]++, m[t[1]]--;
    int cur = 0, res = 0;
    for (auto &it : m)
        res = max(res, cur += it.second);
    return res;
}

int main(){
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    cout << minMeetingRooms(intervals) << endl;
    return 0;
}