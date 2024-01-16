// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8







class Solution {
private:
    void generate(vector<string> &res, string current, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(current);
            return;
        }

        if (open > 0) {
            generate(res, current + '(', open - 1, close);
        }

        if (close > 0 && close > open) {
            generate(res, current + ')', open, close - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", n, n);
        return res;
    }
};
