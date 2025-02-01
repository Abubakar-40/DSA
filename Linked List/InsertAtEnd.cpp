//GFG : https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        if(head ==nullptr)
        {
            head = new Node(x);
            return head;
        }
        Node*temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = new Node(x);
        return head;
    }
};