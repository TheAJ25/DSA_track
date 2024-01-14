// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

// Example 1:


// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]
// Example 2:

// Input: root = [1,null,3]
// Output: [1,3]
// Example 3:

// Input: root = []
// Output: []





class Solution {
private:
    void recursion(TreeNode* &root, int level, vector<int> &res){
        if(root == NULL){
            return;
        }
        else if(res.size() == level){
            res.push_back(root->val);
        }
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
