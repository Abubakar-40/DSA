// GFG : https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

// Approach # 1
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(!head)
            return nullptr;
        head = reverse(head);
        int carry = 1;
        Node * curr = head;
        while(curr){
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum/10;
            if(carry == 0)
                break;
            if(curr->next == nullptr && carry){
                curr->next = new Node(carry);
                carry = 0;
            }
            curr = curr->next;
        }
        
        return head = reverse(head);
    }
    Node* reverse(Node*head){
        if(!head || !head->next){
            return head;
        }
        Node*prev = nullptr;
        Node * curr = head;
        while(curr){
            Node*Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    
};