// LeetCode: https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                red++;
            } else if (nums[i] == 1) {
                white++;
            } else {
                blue++;
            }
        }
        for (size_t i = 0; i < red; i++) {
            nums[i] = 0;
        }
        for (size_t i = red; i < (red + white); i++) {
            nums[i] = 1;
        }
        for (size_t i = (red + white); i < (red + white + blue); i++) {
            nums[i] = 2;
        }
    }
};