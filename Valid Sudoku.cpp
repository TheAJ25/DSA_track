// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 

// Example 1:


// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit 1-9 or '.'.









solution:


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        //Using hashset

        unordered_set<string> s;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char number = board[i][j];
                if(number != '.'){
                    string rowStr = "row" + to_string(i) + number;
                    string colStr = "col" + to_string(j) + number;
                    string boxStr = "box" + to_string((i/3)*3+(j/3)) + number;
                    if(!s.insert(rowStr).second || !s.insert(colStr).second || !s.insert(boxStr).second){
                        return false;
                    }
                }
            }
        }
        return true;


        // Using Hashmaps

        // unordered_map<char, int> rows[9], cols[9], boxes[3][3];

        // for(int i = 0; i < 9; i++){
        //     for(int j = 0; j < 9; j++){
        //         char number = board[i][j];
        //         if(number != '.'){
        //             if(rows[i].count(number) || cols[j].count(number) || boxes[i/3][j/3].count(number))
        //                 return false;
                    
        //             rows[i][number] = 1;
        //             cols[j][number] = 1;
        //             boxes[i/3][j/3][number] = 1;
        //         }
        //     }
        // }
        // return true;
    }
};
