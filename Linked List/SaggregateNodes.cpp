//LeetCode: https://leetcode.com/problems/odd-even-linked-list/description/

// Approach # 1
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int c = count(head);
        ListNode *temp1 = head, *temp2 = head->next, *save = head->next;
        while (true) {
            if (temp2->next != nullptr) {
                temp1->next = temp2->next;
                temp1 = temp2;
                temp2 = temp2->next;
            } else {
                if (c % 2 == 0)
                    temp1->next = save;
                else {
                    temp1->next = nullptr;
                    temp2->next = save;
                }
                break;
            }
        }
        return head;
    }
    int count(ListNode* head) {
        int c = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }
        return c;
    }
};