// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]


class Solution {
private:
    void result(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int id){
        ans.push_back(ds);
        for(int i=id; i<nums.size(); i++){
            if(i > id && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            result(nums, ans, ds, i+1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates
        result(nums, ans, ds, 0);
        return ans;
    }
};
