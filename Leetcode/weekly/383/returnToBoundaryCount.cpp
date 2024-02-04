// https://leetcode.com/problems/ant-on-the-boundary/description/

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size();
        int onBoundary = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum == 0) onBoundary++;
        }
        return onBoundary;
    }
};