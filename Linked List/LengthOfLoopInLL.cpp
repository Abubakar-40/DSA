//GFG : https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        if(!head || !head->next){
            return 0;
        }
        struct Node*slow = head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                slow =  head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                int c = 1;
                fast = slow->next;
                while(fast!=slow){
                    c++;
                    fast = fast->next;
                }
                return c;
            }
        }
        return 0;
    }
};