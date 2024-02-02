// https://www.geeksforgeeks.org/problems/implement-atoi/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        bool isNegative = false;
        if(s[0] - '-' == 0) isNegative = true;
        int num = 0;
        int i = 0;
        if (isNegative) i = 1;
        while(i < s.length()) {
            if(s[i] - '0' < 0 || s[i] - '0' > 9) return -1;
            num = num*10 + (s[i] - '0');
            i++;
        }
        
        if(isNegative) return num*=-1;
        
        return num;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends