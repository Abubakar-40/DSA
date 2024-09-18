// LeetCode: https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int count = 0;
        for (size_t i = 0; i < size; i++) {
            int sum = 0;
            for (size_t j = i; j < size; j++) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};