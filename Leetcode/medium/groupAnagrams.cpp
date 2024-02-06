// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        unordered_map<string,vector<string>> hash;

        int len = strs.size();
        for(int i = 0; i < len; i++) {
            string st = strs[i];
            sort(st.begin(),st.end());
            hash[st].push_back(strs[i]);
        }

        for(auto iter = hash.begin(); iter != hash.end(); iter++) {
            result.push_back(iter->second);
        }

        return result;
    }
};