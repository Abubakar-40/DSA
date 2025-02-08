//LeetCode: https://leetcode.com/problems/valid-parentheses/description/

// Approach (Using Stack Data Structure)
// Space Complexity : O(n)
// Time Complexity : O(n)

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1) {
            return false;
        }
        if(s.size() == 0){
            return true;
        }
        
        stack<char> stk;
        stk.push(s[0]);
        for(size_t i = 1; i<s.size(); i++){
            if(!stk.empty() && s[i] == ')' && stk.top() == '('){
                stk.pop();
            }
            else if(!stk.empty() && s[i] == ']' && stk.top() == '['){
                stk.pop();
            }
            else if(!stk.empty() && s[i] == '}' && stk.top() == '{'){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};