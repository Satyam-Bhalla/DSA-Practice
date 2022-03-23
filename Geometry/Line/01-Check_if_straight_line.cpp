/*
    You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

    Example 1:
    Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    Output: true

    Example 2:
    Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    Output: false
*/
#include <bits/stdc++.h>

using namespace std;

bool is_straight_line(vector<vector<int>>& coordinates) {
    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];
    for (int i = 2; i < coordinates.size(); i++) {
        int x3 = coordinates[i][0];
        int y3 = coordinates[i][1];
        // If slope is not same, then it is not a straight line
        // Two point formula of line, if (x2-x1)*(y1-y0) = (x1-x0)(y2-y1), then a straight line, otherwise not
        if ((x2 - x1) * (y3 - y1) != (y2 - y1) * (x3 - x1)) {
            return false;
        }
    }
    return true;
}



int main()
{
    vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    cout << is_straight_line(coordinates) << endl;
    return 0;
}