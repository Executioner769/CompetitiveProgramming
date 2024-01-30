// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
private:
    int performOperation(int n1, int n2, int op) {
        int ans = 0;
        switch(op) {
            case 1: {ans = n1 + n2; break;}
            case 2: {ans = n1 - n2; break;}
            case 3: {ans = n1 * n2; break;}
            case 4: {ans = n1 / n2; break;}
        }
        return ans;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string,int> operators {{"+",1},{"-",2},{"*",3},{"/",4}};
        for(auto token: tokens) {
            if(operators.find(token) != operators.end()) {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(performOperation(n1,n2,operators[token]));
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};