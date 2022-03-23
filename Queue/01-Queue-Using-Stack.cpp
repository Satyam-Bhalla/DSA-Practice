#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        pushHelper(x);
    }
    void pushHelper(int x){
        if(s.empty()){
            s.push(x);
            return;
        }
        if(s.size()==0){
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        pushHelper(x);
        s.push(data);
        return;
        
    }
    
    int pop() {
        int temp = s.top();
        s.pop();
        return temp;
    }
    
     // Get the front element.
    int peek() {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty() {
        return (s.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    return 0;
}