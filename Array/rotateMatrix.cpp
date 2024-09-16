//LeetCode: https://leetcode.com/problems/rotate-image/description/

// Most Optimal Solution

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = i + 1; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (size_t i = 0; i < matrix.size(); i++) {
            for (int j = 0, k = matrix.size() - 1; j < matrix.size(), k >= 0;
                 j++, k--) {
                if (j == k) {
                    break;
                } else if (j + 1 == k && k - 1 == j) {
                    swap(matrix[i][j], matrix[i][k]);
                    break;
                } else {
                    swap(matrix[i][j], matrix[i][k]);
                }
            }
        }
    }
};