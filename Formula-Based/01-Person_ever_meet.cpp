/* 
    Question URL - https://www.geeksforgeeks.org/check-if-two-people-starting-from-different-points-ever-meet/#
    Question - Check if two people starting from different points ever meet.
    Testcases:- 
        Input  : x1 = 5, v1 = 8, x2 = 4, v2 = 7
        Output : No
        Explanation: The first person is starting ahead of the second one.
        and his speed is also greater than the second one, so they will never meet.

        Input  : x1 = 6, v1 = 6, x2 = 4, v2 = 8
        Output : Yes
*/
#include <iostream>
using namespace std;

int main(){
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    if(x1>x2 && v1>=v2){
        cout << "No" << endl;
    }
    else if(x1<x2 && v1<=v2){
        cout << "No" << endl;
    }
    else{
        // If the relative difference between the starting points is a factor of the relative difference between the speeds, then they will meet.
        if((x2-x1)%(v2-v1)==0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        } 
    }

    return 0;
}