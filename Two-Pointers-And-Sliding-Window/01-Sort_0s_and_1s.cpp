/*
    Question URL - https://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
    Question - You are given an array of 0s and 1s in random order. 
               Segregate 0s on left side and 1s on right side of the array 
               [Basically you have to sort the array]. Traverse array only once. 
    Testcases:-
        Example 1:
            Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
            Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
*/
#include <bits/stdc++.h>
using namespace std;

/*Function to put all 0s on left and all 1s on right*/
void segregate0and1(int arr[], int size)
{
	/* Initialize left and right indexes */
	int left = 0, right = size-1;

	while (left < right)
	{
		/* Increment left index while we see 0 at left */
		while (arr[left] == 0 && left < right)
			left++;

		/* Decrement right index while we see 1 at right */
		while (arr[right] == 1 && left < right)
			right--;

		/* If left is smaller than right then there is a 1 at left
		and a 0 at right. Exchange arr[left] and arr[right]*/
		if (left < right)
		{
			arr[left] = 0;
			arr[right] = 1;
			left++;
			right--;
		}
	}
}


int main()
{
	int arr[] = {0, 1, 0, 1, 1, 1};
	int i, arr_size = sizeof(arr)/sizeof(arr[0]);

	segregate0and1(arr, arr_size);

	cout << "Array after segregation " << endl;
	for (i = 0; i < 6; i++)
		cout << arr[i] << " ";
    cout << endl;
	return 0;
}