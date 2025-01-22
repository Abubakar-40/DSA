//LeetCode: https://leetcode.com/problems/palindrome-linked-list/

// Approach # 1
//  Time Complexity: O(n)
//  Space Complexity: O(n)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 0,j=v.size()-1;i<v.size(),j>=0;i++,j--)
        {
            if(v[i] != v[j]){
                return false;
            }
        }
        return true;

    }
};


// Approach # 2
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr && fast->next == nullptr) {
            ListNode* t = new ListNode(slow->val);
            t->next = slow->next;
            // slow->next = t;
            slow->next = 0;
            t = reverse(t);
            slow = head;
            while (slow != nullptr && t != nullptr) {
                if (slow->val != t->val) {
                    return false;
                }
                slow = slow->next;
                t = t->next;
            }
            return true;
        } else {
            prev->next = 0;
            slow = reverse(slow);
            prev = head;
            while (slow != nullptr && prev != nullptr) {
                if (slow->val != prev->val) {
                    return false;
                }
                slow = slow->next;
                prev = prev->next;
            }
            return true;   
        }
    }
    ListNode* reverse(ListNode* head) {
        ListNode *temp = head, *prev = nullptr;
        while (temp != nullptr) {
            ListNode* temp2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp2;
        }
        return prev;
    }
};
