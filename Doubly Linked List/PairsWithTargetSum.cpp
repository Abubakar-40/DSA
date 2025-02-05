//GFG : https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list

// Approach # 1
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>> v;
        if(!head)
            return v;
        Node * h = head;
        Node * t = head;
        while(t->next){
            t = t->next;
        }
        while(h && t && h!=t && h->prev!=t){
            if(h->data + t->data == target){
                v.push_back({h->data,t->data});
                h = h->next;
                t = t->prev;
            }
            else if(t->data + h->data >= target){
                t = t->prev;
            }
            else {
                h = h->next;
            }
           
        }
        return v;
    }
};