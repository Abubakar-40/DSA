// LeetCode: https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (size_t i = 0; i < nums.size() - 1; i++) {
            int min = i;
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums[min] > nums[j]) {
                    min = j;
                }
            }
            if (i != min) {
                swap(nums[min], nums[i]);
            }
        }
        int s;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i != nums[i]) {
                return i;
            }
            s = i;
        }
        return ++s;
    }
};