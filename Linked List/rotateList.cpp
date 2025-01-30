//LeetCode: https://leetcode.com/problems/rotate-list/description/

// Approach # 1
// Space Complexity : O(n)
// Time Complexity : O(n)

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* prev, int& c) {
        ListNode* temp = head;
        while (temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            c++;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int c = 0;
        head = reverse(head, nullptr, c);
        k = k % c;
        if(k == 0)
            return head = reverse(head,nullptr,c);
        ListNode* temp1 = head;
        int s = 1;
        while (s != k) {
            s++;
            temp1 = temp1->next;
        }
        ListNode* temp2 = temp1->next;
        temp1->next = nullptr;
        temp1 = reverse(head, nullptr, c);
        temp2 = reverse(temp2, nullptr, c);
        head->next = temp2;
        return head = temp1;
    }
};