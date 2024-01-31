// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // vector<int> answer(t.size(), 0);
        // Brute Force: O(N^2) Time Limit Exceeded
        // for(int i = 0 ; i < t.size(); i++) {
        //     int k = i;
        //     while(k < t.size() && t[k] <= t[i]) {
        //         answer[i]++;
        //         k++;
        //     }
        //     if(k >= t.size()) answer[i] = 0;
        // }

        // Sapce Complexity: O(N)
        // Time Complexity: O(N)
        stack<int> st;
        int i = 0;
        st.push(0);
        for(int i = 1; i < t.size(); i++) {
            if(t[st.top()] >= t[i]) st.push(i);
            else {
                while(!st.empty() && t[st.top()] < t[i]) {
                    answer[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()) {
            answer[st.top()] = 0;
            st.pop();
        }
        return answer;


        // Sapce Complexity: O(100)
        // Time Complexity: O(N*100)
        // int n = t.size();
        // vector<int> days(101, 0), ans(n, 0);
        // for(int i=n-1; i>=0; i--){
        //     int cur = t[i];
        //     fill(days.begin(), days.begin()+cur, i);
        //     if(days[cur] != 0) ans[i] = days[cur]-i;
        // }
        // return ans;
    }
};