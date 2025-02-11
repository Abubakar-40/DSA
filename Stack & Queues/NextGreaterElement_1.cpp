//LeetCode: https://leetcode.com/problems/next-greater-element-i/description/

// Approach # 1(Bruite Force)
// Space Complexity : O(N)
// Time Complexity : O(N * M^2)
// Inefficient Approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size());
        for(size_t i = 0; i < nums1.size(); i++){
            for(size_t j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    int max = nums2[j];
                    for(size_t k = j + 1; k < nums2.size(); k++){
                        if(nums2[k] > max){
                            max = nums2[k];
                            break;
                        }
                    }
                    if(max == nums2[j]){
                        result[i] = -1;
                    }
                    else{
                        result[i] = max;
                    }
                }
            }
        }
        return result;      
    }
};

// Approach # 2(Using Stack)
// Space Complexity : O(N)
// Time Complexity : O(N*M)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreater(nums2.size(), -1);
        stack<int> stk;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                nextGreater[i] = stk.top();
            }
            stk.push(nums2[i]);
        }
        vector<int> result(nums1.size());
        for (size_t i = 0; i < nums1.size(); i++) {
            for (size_t j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]){
                    result[i] = nextGreater[j];
                    break;
                }
            }
        }
        return result;
    }
};