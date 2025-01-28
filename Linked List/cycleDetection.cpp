//LeetCode: https://leetcode.com/problems/linked-list-cycle/description/


//Floyd's Cycle Detection Algorithm(Hare OR Tortoise Algorithm)
// Approach(Two pointer Approach)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};