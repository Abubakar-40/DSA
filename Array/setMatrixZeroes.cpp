//LeetCode: https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = -99999;
                }
            }
        }
        
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == -99999) {
                    matrix[i][j]=0;
                    for (size_t k = 0; k < matrix[0].size(); k++) {
                        if (k == 0) {
                            matrix[i][0] = 0;
                        } else if (matrix[i][k] != -99999) {
                            matrix[i][k] = 0;
                        }
                    }
                    for (size_t l = 0; l < matrix.size(); l++) {
                        if (l == 0)
                    {
                        matrix[0][j] = 0;
                    }
                        else if (matrix[l][j] != -99999) {
                            matrix[l][j] = 0;
                        }
                    }
                }
            }
        }
    }
};