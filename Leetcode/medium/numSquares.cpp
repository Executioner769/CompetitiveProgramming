// https://leetcode.com/problems/perfect-squares/

class Solution {
private:
    int minSoFar;
    void findMinSquares(int n, int min, vector<int>& vt) {
        if(n < 0) return ;
        if(minSoFar <= min) return;
        if(n == 0) {
            minSoFar = (min < minSoFar ? min : minSoFar); 
            return;
        }
        
        for(int i = 0; i < vt.size(); i++) {
            findMinSquares(n-vt[i],min+1,vt);
        }
        return;
    }
public:
    int numSquares(int n) {
        vector<int> sq;
        minSoFar = n;
        int sum = 1;
        for(int i = 3; sum <= n; i+=2) {
            sq.push_back(sum);
            sum+=i;
        }
        sort(sq.begin(),sq.end(),greater<int>());

        findMinSquares(n,0,sq);
        return minSoFar;
    }
};