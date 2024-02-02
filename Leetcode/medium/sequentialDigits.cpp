
// https://leetcode.com/problems/sequential-digits/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        // My Solution

        // vector<string> nums;
        // for(int i = 1; i < 10; i++) {
        //     nums.push_back(to_string(i));
        // }
        // vector<int> answer;
        // string l = to_string(low);
        // string h = to_string(high);
        // int llen = l.length();
        // int hlen = h.length();
        // if(hlen == 10) hlen--;
        // for(int i = llen; i <= hlen; i++) {
        //     for(int j = 0; j <= nums.size() - i; j++) {
        //         string temp = "";
        //         for(int k = j; k < j + i; k++) {
        //             temp+=nums[k];
        //         }
        //         int n = stoi(temp);
        //         if(low <= n && high >= n) answer.push_back(n);
        //     }
        // }
        // return answer;



        // vector<int> nums = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
        // int len = nums.size();
        // vector<int> answer;
        // for(int i = 0; i < len; i++) {
        //     if(nums[i] >= low && nums[i] <= high) answer.push_back(nums[i]);
        // }
        // return answer;


        // vector<int> ans;
        // for (int len = 1; len <= 9; len++) {
        //     for (int i = 0; i + len <= 9; i++) {
        //         int x = stoi(s.substr(i, len));
        //         if (L <= x && x <= R) {
        //             ans.push_back(x);
        //         }
        //         if (x > R) break;
        //     }    
        // }
        // return ans;
    }
};

// Nice Logic

class Solution {
public:
    vector<int>ans;
    void dfs(int low,int high,int i,int num){
        if(num>=low && num<=high){
            ans.push_back(num);
        }
        if(num>high || i>9){
            return ;
        }
        dfs(low,high,i+1,num*10+i);
    }
    vector<int> sequentialDigits(int low, int high) {
      for(int i=1;i<=9;i++){
          dfs(low,high,i,0);
          
      }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
