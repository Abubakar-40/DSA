//LeetCode: https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (size_t i = 0; i < numRows; i++) {
            for (size_t j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    ans[i].push_back(1);
                } else {
                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
        }
        return ans;
    }
};