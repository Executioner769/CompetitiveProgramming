// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// 28-01-2024

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int rowVal = (i > 0 ?  matrix[i-1][j]: 0); // Top Row Sum
                int colVal = (j > 0 ?  matrix[i][j-1]: 0); // Left Col Sum
                int rowcolVal = (min(i,j) > 0 ? matrix[i-1][j-1]: 0); //Top Row and Left Col Sum
                matrix[i][j] = matrix[i][j] + rowVal + colVal - rowcolVal;
            }
        }

        // O(N^M)

        int count = 0;
        for(int r1 = 0; r1 < rows; r1++) {
            for(int r2 = r1; r2 < rows; r2++) {
                unordered_map<int,int> hashmap;
                for(int c = 0; c < cols; c++) {
                    int aboveRowSum = (r1 > 0 ? matrix[r1-1][c] : 0);
                    int sum = matrix[r2][c] - aboveRowSum;
                    int diff = sum-target;
                    if(sum == target) count++;
                    if(hashmap.find(diff) != hashmap.end()) count+= hashmap[diff];
                    hashmap[sum]++;
                }
            }
        }

        // Time Complexity:  O(N^2 X M)
        // Space Complexity: O(M)

        return count;
    }
};