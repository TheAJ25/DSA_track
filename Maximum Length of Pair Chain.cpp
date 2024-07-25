// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

 

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].
// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

// Constraints:

// n == pairs.length
// 1 <= n <= 1000
// -1000 <= lefti < righti <= 1000






class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<vector<int>>& nums, int cur_idx, int prev_idx){

        if(dp[cur_idx][prev_idx+1] != -1){
            return dp[cur_idx][prev_idx+1];
        }

        if(cur_idx>=n){
            return 0;
        }
        int skip = solve(nums, cur_idx+1, prev_idx);
        int take = 0;
        if(prev_idx == -1 || nums[prev_idx][1]<nums[cur_idx][0]){
            take = 1 + solve(nums, cur_idx+1, cur_idx);
        }
        return dp[cur_idx][prev_idx+1] = max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(dp, -1, sizeof(dp));
        return solve(pairs, 0, -1);
    }
};
