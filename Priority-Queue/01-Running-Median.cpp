// https://leetcode.com/problems/find-median-from-data-stream/
#include<iostream>
#include<queue>
using namespace std;


//Running Median Heaps
int main(){



	priority_queue<int> leftheap; //maxheap
	priority_queue<int,vector<int>,greater<int> > rightheap; //min heap

	int d;
	cin>>d;
	leftheap.push(d);

    // First element is the median itself
	float med = d;
	cout<< med <<" ";

	cin>>d;
	while(d!=-1){
		//left or right or equal
		if(leftheap.size() > rightheap.size()){
			if(d < med){
				rightheap.push(leftheap.top());
				leftheap.pop();
				leftheap.push(d);
			}
			else{
				rightheap.push(d);
			}
			med = (leftheap.top() + rightheap.top())/2.0;
		}else if(leftheap.size() < rightheap.size()){
			if(d < med){
				leftheap.push(d);
			}
			else{
				leftheap.push(rightheap.top());
				rightheap.pop();
				rightheap.push(d);
			}
			med = (leftheap.top() + rightheap.top())/2;

		}else{ //leftheap.size()==rightheap.size
			if(d < med){
				leftheap.push(d);
				med = leftheap.top();
			}
			else{
				rightheap.push(d);
				med = rightheap.top();
			}

		}
		
		

		cout<< med<<" ";
		cin>>d;
	}



	return 0;
}