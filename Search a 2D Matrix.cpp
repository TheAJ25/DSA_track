// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104




If closely analyze the given matrix, we can notice one interesting property (╭ರ_•́): elements on the left are always smaller than the current element, and elements on the bottom are always greater. It reminds us of the Binary Search Tree, doesn't it (๏็ટૄ◟๏็ )? Just look at this matrix from this angle and everything will become clear to you (our target, say, is 11):

imageWoooooow!!! ٩(ˊᗜˋ*)و

Time: O(n) - in the case we have just one row
Space: O(1) - nothing stored

Runtime: 3 ms, faster than 88.01% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.6 MB, less than 52.00% of C++ online submissions for Search a 2D Matrix.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};
