//LeetCode: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

// Approach # 1
// Time Complexity : O(n)
// Space Complexity : O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int count(ListNode* head) {
        int c = 0;
        while (head != nullptr) {
            head = head->next;
            c++;
        }
        return c;
    }
    ListNode* reverse(ListNode* head, ListNode* prev) {
        ListNode* temp = head;
        while (temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c = count(head);
        k = k % c;
        if (k == 0) {
            return head = reverse(head, nullptr);
        }
        if (head == nullptr || k == 1) {
            return head;
        }
        bool flag1 = true, flag2 = true;
        ListNode *prev = nullptr, *temp1 = head, *temp2 = head;
        while (temp2 != nullptr) {
            int i = 1;
            flag2 = true;
            while (i != k && temp2 != nullptr) {
                temp2 = temp2->next;
                i++;
            }
            if (temp2) {
                if (prev) {
                    prev->next = nullptr;
                }
                flag2 = false;
                ListNode* save = temp2->next;
                temp2->next = nullptr;
                temp2 = reverse(temp1, nullptr);
                if (flag1) {
                    head = temp2;
                    flag1 = false;
                }
                if (prev) {
                    prev->next = temp2;
                }
                prev = temp1;
                temp1 = temp2 = save;
            }
        }
        if (flag2) {
            prev->next = temp1;
        }
        return head;
    }
};