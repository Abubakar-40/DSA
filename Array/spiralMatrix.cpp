//LeetCode: https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int r = matrix.size();
        int c = matrix[0].size();
        int total = r * c;
        int count = 0;
        for (int i = 0; i < r; i++) {
            if (count == total) {
                break;
            }
            for (int j = i; j < c - i; j++) {
                v.push_back(matrix[i][j]);
                count++;
            }
            if (count == total) {
                break;
            }
            for (int k = i + 1; k < r - i; k++) {
                v.push_back(matrix[k][c - 1 - i]);
                count++;
            }
            if (count == total) {
                break;
            }
            for (int l = c - i - 2; l >= i; l--) {
                v.push_back(matrix[r - i - 1][l]);
                count++;
            }
            if (count == total) {
                break;
            }
            for (int m = r - i - 2; m > i; m--) {
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