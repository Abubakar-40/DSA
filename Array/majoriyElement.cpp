// LeetCode: https://leetcode.com/problems/majority-element/description/

// Approach # 1(By sorting)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int s = 0;
        bool flag = true;
        for (size_t i = 1; i < nums.size(); i++) {
            if (i >= 1 && i < nums.size() && nums[i] == nums[i - 1]) {
                count++;
            } else {
                if (count > (nums.size() / 2)) {
                    s = nums[i - 1];
                    flag = false;
                    break;
                } else {
                    count = 1;
                }
            }
        }
        if (flag) {
            s = nums[nums.size() - 1];
        }
        return s;
    }
};

// Approach # 2(without sorting--> optimal Approach)