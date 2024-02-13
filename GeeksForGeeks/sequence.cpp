// https://www.geeksforgeeks.org/problems/recursive-sequence1611/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        int val = 1;
        const long long M = 1e9 + 7;
        long long totalSum = 0;
        for(int i = 1; i <= n; i++) {
            int termSum = 1;
            for(int j = 1; j <= i; j++) {
                termSum = (termSum % M * val % M);
                val++;
            }
            totalSum = (totalSum % M + termSum % M);
        }
        return totalSum % M;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends