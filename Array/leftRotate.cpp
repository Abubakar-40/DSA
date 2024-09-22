// LeetCode: https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for (int i = 0, j = nums.size() - 1; i < nums.size(), j >= 0;
             i++, j--) {
            if (i + 1 == j && j - 1 == i) {
                swap(nums[i], nums[j]);
                break;
            } else if (i == j) {
                break;
            } else {
                swap(nums[i], nums[j]);
            }
        }
        for (int i = 0, j = k - 1; i < k, j >= 0; i++, j--) {
            if (i + 1 == j && j - 1 == i) {
                swap(nums[i], nums[j]);
                break;
            } else if (i == j) {
                break;
            } else {
                swap(nums[i], nums[j]);
            }
        }
        for (int i = k, j = nums.size() - 1; i < nums.size(), j >= k;
             i++, j--) {
            if (i + 1 == j && j - 1 == i) {
                swap(nums[i], nums[j]);
                break;
            } else if (i == j) {
                break;
            } else {
                swap(nums[i], nums[j]);
            }
        }
    }
};