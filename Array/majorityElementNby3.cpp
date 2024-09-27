//LeetCode: https://leetcode.com/problems/majority-element-ii/description/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        int count = 1;
        int i = 1;
        bool flag = true;
        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                count++;
                flag = true;
            } else {
                if (count > nums.size() / 3) {
                    v.push_back(nums[i - 1]);
                }
                count = 1;
                flag = false;
            }
            i++;
        }
        if (count > nums.size() / 3) {
            v.push_back(nums[i - 1]);
        }
        return v;
    }
};