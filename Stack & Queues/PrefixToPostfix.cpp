//GFG : https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-postfix-conversion

// Approach # 1

// Time Complexity : O(N)
// Space Complexity : O(N)
// This approach having 2 steps:
// 1. Conversion of prefix to infix:
// Link : https://github.com/Abubakar-40/DSA/blob/main/Stack%20%26%20Queues/PrefixToInfix.cpp
// 2. Then Conversion of infix to Postfix:
// Link : https://github.com/Abubakar-40/DSA/blob/main/Stack%20%26%20Queues/InfixToPostFix.cpp

class Solution {
  public:
  string preToInfix(string pre_exp) {
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
    int prec(char s){
        if(s == '^')
            return 3;
        else if(s == '*' || s == '/')
            return 2;
        else if(s == '+' || s == '-')
            return 1;
        else
            return -1;
    }
    string infixToPostfix(string s) {
        string p;
        stack<char>stk;
        for(size_t i = 0; i<s.size(); i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i] >= '0' && s[i] <= '9')){
                p+=s[i];
            }
            else if(s[i] == '('){
                stk.push(s[i]);
            }
            else if(s[i] == ' '){
                
            }
            else if(s[i] == ')'){
                while(!stk.empty() && stk.top() != '('){
                    p += stk.top();
                    stk.pop();
                }
                if(!stk.empty())
                    stk.pop();
            }
            else{
                while(!stk.empty() && prec(s[i])<=prec(stk.top())){
                    p+=stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
        while(!stk.empty()){
            p+=stk.top();
            stk.pop();
        }
        return p;
    }

    string preToPost(string pre_exp) {
        
        string infix = preToInfix(pre_exp);
        return infixToPostfix(infix);
        
    }
};
