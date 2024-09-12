// Leet Code: https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
};