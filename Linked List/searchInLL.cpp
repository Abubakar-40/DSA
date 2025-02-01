//GFG: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
        struct Node*temp = head;
        while(temp!=nullptr){
            if(temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
};