// https://leetcode.com/contest/biweekly-contest-123/problems/type-of-triangle-ii/

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int sum = 0;
        string triangleType = "none";
        for(int i = 0; i < 3; i++) {
            sum += nums[i];
        }
        unordered_set<int> st;
        for(int i = 0; i < 3; i++) {
            int twoSum = sum - nums[i];
            if(twoSum <= nums[i]) return triangleType;
            st.insert(nums[i]);
        }
        if(st.size() == 3) triangleType = "scalene";
        else if (st.size() == 2) triangleType = "isosceles";
        else if(st.size() == 1) triangleType = "equilateral";
        
        return triangleType;
    }
};