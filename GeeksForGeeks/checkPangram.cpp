//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        unordered_set<int> alphabets;
        
        for(int i =0; i < 26; i++) alphabets.insert(i);
        
        for(int i = 0; i < s.length(); i++) {
            if(!s[i]) continue;
            else alphabets.erase(tolower(s[i]) - 'a');
            if(alphabets.empty()) break;
        }
        
        return alphabets.empty();
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends