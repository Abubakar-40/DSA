//LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// Approach 
// Space Complexity : O(1)
// Time Complexity : O(n)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }
        int c = count(head);
        c = c - n + 1;
        int c2 = 0;
        ListNode *temp = head, *prev = nullptr;
        while (temp != nullptr) {
            c2++;
            if (c2 == c) {
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if (c != 1) {
            prev->next = temp->next;
            delete temp;
        }
        else{
            head = head->next;
            delete temp;
        }
        return head;
    }

    int count(ListNode* head) {
        ListNode* temp = head;
        int c = 0;
        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }
        return c;
    }
};