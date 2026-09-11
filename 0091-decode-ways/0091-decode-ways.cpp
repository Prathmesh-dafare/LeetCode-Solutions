class Solution {
public:
    int numDecodings(string s) {

        int n = s.length();

        // If string starts with 0, invalid
        if (s[0] == '0')
            return 0;

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {

            // Single digit decode
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Two digit decode
            int twoDigit = stoi(s.substr(i - 2, 2));

            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};