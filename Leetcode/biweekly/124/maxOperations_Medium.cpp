
// https://leetcode.com/contest/biweekly-contest-124/problems/maximum-number-of-operations-with-the-same-score-ii/

class Solution {
private:
    int dfs(vector<int>& nums,int i, int j, int sum, vector<vector<int>>& dp) {
        if(j - i + 1 < 2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int v1 = 0,v2 = 0,v3 = 0;
        if((nums[i] + nums[i+1]) == sum) {
            v1 = 1 + dfs(nums,i+2,j,sum);
        }
        if((nums[i] + nums[j]) == sum) {
            v2 = 1 + dfs(nums,i+1,j-1,sum);
        }
        if((nums[j-1] + nums[j]) == sum) {
            v3 = 1 + dfs(nums,i,j-2,sum);
        }
        return dp[i][j] = max({v1,v2,v3});
    }
public:
    int maxOperations(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        
        vector<vector<int>> dp(j+1, vector<int>(j+1,-1));
        
        int sum1 = nums[i] + nums[i+1];
        int sum2 = nums[i] + nums[j];
        int sum3 = nums[j-1] + nums[j];
        
        int v1 = dfs(nums,i,j,sum1,dp);
        int v2 = dfs(nums,i,j,sum2,dp);
        int v3 = dfs(nums,i,j,sum3,dp);        

        return max({v1,v2,v3});
    }
};