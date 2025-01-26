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

// Approach # 2
// Space Complexity : O(1)
// Time Complexity : O(n log n)

class Solution {
public:
    ListNode* sortList(ListNode* head) { 
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        return mergeSort(head); 
    }

    ListNode* middle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = middle(head);
        ListNode* nextToMiddle = mid->next;
        mid->next = nullptr;
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(nextToMiddle);
        return merge(left, right);
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        ListNode* result = nullptr;
        if (left->val <= right->val) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }
};

