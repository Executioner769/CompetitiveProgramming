// https://leetcode.com/contest/biweekly-contest-125/problems/minimum-operations-to-exceed-threshold-value-ii/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long , vector<long long>, greater<long long>> pq(nums.begin(),nums.end());
        int operations = 0;
        while(pq.top() < k && pq.size() >= 2) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long z = min(x,y) * 2 + max(x,y);
            pq.push(z);
            operations++;
        }
        return operations;
    }
};