// https://leetcode.com/problems/find-the-grid-of-region-average/

class Solution {
private:
    int getRegionAverage(int i, int j,int m,int n, vector<vector<int>>& image, int t) {
        int r1 = i;
        int sum = 0;
        while(r1 < i + 3 && r1 < m) {
            int c1 = j;
            while(c1 < j + 3 && c1 < n) {
                sum+=image[r1][c1];
                
                int leftCell = -1;
                int topCell = -1;
                
                if(c1 > 0 && c1 != j) leftCell = image[r1][c1-1];
                if(r1 > 0 && r1 != i) topCell = image[r1-1][c1];
                
                if(leftCell != -1) {if(abs(image[r1][c1] - leftCell) > t) return -1;}
                if(topCell != -1) {if(abs(image[r1][c1] - topCell) > t) return -1;}
                 
                c1++;
            }
            r1++;
        }
        
        int avg = (sum / 9);
        return avg;
    }
    
    void updateResult(int i, int j,int m,int n, vector<vector<int>>& image, vector<vector<int>>& result,vector<vector<int>>& visitCount, int avg) {
        int r1 = i;
        while(r1 < i + 3 && r1 < m) {
            int c1 = j;
            while(c1 < j + 3 && c1 < n) {
                if(avg == -1 && visitCount[r1][c1] == 0) {
                    result[r1][c1] = image[r1][c1];
                } else if(avg != -1) {
                    if(visitCount[r1][c1] == 0){ 
                        result[r1][c1] = avg;
                    } else {
                        result[r1][c1] += avg;
                    }
                    visitCount[r1][c1]++;
                }
                c1++;
            }
            r1++;
        }
        return;
    }
    
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int t) {
        vector<vector<int>> result;
        vector<vector<int>> visitCount;
        int n = image[0].size();
        int m = image.size();
        
        result.resize(m , vector<int>(n, 0));
        visitCount.resize(m , vector<int>(n, 0));
        for(int i = 0; i <= m-3; i++) {
            for(int j = 0; j <= n-3; j++) {
                int average = getRegionAverage(i,j,m,n,image,t);
                updateResult(i,j,m,n,image,result,visitCount,average);
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visitCount[i][j] != 0) result[i][j] /= visitCount[i][j];
            }
        }
        
        return result;
    }
};