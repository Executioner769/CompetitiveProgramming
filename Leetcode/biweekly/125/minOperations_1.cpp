// https://leetcode.com/contest/biweekly-contest-125/problems/minimum-operations-to-exceed-threshold-value-i/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < k) count++;
        }
        return count;
    }
};