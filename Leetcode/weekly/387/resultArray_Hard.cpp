
// https://leetcode.com/contest/weekly-contest-387/problems/distribute-elements-into-two-arrays-ii/

// Brute Force TLE

class Solution {
public:
    int greaterCount(vector<int>& nums,int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > k) count++;
        }
        return count;
    }
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        int n = nums.size();
        for(int i = 2; i < n; i++) {
            if(greaterCount(arr1,nums[i]) > greaterCount(arr2,nums[i])) arr1.push_back(nums[i]);
            else if(greaterCount(arr1,nums[i]) < greaterCount(arr2,nums[i])) arr2.push_back(nums[i]);
            else {
                if(arr1.size() <= arr2.size()) arr1.push_back(nums[i]);
                else arr2.push_back(nums[i]);
            }
        }
        
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};