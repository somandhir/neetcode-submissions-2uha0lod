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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> res;
        while(q.size()){
            int n = q.size();
            vector<int>v;
            for(int _=0;_<n;_++){
                auto curr = q.front();q.pop();
                v.push_back(curr->val);
                auto left = curr->left;
                auto right = curr->right;
                if(left) q.push(left);
                if(right) q.push(right);   
            }      
            res.push_back(v);      
        }
        return res;
    }
};
