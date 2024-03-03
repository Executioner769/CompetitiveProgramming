// https://leetcode.com/contest/weekly-contest-387/problems/distribute-elements-into-two-arrays-i/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            if(arr1[arr1.size() - 1] > arr2[arr2.size() - 1]) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        int k = 0;
        for(int i = 0; i < arr1.size(); i++) {
            nums[k] = arr1[i];
            k++;
        }
        for(int i = 0; i < arr2.size(); i++) {
            nums[k] = arr2[i];
            k++;
        }
        return nums;
    }
};