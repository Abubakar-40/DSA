// GFG : https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list

// Approach # 1
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if(!head || !head->next){
            return head;
        }
        struct Node* curr = head->next;
        while(curr){
            struct Node*save = curr->next;
            if(curr->data == curr->prev->data){
                if(curr->prev)
                    curr->prev->next = curr->next;
                if(curr->next)
                    curr->next->prev = curr->prev;
                delete curr;
            }
            curr = save;
        }
        return head;
    }
};