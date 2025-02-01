//GFG : https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-linked-list


class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node*head = nullptr;
        head = new Node(arr[0]);
        Node*temp = head;
        for(size_t i = 1; i<arr.size();i++){
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        return head;
    }
};