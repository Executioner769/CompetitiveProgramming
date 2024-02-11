// https://leetcode.com/problems/modify-the-matrix/
// https://leetcode.com/contest/weekly-contest-384/problems/modify-the-matrix/

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        for(int j = 0; j < n; j++) {
            int maxVal = -1;
            for(int i = 0; i < m; i++) {
                if(matrix[i][j] == -1) continue;
                maxVal = max(maxVal , matrix[i][j]);
            }
            
            for(int i = 0; i < m; i++) {
                if(matrix[i][j] == -1) matrix[i][j] = maxVal;
            }
        }
        return matrix;
    }
};

