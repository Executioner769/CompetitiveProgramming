// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26,0);
        for(auto ch: s) mp[ch - 'a']++;
        int index = -1;
        for(int i = 0; i < s.length(); i++) {
            if(mp[s[i] - 'a'] == 1) return i;
        }
        return index;
    }
};