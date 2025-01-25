// LeetCode: https://leetcode.com/problems/sort-list/

// Approach # 1 (Bruite Force)
// Time Complexity : O(n^2)
// Space Complexity : O(1)

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* temp1 = head;
        while (temp1->next != nullptr) {
            ListNode* temp2 = temp1->next;
            ListNode* store = temp1;
            while (temp2 != nullptr) {
                if (temp2->val < store->val) {
                    store = temp2;
                }
                temp2 = temp2->next;
            }
            swap(temp1->val,store->val);
            temp1 = temp1->next;
        }
        return head;
    }
};

