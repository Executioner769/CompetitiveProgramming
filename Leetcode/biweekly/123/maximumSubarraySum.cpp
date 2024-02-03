// https://leetcode.com/contest/biweekly-contest-123/problems/maximum-good-subarray-sum/

class Solution {
private: 
    long long getSum(int i1, int i2, vector<long long> &prefix) {
        // We have to make sure that  i1 < i2         
        long long leftSum = 0;
        if(i1 > 0) leftSum = prefix[i1 - 1];
        long long rightSum = prefix[i2];
        return rightSum - leftSum;
    }
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        vector<long long> prefix(nums.size(),0);
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum+=nums[i];
            prefix[i] = sum;
        }
        
        bool isMaxSumNull = true;
        long long max_sum;
        unordered_map<int,vector<int>> mp;
        
        
        // My Optimal Solution That got TLE 
        
        // for(int i = 0; i < nums.size(); i++) {
        //     if(mp.find(nums[i]) != mp.end()) {
        //         for(int i2 = 0; i2 < mp[nums[i]].size(); i2++) {
        //             int idx = mp[nums[i]][i2];
        //             // cout<<idx<<","<<i<<endl;
        //             if(isMaxSumNull) max_sum = getSum(idx,i,prefix); isMaxSumNull = false;
        //             max_sum = max(max_sum, getSum(idx,i,prefix));
        //             // cout<<max_sum<<endl;
        //         }
        //     } 
        //     mp[nums[i] - k].push_back(i);
        //     mp[nums[i] + k].push_back(i);
        // }
        
        // Optimal Solution That got Accepted 
        
        for(int i = 0 ; i < nums.size(); i++) {
            
            if(mp.find(nums[i] - k) != mp.end()) {
                for(auto idx: mp[nums[i] - k]) {
                    if(isMaxSumNull) max_sum = getSum(idx,i,prefix); isMaxSumNull = false;
                    max_sum = max(max_sum, getSum(idx,i,prefix));
                }
            }
            
            if(mp.find(nums[i] + k) != mp.end()) {
                for(auto idx: mp[nums[i] + k]) {
                    if(isMaxSumNull) max_sum = getSum(idx,i,prefix); isMaxSumNull = false;
                    max_sum = max(max_sum, getSum(idx,i,prefix));
                }
            }

            mp[nums[i]].push_back(i);
        }
        

//         Brute Force got TLE
        
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i + 1; j < nums.size(); j++) {
        //         if(abs(nums[i] - nums[j]) == k) {
        //             // cout<<i<<","<<j<<endl;
        //             if(isMaxSumNull) max_sum = getSum(i,j,prefix); isMaxSumNull = false;
        //             max_sum = max(max_sum, getSum(i,j,prefix));
        //             // cout<<max_sum;
        //         }
        //     }
        // }
        if(isMaxSumNull) max_sum = 0;
        return max_sum;
    }
};


// Best Solution
class Solution {    
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long max_sum = LONG_MIN;
        unordered_map<int,long long> mp;
        
        long long sum = 0;
        
        for(int i = 0 ; i < nums.size(); i++) {
            int cond1 = nums[i] - k;
            int cond2 = nums[i] + k;
            
            sum += nums[i];
            
            if(mp.find(cond1) != mp.end()) {
                max_sum = max(max_sum, sum - mp[cond1]);
            }
            
            if(mp.find(cond2) != mp.end()) {
                max_sum = max(max_sum, sum - mp[cond2]);
            }
            
            if(mp.find(nums[i]) != mp.end()) {
                mp[nums[i]] = min(mp[nums[i]], sum - nums[i]);
            } else {
                mp[nums[i]] = sum - nums[i];
            }
            
        }
        
        return max_sum == LONG_MIN ? 0 : max_sum;
    }
};