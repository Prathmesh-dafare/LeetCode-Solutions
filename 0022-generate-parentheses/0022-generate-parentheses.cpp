class Solution {
public:

    void generate(int open, int close, string curr, vector<string>& ans) {

        // Valid combination formed
        if (open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }

        // Add opening bracket
        if (open > 0) {
            generate(open - 1, close, curr + "(", ans);
        }

        // Add closing bracket
        if (close > open) {
            generate(open, close - 1, curr + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        generate(n, n, "", ans);

        return ans;
    }
};