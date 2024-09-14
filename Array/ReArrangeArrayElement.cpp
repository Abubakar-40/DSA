// LeetCode: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// Approach # 1 (BruiteForce---> O(n^3) without extra space)

vector<int> rearrangeArray(vector<int> &nums){
    for (size_t i = 0; i < nums.size(); i++){
        if ((i + 1) % 2 == 0){
            if (nums[i] > 0){
                for (size_t j = i + 1; j < nums.size(); j++){
                    if (nums[j] < 0){
                        int s = nums[j];
                        for (int k = j; k >= i + 1; k--){
                            nums[k] = nums[k - 1];
                        }
                        nums[i] = s;
                        break;
                    }
                }
            }
        }
        else{
            if (nums[i] < 0){
                for (size_t j = i + 1; j < nums.size(); j++){
                    if (nums[j] > 0){
                        int s = nums[j];
                        for (int k = j; k >= i + 1; k--){
                            nums[k] = nums[k - 1];
                        }
                        nums[i] = s;
                        break;
                    }
                }
            }
        }
    }
    return nums;
}

// Approach # 2(O(n) with 2 extra Arrays/Vectors)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }
        int c1 = 0, c2 = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = pos[c1++];
            } else {
                nums[i] = neg[c2++];
            }
        }
        pos.clear();
        neg.clear();
        return nums;
    }
};

// Approach # 3(O(n) with 1 extra Array/ Vector) 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int arranged[nums.size()];
        int pos = 0, neg = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                arranged[pos] = nums[i];
                pos += 2;
            } else {
                arranged[neg] = nums[i];
                neg += 2;
            }
        }
        for (size_t i = 0; i < nums.size(); i++) {
            nums[i] = arranged[i];
        }
        return nums;
    }
};

