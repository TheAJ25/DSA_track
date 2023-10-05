// Given a binary tree, determine if it is 
// height-balanced
// .

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true





class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return 1;
        }
        int height = 0;
        return dfs(root, height);
    }
private:
    bool dfs(TreeNode* &root, int &height){
        if(root == NULL){
            height = -1;
            return true;
        }

        int left = 0;
        int right = 0;

        if(!dfs(root->left, left) || !dfs(root->right, right)){
            return false;
        }
        if(abs(left-right)>1){
            return false;
        }

        height = 1+max(left, right);
        return true;
    }
};
