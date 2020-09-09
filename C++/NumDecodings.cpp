//Ian Hays
//08-03-2020
//https://leetcode.com/problems/decode-ways/
//SC: O(N) TC: O(N)

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        
        vector<int> dp(s.length()+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= s.length(); i++){
            if(s[i-1] != '0'){
                dp[i] += dp[i-1];
            }
            if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7'){
                dp[i] += dp[i-2];
            }
        }
        
        return dp[s.length()];
    }
};
