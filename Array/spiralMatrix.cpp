//LeetCode: https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int total = matrix.size() * matrix[0].size();
        int count = 0;
        for (int i = 0; i < matrix.size(); i++) {
            if (count == total) {
                break;
            }
            for (int j = i; j < matrix[0].size() - i; j++) {
                v.push_back(matrix[i][j]);
                count++;
            }
            if (count == total) {
                break;
            }
            for (int k = i + 1; k < matrix.size() - i; k++) {
                v.push_back(matrix[k][matrix[0].size() - 1 - i]);
                count++;
            }
            if (count == total) {
                break;
            }
            for (int l = matrix[0].size() - i - 2; l >= i; l--) {
                v.push_back(matrix[matrix.size() - i - 1][l]);
                count++;
            }
            if (count == total) {
                break;
            }
            for (int m = matrix.size() - i - 2; m > i; m--) {
                v.push_back(matrix[m][i]);
                count++;
            }
            if (count == total) {
                break;
            }
        }
        return v;
    }
};