//LeetCode: https://leetcode.com/problems/implement-stack-using-queues/description/

// Time Complexity : O(1)
// Space Complexity : O(1)

class MyStack {
private:
    queue<int> q2;
    queue<int> q1;
public:
    MyStack() {}
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};