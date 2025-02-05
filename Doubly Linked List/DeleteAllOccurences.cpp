//GFG : https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list

// Approach # 1
// Time Complexity : o(n)
// Space Complexity : O(1)

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        if(head_ref == nullptr || *head_ref == nullptr){
            return;
        }
        Node * curr = *head_ref;
        while(curr){
            if(curr->data == x){
                Node*save = curr->next;
                if(curr == *head_ref){
                    *head_ref = save;
                }
                if(curr->prev)
                    curr->prev->next = curr->next;
                if(curr->next)
                    curr->next->prev = curr->prev;
                delete curr;
                curr = save;
            }
            else{
                curr = curr->next;
            }
        }
    }
};