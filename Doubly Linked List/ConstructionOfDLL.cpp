//GFG : https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-doubly-linked-list

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        if(arr.size() == 0){
            return nullptr;
        }
        Node * head = new Node(arr[0]);
        Node * temp = head;
        for(size_t i = 1; i<arr.size(); i++){
            temp->next = new Node(arr[i]);
            temp->next->prev = temp;
            temp = temp->next;
        }
        return head;
    }
};