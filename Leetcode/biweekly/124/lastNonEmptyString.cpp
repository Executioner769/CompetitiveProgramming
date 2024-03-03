// https://leetcode.com/contest/biweekly-contest-124/problems/apply-operations-to-make-string-empty/

class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.length();
        
        // Count the Fequencies of the character
        unordered_map<char,int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        
        // Get Max Frequency
        int maxFreq = -1;
        for(auto iter: mp) {
            maxFreq = max(maxFreq,iter.second);
        }
        
        // Get all the characters with maxFrequency and store them in a set
        unordered_set<char> st;
        for(auto iter: mp) {
            if(maxFreq == iter.second) st.insert(iter.first);
        }
        
        string ans;
        
        // Find for first occurence of the charcters in set from the end of the string and append characters to ans "" string;
        for(int i = n-1; i >= 0; i--) {
            if(st.size() == 0) break;
            if(st.find(s[i]) != st.end()) {
                ans+=s[i];
                st.erase(s[i]);
            }
        }
        
        
        // We nee to reverse the ans string to get our answer string
        int i = 0;
        int j = ans.size() - 1;
        while(i < j) {
            char t = ans[i];
            ans[i] = ans[j];
            ans[j] = t;
            i++;
            j--;
        }
        return ans;
    }
};