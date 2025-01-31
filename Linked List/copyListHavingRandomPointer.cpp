//LeetCode : https://leetcode.com/problems/copy-list-with-random-pointer/description/

// Approach # 1
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }
        current = head;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        current = head;
        Node* newHead = head->next;
        while (current != nullptr) {
            Node* save = current->next;
            if (save != nullptr) {
                current->next = save->next;
            }
            current = save;
        }
        return newHead;
    }
};