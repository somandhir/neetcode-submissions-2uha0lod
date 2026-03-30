class Solution {
public:
        map<TreeNode*,int>mp;
    int kthSmallest(TreeNode* root, int k) {
        auto helper = [&](auto&&self,TreeNode*root){
            if(!root) return 0;
            if(mp.count(root)) return mp[root];
            int cntLeftSubtree = self(self,root->left);
            int cntRightSubtree = self(self,root->right);
            return mp[root] =  (cntLeftSubtree+cntRightSubtree+1);
        };  
        int leftCount = helper(helper,root->left);
        if(k<=leftCount) return kthSmallest(root->left,k);
        else if(k==(leftCount+1)) return root->val;
        else return kthSmallest(root->right,k-(leftCount+1));
    }
};
