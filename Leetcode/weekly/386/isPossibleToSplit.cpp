// https://leetcode.com/contest/weekly-contest-386/problems/split-the-array/

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 2) return false;
        }
        return true;
    }
};