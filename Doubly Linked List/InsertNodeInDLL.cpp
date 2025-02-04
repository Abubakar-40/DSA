//GFG : https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list

class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        struct Node* curr = head;
        int c = 0;
        while(c!=pos){
            curr = curr->next;
            c++;
        }
        struct Node*newNode = new Node(data);
        newNode->next = curr->next;
        if(curr->next){
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
        return head;
    }
};