//LeetCode: https://leetcode.com/problems/min-stack/description/

// Time Complexity : O(1)
// Space Complexity : O(n)

class MinStack {
    stack<int> mainStack, minStack;

public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if(!mainStack.empty()){
            if(mainStack.top() == minStack.top()){
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        if(!mainStack.empty()){
            return mainStack.top();
        }
        return -1;
    }

    int getMin() {
        if(!minStack.empty()){
            return minStack.top();
        }
        return -1;   
    }
};