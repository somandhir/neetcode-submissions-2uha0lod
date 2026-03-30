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
    bool check(TreeNode* root, TreeNode* subRoot){
        if(!subRoot and !root) return true;
        if(!subRoot or !root) return false;
        if(root->val!=subRoot->val) return false;

        if(check(root->left,subRoot->left) and check(root->right,subRoot->right)){
            return true;
        }
        return false;
    };
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val==subRoot->val){
            if(check(root,subRoot)) return true;
        }
        return (isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot));
    }
};
