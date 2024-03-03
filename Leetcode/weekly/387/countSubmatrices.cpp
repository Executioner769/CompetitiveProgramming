// https://leetcode.com/contest/weekly-contest-387/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& nums, int k) {
        int m = nums.size();
        int n = nums[0].size();
        
        for(int r1 = 0; r1 < m; r1++) {
            for(int c1 = 0; c1 < n; c1++) {
                int top = (r1 > 0 ? nums[r1-1][c1]: 0);
                int left = (c1 > 0? nums[r1][c1-1]: 0);
                int top_left = (min(r1,c1) > 0 ? nums[r1-1][c1-1]: 0);
                
                nums[r1][c1] += top + left - top_left;
            }
        }
        int count = 0;
        for(int r1 = 0; r1 < m; r1++) {
            for(int c1 = 0; c1 < n; c1++) {
                // cout<<nums[r1][c1]<<" ";
                if(nums[r1][c1] <= k) count++;
            }
            // cout<<endl;
        }
        return count;
    }
};