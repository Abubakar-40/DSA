//GFG : https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-stack-using-linked-list

// Space Complexity : O(1)
// Time Complexity : O(1)
class MyStack{
  private:
    StackNode *top;
  public:
    void push(int x) {
        // code here
        if(top == nullptr){
            top = new StackNode(x);
        }
        StackNode*newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        // code here
        if(!top)
            return -1;
        int val = top->data;
        StackNode*save = top;
        top = top->next;
        delete save;
        return val;
    }

    MyStack() { top = NULL; }
};