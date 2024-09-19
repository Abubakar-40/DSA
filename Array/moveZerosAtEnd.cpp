// LeetCode: https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                for (size_t j = i + 1; j < nums.size(); j++) {
                    if (nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};