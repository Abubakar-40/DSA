// LeetCode: https://leetcode.com/problems/merge-sorted-array/description/

// APPROACH # 1--> BruiteForce O(nlog n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        for (size_t i = m; i < nums1.size(); i++) {
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(),nums1.end());
    }
};

// APPROACH # 2 (OPTIMAL APPROACH)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            return;
        }
        int i = m - 1;
        int index = nums1.size() - 1;
        while (i >= 0) {
            nums1[index--] = nums1[i];
            nums1[i] = 0;
            i--;
        }
        index = 0;
        i = nums1.size() - m;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                nums1[index++] = nums1[i++];
            } else {
                nums1[index++] = nums2[j++];
            }
        }
        while (j < nums2.size()) {
            nums1[index++] = nums2[j++];
        }
        while (i < nums1.size()) {
            nums1[index++] = nums1[i++];
        }
    }
};

// APPROACH STEPS
/*
1. Check if `nums2` is empty**:
    If there's nothing to add from `nums2`, just stop.
  
2. Make space in `nums1`:
    Move the existing numbers in `nums1` to the back to create room for merging.

3. Start comparing numbers:
    Look at the numbers from both `nums1` and `nums2`, and pick the smaller one to place in the front.

4. Keep going until one list runs out:
    Continue comparing and placing numbers until you've gone through one of the lists.

5. Add leftover numbers:
    If one list still has numbers left, just add them to the end.

The result is that both lists are combined into a single sorted list.
*/

