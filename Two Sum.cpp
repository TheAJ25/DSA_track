// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]




class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {
        vector<pair<int, int>> nums;
        for(int i=0; i<vec.size(); i++){
            nums.push_back({vec[i], i});
        }

        sort(nums.begin(), nums.end());

        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum = nums[i].first + nums[j].first;
            if(sum == target){
                return {nums[i].second , nums[j].second};
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {};
    }
};
