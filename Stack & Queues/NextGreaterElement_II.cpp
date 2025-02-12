//LeetCode : https://leetcode.com/problems/next-greater-element-ii/description/

// Approach # 1(Bruite Force)
// Space Complexity : O(N)
// Time Complexity : O(N^2)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size() , -1);
        for(int i = 0; i < nums.size(); i++){
            int j = (i + 1) % nums.size();
            while(i != j){
                if(nums[i]<nums[j]){
                    result[i] = nums[j];
                    break;
                }
                else
                    j = (j + 1) % nums.size();
            }
        }
        return result;
    }
};


// Approach # 2
// 