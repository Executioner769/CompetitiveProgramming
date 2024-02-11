// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/

// https://leetcode.com/contest/weekly-contest-384/problems/number-of-subarrays-that-match-a-pattern-i/

// Brute Force Algorithm

class Solution {
private:
    bool checkPattern(vector<int>& nums,vector<int>& pattern,int i, int m) {
        for(int t = 0; t < m; t++) {
            switch(pattern[t]) {
                case 1: {
                    if(nums[i + t + 1] <= nums[i + t]) return false;
                    break;
                } case 0: {
                    if(nums[i + t + 1] != nums[i + t]) return false;
                    break;
                } case -1: {
                    if(nums[i + t + 1] >= nums[i + t]) return false;
                    break;                    
                }
            }
        }
        return true;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;
        for(int i = 0; i + m < n; i++) {
            if(checkPattern(nums,pattern,i,m)) count++;
        }
        return count;
    }
};