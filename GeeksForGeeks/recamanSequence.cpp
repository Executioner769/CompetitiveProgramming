// https://www.geeksforgeeks.org/problems/recamans-sequence4856/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> seq(n,0);
        unordered_set<int> st;
        st.insert(seq[0]);
        for(int i = 1; i < n; i++) {
            if(seq[i-1] - i > 0 && st.find(seq[i-1] - i) == st.end()) seq[i] = seq[i-1] - i;
            else seq[i] = seq[i-1] + i;
            st.insert(seq[i]);
        }
        return seq;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends