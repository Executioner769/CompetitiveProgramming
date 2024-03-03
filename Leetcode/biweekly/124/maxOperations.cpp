// https://leetcode.com/contest/biweekly-contest-124/problems/maximum-number-of-operations-with-the-same-score-i/

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sum = nums[0] + nums[1];
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i+=2) {
            if(nums[i] + nums[i+1] == sum) ans++;
            else break;
        }
        return ans;
    }
};