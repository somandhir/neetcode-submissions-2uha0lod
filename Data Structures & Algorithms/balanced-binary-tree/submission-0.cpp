/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        bool flag = false;
        auto len = [&](auto&&self,TreeNode*root){
            if(!root) return 0;
            int leftSubtreeLen = self(self,root->left);
            int rightSubtreeLen = self(self,root->right);
            if(abs(leftSubtreeLen-rightSubtreeLen)>1) flag = true;
            return 1+max(leftSubtreeLen,rightSubtreeLen);
        };
        int leftLen = len(len,root->left);
        int rightLen = len(len,root->right);
        if(abs(leftLen-rightLen)>1) return false;
        if(flag) return false;
        return true;
    }
};
