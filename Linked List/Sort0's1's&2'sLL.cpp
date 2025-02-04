//GFG : https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

// Approach # 1(Bruite Force)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // Add code here
        if(!head)
            return nullptr;
        Node*curr = head;
        int one = 0,zero = 0,two = 0;
        while(curr){
            if(curr->data == 0)
                zero++;
            else if(curr->data == 1){
                one++;
            }
            else{
                two++;
            }
            curr = curr->next;
        }
        curr = head;
        while(zero!=0){
            curr->data = 0;
            zero--;
            curr = curr->next;
        }
        while(one!=0){
            curr->data = 1;
            one--;
            curr = curr->next;
        }
        while(two!=0){
            curr->data = 2;
            two--;
            curr = curr->next;
        }
        return head;
        
    }
};


// Approach # 2(Dutch Flag Algorithm)
// Time Complexity : O(n)
// Space Complexity : O(1)
if (!head || !head->next) return head;  // Edge case

    Node *zeroDummy = new Node(-1), *oneDummy = new Node(-1), *twoDummy = new Node(-1);
    Node *zero = zeroDummy, *one = oneDummy, *two = twoDummy, *curr = head;

    // Traverse and rearrange pointers
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    zero->next = oneDummy->next ? oneDummy->next : twoDummy->next;
    one->next = twoDummy->next;
    two->next = nullptr;

    head = zeroDummy->next;  
    delete zeroDummy, oneDummy, twoDummy;

    return head;