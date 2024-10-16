// Leetcode: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

// APPROACH # 1(log n)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) {
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            } else {
                break;
            }
        }
        return nums[mid];
    }
};

// APPROACH # 2(O(n)) using XOR operator(^)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int val = 0;
        for(size_t i = 0; i<nums.size(); i++){
            val^=nums[i];
        }
        return val;
    }
};