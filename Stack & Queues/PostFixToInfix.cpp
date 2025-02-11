//GFG : https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion

// Space Complexity : O(N)
// Time Complexity : O(N)

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        string result;
        stack<string>stk;
        for(size_t i = 0; i<exp.size(); i++){
            char ch = exp[i];
            if(ch == ' '){
                continue;
            }
            else if(!isOperator(ch)){
                stk.push(string(1,ch));
            }
            else{
                string op2 = stk.top();
                stk.pop();
                string op1 = stk.top();
                stk.pop();
                string temp = "("+op1+ch+op2+")";
                stk.push(temp);
            }
            
        }
        result = stk.top();
        stk.pop();
        return result;
    }
    bool isOperator(char c){
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
};