//GFG : https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix

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
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        // Your code here
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
   
};