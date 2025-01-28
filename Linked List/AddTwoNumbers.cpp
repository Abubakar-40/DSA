// LeetCode : https://leetcode.com/problems/add-two-numbers/description/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        int carry = 0;
        int s = l1->val + l2->val + carry;
        ListNode* result = new ListNode(s % 10);
        carry = s / 10;
        ListNode* temp = result;
        l1 = l1->next, l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                s = l1->val + l2->val + carry;
                temp->next = new ListNode(s % 10);
                carry = s / 10;
                temp = temp->next;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 == nullptr) {
                s = l2->val + carry;
                temp->next = new ListNode(s % 10);
                carry = s / 10;
                temp = temp->next;
                l2 = l2->next;
            } else {
                s = l1->val + carry;
                temp->next = new ListNode(s % 10);
                carry = s / 10;
                temp = temp->next;
                l1 = l1->next;
            }
        }
        if (carry != 0) {
            temp->next = new ListNode(carry);
        }
        return result;
    }
};