// https://leetcode.com/problems/palindromic-substrings/

// Brute Force Approach 

class Solution {
    public int countSubstrings(String s) {
       int c=0; 
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
               String x = s.substring(i,j+1);
                if(checkPal(x)){ 
                    c++;
                }
            }
        }  
        return c;
    }

    public boolean checkPal(String s){
        StringBuilder sb = new StringBuilder(s);

        String rev = sb.reverse().toString();
        return (rev.equals(s));
    }
}