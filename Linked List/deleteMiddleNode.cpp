//LeetCode : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

// Approach # 1(Two Pointer Approach)
// Time Complexity : O(n)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            //delete head;
            return nullptr;
        }
        ListNode *prev = 0, *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != nullptr) {
            prev->next = slow->next;
        }
        delete slow;
        slow =  nullptr;
        return head;
    }
};