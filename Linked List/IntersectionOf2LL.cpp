// LeetCode : https://leetcode.com/problems/intersection-of-two-linked-lists/description/

// Approach # 1(Bruite Force)
// Time Complexity : O(m*n)
// Space Complexity : O(1)

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *temp1 = headA, *temp2 = headB;
        while (temp1 != nullptr) {
            while (temp2 != nullptr) {
                if (temp1 == temp2) {
                    return temp2;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
            temp2 = headB;
        }
        return nullptr;
    }
};


// Approach # 2
// Time Complexity: O(m+n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *temp1 = headA, *temp2 = headB;
        while (temp1 != temp2) {

            temp1 = (temp1 == nullptr) ? headB:temp1->next;
            temp2 = (temp2==nullptr) ? headA:temp2->next;

        }
        return temp2;
    }
};