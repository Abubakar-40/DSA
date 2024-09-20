//LeetCode: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution {
public:
    bool check(vector<int>& nums) {
        int min_index = 0;
        int max_index = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[min_index] && nums[i] != nums[i - 1]) {
                min_index = i;
            }
            if (nums[i] >= nums[max_index]) {
                max_index = i;
            }
        }
        int count = 1;
        int i = min_index % nums.size();
        while (count < nums.size()) {
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                return false;
            }
            i = (i + 1) % nums.size();
            count++;
        }
        return true;
    }
};