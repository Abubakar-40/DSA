//GFG : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list

// Approach # 1(Bruite Force)
// Time Complexity : O(nlogn)
// Space Complexity : O(n)


class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root == nullptr){
            return nullptr;
        }
       vector<int> v;
        struct Node*temp1 = root;
        while(temp1){
            struct Node*temp2 = temp1;
            while(temp2){
                v.push_back(temp2->data);
                temp2 = temp2->bottom;
            }
            temp1 = temp1->next;
        }
        sort(v.begin(),v.end());
        struct Node * newRoot = new Node(v[0]);
        struct Node * newTemp = newRoot;
        for(size_t i = 1; i<v.size();i++){
            newTemp->bottom = new Node(v[i]);
            newTemp = newTemp->bottom;
        }
        return newRoot;
    }
};

// Approach # 2
// Time Complexity : O(m*n)
// Space Complexity : O(1)

class Solution {
public:
    // Function to merge two sorted linked lists using bottom pointers
    Node* mergeLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        Node* result;
        
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeLists(a, b->bottom);
        }
        
        result->next = nullptr; 
        return result;
    }

    
    Node* flatten(Node* root) {
        if (!root || !root->next) return root;

        root->next = flatten(root->next);

        root = mergeLists(root, root->next);

        return root;
    }
};

