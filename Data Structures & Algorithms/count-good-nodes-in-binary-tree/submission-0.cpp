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
    int dfs(TreeNode*root,int currMax){
        if(!root) return 0;
        int ans = 1;
        if(currMax>root->val)ans = 0;
        ans+=dfs(root->left,max(currMax,root->val))+dfs(root->right,max(currMax,root->val));
        return ans;
    }
    int goodNodes(TreeNode* root) {
        int cnt = dfs(root,root->val);
        return cnt;
    }
};
