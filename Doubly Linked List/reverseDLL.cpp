//GFG : https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(!head || !head->next)
            return head;
        
        DLLNode*curr = head,*prev = nullptr;
        while(curr){
            DLLNode*Next = curr->next;
            curr->next = prev;
            curr->prev = Next;
            prev = curr;
            curr = Next;
        }
        return head = prev;
    }
};