//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1


class Solution{
    private:
    
    int count(string &s, int index, int prevsum, vector<vector<int>> &dp) {
        
        if(index == s.length()) return 1;
        
        if(dp[index][prevsum] != -1) return dp[index][prevsum];
        
        int currsum = 0;
        int answer = 0;
        
        for(int i = index; i < s.length(); i++) {
            currsum += (s[i] - '0');
            if(currsum >= prevsum) {
                answer += count(s,i+1,currsum,dp);
            }
        }
        return dp[index][prevsum] = answer;
    }
    
	public:
	int TotalCount(string str){
	   vector<vector<int>> dp;
	   int n = str.length();
	   dp.resize(n,vector<int>(9*n,-1));
	   return count(str,0,0,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends