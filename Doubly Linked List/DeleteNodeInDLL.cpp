//GFG : https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(!head || (!head->next && x == 1))
            return nullptr;
        
        int c = 1;
        Node*curr = head;
        while(c!=x){
            curr = curr->next;
            c++;
        }
        if(curr->prev)
            curr->prev->next = curr->next;
        if(curr->next)
            curr->next->prev = curr->prev;
        if(c == 1){
            head = head->next;
        }
        delete curr;
        return head;
    }
};