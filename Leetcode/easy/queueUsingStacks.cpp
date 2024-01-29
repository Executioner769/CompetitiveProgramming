// https://leetcode.com/problems/implement-queue-using-stacks/
// 29-01-2024

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

    void transferFromTo(stack<int> &source, stack<int> &destination) {
        while(!source.empty()) {
            destination.push(source.top());
            source.pop();
        }
        return;
    }
public:
    MyQueue() {
        // s1.top() is back of Queue
        // s2.top() is front of Queue
    }
    
    void push(int x) {
        if(!s2.empty()) {
            transferFromTo(s2,s1);
        }
        s1.push(x);
    }
    
    int pop() {
        if(!s1.empty()){
            transferFromTo(s1,s2);
        }
        int val = -1;
        if(!s2.empty()) {
            val = s2.top();
            s2.pop();
        }
        return val;
    }
    
    int peek() {
        if(!s1.empty()){
            transferFromTo(s1,s2);
        }
        int val = -1;
        if(!s2.empty()) {
            val = s2.top();
        }
        return val;
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
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