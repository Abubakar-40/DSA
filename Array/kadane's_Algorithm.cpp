// Leetcode: https://leetcode.com/problems/maximum-subarray/description/

// APPROACH # 1 (O(n))

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxHere = nums[0];
        int maxSoFar = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            maxHere = max(nums[i], maxHere + nums[i]);
            maxSoFar = max(maxHere, maxSoFar);
        }
        return maxSoFar;
    }
};


// APPROACH # 2 (BruiteForce) ---> O(n^2)

int subArray(vector<int> &nums)
{
    int s = 0;
    int e = 0;
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum > max)
            {
                max = sum;
                s = i;
                e = j;
            }
        }
    }
    return max;
}