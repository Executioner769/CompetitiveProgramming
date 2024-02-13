class Solution {
private:
    bool isPalindrom(string word) {
        int i = 0;
        int j = word.length() - 1;
        while(i < j) {
            if(word[i] != word[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string word: words) {
            if(isPalindrom(word)) return word;
        }
        return "";
    }
};