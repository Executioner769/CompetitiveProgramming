// https://leetcode.com/contest/weekly-contest-385/problems/count-prefix-and-suffix-pairs-i/

// Brute Force 

class Solution {
private:
    bool isPrefixAndSuffix(string str1, string str2) {
        if(str1.length() > str2.length()) return false;
        string prefix = str2.substr(0,str1.length());
        string suffix = str2.substr(str2.length() - str1.length(), str2.length());
        return (str1 == prefix && str1 == suffix);
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if(isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};


// https://leetcode.com/contest/weekly-contest-385/problems/count-prefix-and-suffix-pairs-ii/



