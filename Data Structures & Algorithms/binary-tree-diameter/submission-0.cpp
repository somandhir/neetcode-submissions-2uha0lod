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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int mxConstant = 0;
        auto maxDepth = [&](auto&&self,TreeNode* root){
            if(!root) return 0;
            int leftLen = self(self,root->left);
            int rightLen = self(self,root->right);
            mxConstant = max(mxConstant,1+leftLen+rightLen);
            return 1+max(leftLen,rightLen);
        };
        int leftMax =  maxDepth(maxDepth,root->left);
        int rightMax = maxDepth(maxDepth,root->right);
        return max(mxConstant,1+leftMax+rightMax) - 1;
    }
};
