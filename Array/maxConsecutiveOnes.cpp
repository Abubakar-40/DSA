// LeetCode: https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count = 0;
                bool flag = true;
                for (size_t j = i; j < nums.size(); j++) {
                    if (nums[j] == 1) {
                        count++;
                    } else {
                        i = j;
                        flag = false;
                        break;
                    }
                }
                if (count > maxCount) {
                    maxCount = count;
                }
                if(flag){
                    break;
                }
            }
        }
        return maxCount;
    }
};