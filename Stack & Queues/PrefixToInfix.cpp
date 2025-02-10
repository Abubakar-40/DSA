//GFG : https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-infix-conversion

// Space Complexity : O(n)
// Time Complexity : O(n)

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> stk;
        string result;
        for(int i = pre_exp.size() - 1;i>=0;i--){
            char ch = pre_exp[i];
            if(ch == ' '){
                continue;
            }
            else if(!isOprtr(ch)){
                stk.push(string(1,ch));
            }
            else{
                string op1 = stk.top();
                stk.pop();
                string op2 = stk.top();
                stk.pop();
                string temp = "(" + op1 + ch + op2 + ")";
                stk.push(temp);
            }
            
        }
        result = stk.top();
        stk.pop();
        return result;
    }
    bool isOprtr(char c){
        if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^'){
            return true;
        }
        return false;
    }
};