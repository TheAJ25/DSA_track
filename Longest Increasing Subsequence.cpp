// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104






class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(vector<int>& nums, int cur_idx, int prev_idx){

        if(dp[cur_idx][prev_idx+1] != -1){
            return dp[cur_idx][prev_idx+1];
        }

        if(cur_idx>=n){
            return 0;
        }
        int skip = solve(nums, cur_idx+1, prev_idx);
        int take = 0;
        if(prev_idx == -1 || nums[prev_idx]<nums[cur_idx]){
            take = 1 + solve(nums, cur_idx+1, cur_idx);
        }
        return dp[cur_idx][prev_idx+1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);

    }
};
