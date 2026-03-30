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
    bool isValidBST(TreeNode* root) {
        auto helper = [](auto&&self,TreeNode*root,int minVal,int maxVal){
            // 1 node, 2 , true
            cout<<"h\n";
            if(!root) return true;
            if(!(root->val>minVal and root->val<maxVal)) return false;
            cout<<"gotHeere\n";
            if((!self(self,root->left,minVal,root->val)) or (!self(self,root->right,root->val,maxVal))) return false;
            return true;
        };
        bool checkLeft = helper(helper,root->left,INT_MIN,root->val);
        if(!checkLeft) return false;
        bool checkRight = helper(helper,root->right,root->val,INT_MAX);
        if(!checkRight) return false;

        return true;
    }
};
