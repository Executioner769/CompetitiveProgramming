// https://leetcode.com/contest/weekly-contest-385/problems/most-frequent-prime/

class Solution {
private:
    void genrate(vector<vector<int>>& mat,int m,int n,int in, int jn, unordered_map<int,int>& mp ) {
        // North
        int i = in, j = jn;
        int num = 0;
        while(i >= 0) {
            num = num * 10 + mat[i--][j];
            if(num > 10) mp[num]++;
        }
        // North-East
        i = in; j = jn;
        num = 0;
        while( i >= 0 && j <= n - 1) {
            num = num * 10 + mat[i--][j++];
            if(num > 10) mp[num]++;
        }
        // East 
        i = in; j = jn;
        num = 0;
        while(j <= n-1) {
            num = num * 10 + mat[i][j++];
            if(num > 10) mp[num]++;
        }
        // South-East
        i = in; j = jn;
        num = 0;
        while(i <= m-1 && j <= n-1) {
            num = num * 10 + mat[i++][j++];
            if(num > 10) mp[num]++;            
        }
        // South
        i = in; j = jn;
        num = 0;
        while(i <= m-1) {
            num = num * 10 + mat[i++][j];
            if(num > 10) mp[num]++;            
        }
        // South - West
        i = in; j = jn;
        num = 0;
        while(i <= m-1 && j >= 0) {
            num = num * 10 + mat[i++][j--];
            if(num > 10) mp[num]++;            
        }
        // East 
        i = in; j = jn;
        num = 0;
        while(j >= 0) {
            num = num * 10 + mat[i][j--];
            if(num > 10) mp[num]++;
        }
        // North-East
        i = in; j = jn;
        num = 0;
        while(i >= 0 && j >= 0) {
            num = num * 10 + mat[i--][j--];
            if(num > 10) mp[num]++;            
        }
    }
        
    
    static bool comp(pair<int,int> a, pair<int,int> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
    
    bool checkPrime(int number) {
        for(int i = 2; i < number; i++) {
            if(number % i == 0) return false;
        }
        return true;
    }
    
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,int> mp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                genrate(mat,m,n,i,j,mp);
            }
        }
        
        vector<pair<int,int>> vt;
        for(auto iter: mp) {
            vt.push_back({iter.second,iter.first});
        }
        
        sort(vt.begin(),vt.end(),comp);
        
        int highFreqPrime = -1;
        for(int i = 0; i < vt.size(); i++) {
            // cout<<vt[i].first<<":"<<vt[i].second<<endl;
            if(checkPrime(vt[i].second)) { 
                // cout<<"Prime: "<<vt[i].second<<endl;
                highFreqPrime = vt[i].second;
                break;
            }
        }
        
        return highFreqPrime;
    }
};