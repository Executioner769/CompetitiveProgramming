// https://leetcode.com/contest/weekly-contest-387/problems/minimum-operations-to-write-the-letter-y-on-a-grid/

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        unordered_map<int,int> outOfY;
        unordered_map<int,int> onTheY;
        int n = grid.size();
        int mid = (n-1)/2;
        for(int r = 0; r < n;r++) {
            for(int c = 0; c < n; c++) {
                if(r <= mid) {
                    if( r == c || n - r - 1 == c) onTheY[grid[r][c]]++;
                    else outOfY[grid[r][c]]++;
                }
                else {
                    if(c == mid) onTheY[grid[r][c]]++;
                    else outOfY[grid[r][c]]++;
                }
            }
        }
        
        int ops = n * n;
        for(int i = 0;i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                ops = min(ops,n * n - onTheY[i] - outOfY[j]);
            }
        }
        return ops;
    }
};