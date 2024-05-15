// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3








class Solution {

private:
    int solve(vector<int>& nums, int i, int n, int dp[]) {
        if (i > n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int steal = nums[i] + solve(nums, i + 2, n, dp);
        int skip = solve(nums, i + 1, n, dp);
        dp[i] = max(steal, skip);
        return dp[i];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return max(nums[0], nums[1]);
        }

        int dp[101];
        memset(dp, -1, sizeof(dp));
        // taking 0th index to n-2 index
        int take_0th_idx_house = solve(nums, 0, n-2, dp); 
        //taking 1st index to n-2 index
        memset(dp, -1, sizeof(dp));
        int take_1st_idx_house = solve(nums, 1, n-1, dp); 

        return max(take_0th_idx_house, take_1st_idx_house);
    }
};
