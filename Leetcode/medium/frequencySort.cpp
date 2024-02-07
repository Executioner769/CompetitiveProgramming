class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        vector<pair<int,char>> list;

        // Store the Frequency of Each Char in String s
        for(auto ch: s) mp[ch]++;
        
        // Store {freq,char} pair in a Vector
        for(auto iter: mp) {
            pair<int,char> pr = make_pair(iter.second,iter.first);
            list.push_back(pr);
        }

        // Sort the Vector in descinding order
        sort(list.begin(),list.end(), greater<pair<int,char>>());

        string res = "";

        // Generate the String res 
        for(int i = 0; i < list.size(); i++) {
            int charCount = list[i].first;
            for(int j = charCount; j > 0; j--) {
                res += list[i].second;
            }
        }

        return res;
    }
};