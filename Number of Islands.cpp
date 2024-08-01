// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3




class Solution {
private:
    void dfs(vector<vector<char>>& grid, int row, int col, int i, int j){
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] == '0'){
            return ;
        }
        grid[i][j] = '0';
        dfs(grid, row, col, i-1, j);
        dfs(grid, row, col, i+1, j);
        dfs(grid, row, col, i, j-1);
        dfs(grid, row, col, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();

        int count = 0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, row, col, i, j);
                    count ++;
                }
            }
        }
        return count;
    }
};
